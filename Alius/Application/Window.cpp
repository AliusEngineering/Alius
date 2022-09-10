#include "Window.hpp"

#include "GLFW/glfw3.h"

#include "Events/EventBus.hpp"

namespace Alius {

Window::Window(int width, int height, const char* windowTitle)
{
  glfwInit();
  m_GlfwWindow = glfwCreateWindow(width, height, windowTitle, nullptr, nullptr);
  if (m_GlfwWindow == nullptr) {
	SQD_ERR("Failed to create new window!");
	throw std::runtime_error("Failed to create new window!");
  }

  SetupGlfwEvents();

  ALS_EVENTS_SUBSCRIBE(WindowMinimize, [this](WindowMinimizeEvent& e) {
	// Window inactive
	m_Active = false;
  });

  ALS_EVENTS_SUBSCRIBE(WindowResize, [this](WindowResizeEvent& e) {
	// Window is active again.
	m_Active = true;
  });

  m_Active = true;
}

void
Window::SetupGlfwEvents()
{
  glfwSetWindowSizeCallback(
    m_GlfwWindow, [](GLFWwindow* window, int width, int height) {
	  if (width == 0 || height == 0)
	    EventBus::PushEvent(WindowMinimizeEvent());
	  else
	    EventBus::PushEvent(WindowResizeEvent(window, width, height));
    });

  glfwSetWindowCloseCallback(m_GlfwWindow, [](GLFWwindow* window) {
	EventBus::PushEvent(WindowCloseEvent(window));
  });

  glfwSetKeyCallback(
    m_GlfwWindow,
    [](GLFWwindow* window, int key, int scancode, int action, int mods) {
	  switch (action) {
	    case GLFW_REPEAT:
	    case GLFW_PRESS:
		  EventBus::PushEvent(
		    KeyPressEvent((KeyCodes)key, mods, action == GLFW_REPEAT));
		  break;
	    case GLFW_RELEASE:
		  EventBus::PushEvent(KeyReleaseEvent((KeyCodes)key, mods));
		  break;
	    default:
		  break;
	  }
    });

  glfwSetCursorPosCallback(
    m_GlfwWindow, [](GLFWwindow* window, double xpos, double ypos) {
	  EventBus::PushEvent(MouseMoveEvent({ (float)xpos, (float)ypos }));
    });

  glfwSetMouseButtonCallback(
    m_GlfwWindow, [](GLFWwindow* window, int button, int action, int mods) {
	  switch (action) {
	    case GLFW_PRESS:
		  EventBus::PushEvent(MouseButtonPressEvent((MouseButtons)button));
	    case GLFW_RELEASE:
		  EventBus::PushEvent(MouseButtonReleaseEvent((MouseButtons)button));
	    default:
		  break;
	  }
    });
}

bool
Window::ShouldClose() const
{
  return glfwWindowShouldClose(m_GlfwWindow);
}

bool
Window::IsActive() const
{
  return m_Active;
}

void
Window::OnUpdate()
{
  glfwPollEvents();
}

Window::~Window()
{
  glfwDestroyWindow(m_GlfwWindow);
}

} // namespace Alius