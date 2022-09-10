#include "Application.hpp"

#include "Core/AliusCore.hpp"

#include "Events/EventBus.hpp"

namespace Alius {

Application::Application(int width, int height, const char* windowTitle)
{
  s_Window = MakeRef<Window>(width, height, windowTitle);
}

void
Application::OnUpdate()
{
  // Process events
  EventBus::ProcessQueue();

  // Poll new window events
  s_Window->OnUpdate();
}

} // namespace Alius
