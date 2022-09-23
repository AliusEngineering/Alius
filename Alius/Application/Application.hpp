#pragma once

#include "Application/LayerStack.hpp"

// Base state
#include "RendererBase/Renderer.hpp"
#include "WindowBase/Window.hpp"

namespace Alius {

class Application
{
public:
  Application(int width, int height, const char* windowTitle);
  ~Application();

  bool IsRunning() const { return !s_Window->ShouldClose(); }
  bool IsActive() const { return s_Window->IsActive(); }

  void PushLayer(Layer* layer);
  void PushOverlay(Layer* overlay);

  void OnUpdate();

  static Ref<Window> GetWindow() { return s_Window; }
  static Ref<Renderer> GetRenderer() { return s_Renderer; }

private:
  static Ref<Renderer> s_Renderer;
  static Ref<Window> s_Window;

  LayerStack m_LayerStack;

private:
  inline static constexpr const char* c_CoreRendererModule = "AlsVkRenderer";
};

} // namespace Alius
