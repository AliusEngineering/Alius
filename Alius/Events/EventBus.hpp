#pragma once

#include "Events/Definitions/Event.hpp"

#include "EventPool.hpp"

#include "functional"
#include "unordered_map"
#include "vector"

// !!! TEMPORARY SOLUTION
#define ALS_EVENTS_SUBSCRIBE(type, callback)                                   \
  Alius::EventBus::Subscribe<Alius::EventType::type, Alius::type##Event>(callback)

namespace Alius {

class Application;

class EventBus
{
public:
  template<EventType Type, class E>
  static void Subscribe(std::function<void(E&)> callback)
  {
	AddToCallbackMap<Type, E>(callback);
  };

  template<EventType Type, class E>
  static void AddToCallbackMap(std::function<void(E&)> cb)
  {

	auto callback = std::move(cb);
	s_CallbackMap[Type].emplace_back(
	  [callback](const Ref<Event>& e) { callback(dynamic_cast<E&>(*e)); });
  }

  template<class E>
  static void PushEvent(E event)
  {
	s_EventPool.Push(event);
  }

private:
  static void ProcessQueue()
  {
	for (auto event : s_EventPool) {
	  try {
		auto eventCallbacks = s_CallbackMap.at(event->GetType());
		for (const auto& callback : eventCallbacks) {
		  if (!event->IsCompleted())
			std::invoke(callback, event);
		  else
			break;
		}
	  } catch (std::out_of_range& out_of_range) {
		continue;
	  }
	}

	// Clear event queue
	s_EventPool.clear();
  };

private:
  inline static std::unordered_map<EventType,
                                   std::vector<std::function<void(Ref<Event>)>>>
    s_CallbackMap{};

  inline static EventPool s_EventPool{};

private:
  friend Application;
};

} // Alius