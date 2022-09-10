#include "Application.hpp"

#include "Core/AliusCore.hpp"

namespace Alius {

Application::Application(int width, int height, const char* windowTitle)
{
  SQD::Logger::EnableLogger();
  s_Window = MakeRef<Window>(width, height, windowTitle);
}

Application::~Application()
{
  for (auto layer : m_LayerStack) {
	layer->OnDetach();
	delete layer;
  }
}

void
Application::PushLayer(Layer* layer)
{
  m_LayerStack.PushLayer(layer);
}

void
Application::PushOverlay(Layer* overlay)
{
  m_LayerStack.PushOverlay(overlay);
}

void
Application::OnUpdate()
{
  EventBus::ProcessQueue();
  for (auto layer : m_LayerStack) {
	layer->OnUpdate();
  }

  s_Window->OnUpdate();
}

} // namespace Alius
