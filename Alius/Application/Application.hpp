#pragma once

namespace Alius {

class Window;

class Application {
public:
  Application(int width, int height, const char *windowTitle);

  bool IsRunning() { return !s_Window->ShouldClose(); }
  void OnUpdate();

  static Ref<Window> GetWindow() { return s_Window; }

private:
  inline static Ref<Window> s_Window{};
};

} // namespace Alius
