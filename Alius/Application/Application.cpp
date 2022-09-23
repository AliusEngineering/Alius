#include "Application.hpp"

#include "Events/EventBus.hpp"

#include "Core/AliusCore.hpp"

namespace Alius {

Ref<Renderer> Application::s_Renderer{};
Ref<Window> Application::s_Window{};

Application::Application(int width, int height, const char* windowTitle)
  : m_LayerStack()
{
  SQD::Logger::EnableLogger();

  SQD_LOG("Available Renderer modules: ");
  for (const auto& [id, functor] : Alius::Renderer::s_RendererModules) {
	SQD_LOG("\t{}", id);
  }

  ALS_LOAD_CORE_MODULE(Alius::Renderer::s_RendererModules,
                       "AlsVkRenderer",
                       s_Renderer,
                       width,
                       height,
                       windowTitle)

  s_Window = s_Renderer->GetWindow();
}

Application::~Application()
{
  m_LayerStack.Shutdown();
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
