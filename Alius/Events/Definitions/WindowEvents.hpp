#pragma once

#include "Core/AliusCore.hpp"

#include "Event.hpp"

namespace Alius {

class WindowResizeEvent : public Event
{
public:
  WindowResizeEvent(GLFWwindow* window, uint32_t width, uint32_t height)
    : m_Width(width)
    , m_Height(height)
    , m_Window(window){};

  [[nodiscard]] uint32_t GetWidth() const { return m_Width; };
  [[nodiscard]] uint32_t GetHeight() const { return m_Height; };

  [[nodiscard]] GLFWwindow* GetWindow() const { return m_Window; }

  ALS_EVENT_TYPE(WindowResize);
  ALS_EVENT_CATEGORY(CategoryWindow);

private:
  uint32_t m_Width;
  uint32_t m_Height;

  GLFWwindow* m_Window;
};

class WindowMinimizeEvent : public Event
{
public:
  WindowMinimizeEvent() = default;

  ALS_EVENT_TYPE(WindowMinimize);
  ALS_EVENT_CATEGORY(CategoryWindow);
};

class WindowCloseEvent : public Event
{
public:
  explicit WindowCloseEvent(GLFWwindow* window)
    : m_Window(window)
  {
  }

  ALS_EVENT_TYPE(WindowClose);
  ALS_EVENT_CATEGORY(CategoryWindow);

private:
  GLFWwindow* m_Window;
};

} // namespace Alius