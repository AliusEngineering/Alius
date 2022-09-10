#pragma once

#include "Core/AliusCore.hpp"

#include "Input/Keycodes.hpp"
#include "Input/MouseButtons.hpp"

namespace Alius {

enum class EventType
{
  None = 0,
  WindowClose,
  WindowResize,
  WindowMinimize,
  KeyPress,
  KeyRelease,
  KeyEnter,
  MouseButtonPress,
  MouseButtonRelease,
  MouseMove,
  MouseScroll
};

enum EventCategory
{
  CategoryNone = 0,
  CategoryWindow = BIT(0),
  CategoryKeyboard = BIT(1),
  CategoryMouse = BIT(2),
  CategoryInput = BIT(3)
};

#define ALS_EVENT_TYPE(type)                                                   \
  static EventType GetStaticType()                                             \
  {                                                                            \
	return EventType::type;                                                    \
  }                                                                            \
  EventType GetType() const override                                           \
  {                                                                            \
	return GetStaticType();                                                    \
  }

#define ALS_EVENT_CATEGORY(category)                                           \
  int GetCategoryFlags() const override                                        \
  {                                                                            \
	return category;                                                           \
  }

class Event
{
public:
  virtual ~Event() = default;

  virtual EventType GetType() const = 0;
  virtual int GetCategoryFlags() const = 0;
  [[nodiscard]] bool IsOfType(EventType type) const
  {
	return (int)GetType() & (int)type;
  };

  void Complete(bool completed = true) { m_IsCompleted = completed; }
  bool IsCompleted() const { return m_IsCompleted; }

  bool IsInCategory(EventCategory c) { return GetCategoryFlags() & c; }

private:
  bool m_IsCompleted = false;
};

} // namespace Alius

namespace std {

template<>
struct hash<Alius::Event>
{
  ::size_t operator()(const Alius::Event& e) const
  {
	return static_cast<size_t>(e.GetType());
  }
};

}
