#pragma once

#include "Core/AliusCore.hpp"

#include "Event.hpp"

namespace Alius {

class KeyEvent : public Event
{
public:
  KeyEvent(KeyCodes keycode, int mods, bool repeat = false)
    : m_KeyCode(keycode)
    , m_Modifiers(mods)
    , m_IsRepeated(repeat)
  {
  }

  [[nodiscard]] KeyCodes GetKeyCode() const { return m_KeyCode; }
  [[nodiscard]] bool IsRepeated() const { return m_IsRepeated; }
  [[nodiscard]] bool HasModPressed(Modifiers mod) const
  {
	return m_Modifiers & mod;
  }

  ALS_EVENT_CATEGORY(CategoryKeyboard | CategoryInput);

private:
  KeyCodes m_KeyCode;
  int m_Modifiers;

  bool m_IsRepeated;
};

class KeyPressEvent : public KeyEvent
{
public:
  KeyPressEvent(KeyCodes keycode, int mods, bool repeat = false)
    : KeyEvent(keycode, mods, repeat){};

  ALS_EVENT_TYPE(KeyPress);
};

class KeyReleaseEvent : public KeyEvent
{
public:
  KeyReleaseEvent(KeyCodes keycode, int mods, bool repeat = false)
    : KeyEvent(keycode, mods, repeat)
  {
  }

  ALS_EVENT_TYPE(KeyRelease);
};

class KeyEnterEvent : public KeyEvent
{
public:
  KeyEnterEvent(KeyCodes keycode, int mods)
    : KeyEvent(keycode, mods, false)
  {
  }

  ALS_EVENT_TYPE(KeyEnter);
};

} // namespace Alius
