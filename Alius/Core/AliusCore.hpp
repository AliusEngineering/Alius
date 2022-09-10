#pragma once

// std
#include "set"
#include "string"
#include "unordered_map"
#include "vector"

#include "algorithm"

#include "memory"

// 3rd-party
#include "Logger.hpp"

// Alius
#include "Application/Window.hpp"

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T, typename... Args>
Ref<T>
MakeRef(Args... constructArgs)
{
  return std::make_shared<T>(constructArgs...);
}

#define BIT(shift) (1 << (shift))
