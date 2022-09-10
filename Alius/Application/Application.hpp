#pragma once

#include "Application/LayerStack.hpp"
#include "Application/Window.hpp"

#include "Events/EventBus.hpp"

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

private:
  inline static Ref<Window> s_Window{};
  LayerStack m_LayerStack;
};

} // namespace Alius
