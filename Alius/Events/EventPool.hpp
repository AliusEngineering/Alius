#pragma once

#include "Core/AliusCore.hpp"

#include "Events/Definitions/KeyboardEvents.hpp"
#include "Events/Definitions/MouseEvents.hpp"
#include "Events/Definitions/WindowEvents.hpp"

namespace Alius {

struct EventPool
{
public:
  EventPool() = default;

  template<class E>
  void Push(E event)
  {
	s_EventPool.emplace_back(std::make_shared<E>(event));
  };

  [[nodiscard]] Ref<Event> GetNext()
  {
	// Get event and remove from stack
	auto ret = s_EventPool.back();
	s_EventPool.pop_back();

	return ret;
  };

  std::vector<Ref<Event>>::iterator begin() { return s_EventPool.begin(); }
  std::vector<Ref<Event>>::iterator end() { return s_EventPool.end(); }
  std::vector<Ref<Event>>::const_iterator begin() const
  {
	return s_EventPool.begin();
  }
  std::vector<Ref<Event>>::const_iterator end() const
  {
	return s_EventPool.end();
  }

  void clear() { s_EventPool.clear(); }

private:
  std::vector<Ref<Event>> s_EventPool{};
};

}
