#pragma once

#include "Core/AliusCore.hpp"

// GLFW forward declarations
struct GLFWwindow;

namespace Alius {

class Window
{
public:
  Window() = default;
  Window(int width, int height, const char* windowTitle);
  ~Window();

  bool ShouldClose() const;

  void OnUpdate();

private:
  void SetupGlfwEvents();

private:
  GLFWwindow* m_GlfwWindow;
};

} // namespace Alius
