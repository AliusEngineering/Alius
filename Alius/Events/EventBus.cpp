#include "EventBus.hpp"

namespace Alius {

void
EventBus::ProcessQueue()
{
  for (auto& event : s_EventPool) {
	auto eventCallbacks = s_CallbackMap.find(event->GetType());
	if (eventCallbacks == s_CallbackMap.end())
	  continue;

	for (auto& callback : eventCallbacks->second) {
	  if (!event->IsCompleted())
		std::invoke(callback, event);
	  else
		break;
	}
  }

  // Clear event queue
  s_EventPool.clear();
}

} // Alius