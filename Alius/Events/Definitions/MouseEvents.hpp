#pragma once

#include "Core/AliusCore.hpp"

#include "Event.hpp"

namespace Alius {

class MouseEvent : public Event
{
public:
  MouseEvent(MouseButtons button)
    : m_Button(button)
  {
  }

  MouseButtons GetMouseButton() const { return m_Button; }

  ALS_EVENT_CATEGORY(CategoryMouse | CategoryInput);

private:
  MouseButtons m_Button;
};

class MouseButtonPressEvent : public MouseEvent
{
public:
  MouseButtonPressEvent(MouseButtons button)
    : MouseEvent(button)
  {
  }
  ALS_EVENT_TYPE(MouseButtonPress);
};

class MouseButtonReleaseEvent : public MouseEvent
{
public:
  MouseButtonReleaseEvent(MouseButtons button)
    : MouseEvent(button)
  {
  }
  ALS_EVENT_TYPE(MouseButtonRelease);
};

class MouseMoveEvent : public Event
{
public:
  struct MousePosition
  {
	MousePosition(float x, float y)
	  : pos_x(x)
	  , pos_y(y)
	{
	}

	[[nodiscard]] float GetX() const { return pos_x; }
	[[nodiscard]] float GetY() const { return pos_y; }

	float pos_x;
	float pos_y;
  };

public:
  MouseMoveEvent(MousePosition position)
    : m_Position(position)
  {
  }

  [[nodiscard]] MousePosition GetPosition() const { return m_Position; }
  [[nodiscard]] float GetX() const { return m_Position.GetX(); }
  [[nodiscard]] float GetY() const { return m_Position.GetY(); }

  ALS_EVENT_TYPE(MouseMove);
  ALS_EVENT_CATEGORY(CategoryMouse | CategoryInput);

private:
  MousePosition m_Position;
};

class MouseScrollEvent : public Event
{
public:
  MouseScrollEvent(float offset)
    : m_Offset(offset)
  {
  }

  [[nodiscard]] float GetOffset() const { return m_Offset; }

  ALS_EVENT_TYPE(MouseScroll);
  ALS_EVENT_CATEGORY(CategoryMouse | CategoryInput);

private:
  float m_Offset;
};

}
