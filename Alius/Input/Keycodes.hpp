#pragma once

#include "GLFW/glfw3.h"

namespace Alius {

enum KeyCodes
{
  // Alphabetical
  A = GLFW_KEY_A,
  B = GLFW_KEY_B,
  C = GLFW_KEY_C,
  D = GLFW_KEY_D,
  E = GLFW_KEY_E,
  F = GLFW_KEY_F,
  G = GLFW_KEY_G,
  H = GLFW_KEY_H,
  I = GLFW_KEY_I,
  J = GLFW_KEY_J,
  K = GLFW_KEY_K,
  L = GLFW_KEY_L,
  M = GLFW_KEY_M,
  N = GLFW_KEY_N,
  O = GLFW_KEY_O,
  P = GLFW_KEY_P,
  Q = GLFW_KEY_Q,
  R = GLFW_KEY_R,
  S = GLFW_KEY_S,
  T = GLFW_KEY_T,
  U = GLFW_KEY_U,
  V = GLFW_KEY_V,
  W = GLFW_KEY_W,
  X = GLFW_KEY_X,
  Y = GLFW_KEY_Y,
  Z = GLFW_KEY_Z,
  // Numerica = GLFW_KEY_l
  One = GLFW_KEY_1,
  Two = GLFW_KEY_2,
  Three = GLFW_KEY_3,
  Four = GLFW_KEY_4,
  Five = GLFW_KEY_5,
  Six = GLFW_KEY_6,
  Seven = GLFW_KEY_7,
  Eight = GLFW_KEY_8,
  Nine = GLFW_KEY_9,
  Zero = GLFW_KEY_0,
  Plus = GLFW_KEY_EQUAL,
  Equal = GLFW_KEY_EQUAL,
  Minus = GLFW_KEY_MINUS,
  // Modifier = GLFW_KEY_s
  Backspace = GLFW_KEY_BACKSLASH,
  Enter = GLFW_KEY_ENTER,
  LShift = GLFW_KEY_LEFT_SHIFT,
  RShift = GLFW_KEY_RIGHT_SHIFT,
  LAlt = GLFW_KEY_LEFT_ALT,
  RAlt = GLFW_KEY_RIGHT_ALT,
  LSuper = GLFW_KEY_LEFT_SUPER,
  RSuper = GLFW_KEY_RIGHT_SUPER,
  //  Fn = GLFW_KEY_MENU,
  // F-Row
  F1 = GLFW_KEY_F1,
  F2 = GLFW_KEY_F2,
  F3 = GLFW_KEY_F3,
  F4 = GLFW_KEY_F4,
  F5 = GLFW_KEY_F5,
  F6 = GLFW_KEY_F6,
  F7 = GLFW_KEY_F7,
  F8 = GLFW_KEY_F8,
  F9 = GLFW_KEY_F9,
  F10 = GLFW_KEY_F10,
  F11 = GLFW_KEY_F11,
  F12 = GLFW_KEY_F12,
  // Misc
  Space = GLFW_KEY_SPACE,
  Tab = GLFW_KEY_TAB,
  Esc = GLFW_KEY_ESCAPE,
  Tilde = GLFW_KEY_GRAVE_ACCENT,
  Comma = GLFW_KEY_COMMA,
  Dot = GLFW_KEY_PERIOD,
  Slash = GLFW_KEY_SLASH,
  BackSlash = GLFW_KEY_BACKSLASH,
  ArrowUp = GLFW_KEY_UP,
  ArrowDown = GLFW_KEY_DOWN,
  ArrowLeft = GLFW_KEY_LEFT,
  ArrowRight = GLFW_KEY_RIGHT,
  // Functional
  Delete = GLFW_KEY_DELETE,
  Insert = GLFW_KEY_INSERT,
  PrtSc = GLFW_KEY_PRINT_SCREEN,
  PgUp = GLFW_KEY_PAGE_UP,
  PgDown = GLFW_KEY_PAGE_DOWN,
  Home = GLFW_KEY_HOME,
  End = GLFW_KEY_END,
  // Symbols
  Apostrophe = GLFW_KEY_APOSTROPHE,
  Semicolon = GLFW_KEY_SEMICOLON,
  LeftBracket = GLFW_KEY_LEFT_BRACKET,
  RightBracket = GLFW_KEY_RIGHT_BRACKET
};

enum Modifiers
{
  ModShift = GLFW_MOD_SHIFT,
  ModCtrl = GLFW_MOD_CONTROL,
  ModAlt = GLFW_MOD_ALT,
  ModCapsLk = GLFW_MOD_CAPS_LOCK,
  ModSuper = GLFW_MOD_SUPER,
  ModNumLk = GLFW_MOD_NUM_LOCK
};

} // namespace Alius