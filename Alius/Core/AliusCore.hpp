#pragma once

#ifdef ALS_RELEASE
#define SQD_DISABLE_LOGGER 1
#endif

// std
#include "set"
#include "string"
#include "unordered_map"
#include "vector"

#include "algorithm"

#include "memory"

// 3rd-party
#include "Logger.hpp"

// Alius Base
#include "RendererBase/Renderer.hpp"
#include "WindowBase/Window.hpp"

#define ALS_LOAD_CORE_MODULE(moduleStorage, moduleIdentifier, module, ...)     \
  try {                                                                        \
	auto creator = moduleStorage.at(moduleIdentifier);                         \
	module = creator(__VA_ARGS__);                                             \
  } catch (std::out_of_range & oor) {                                          \
	SQD_ERR(                                                                   \
	  "Failed to find module {}! It is required to start the application.",    \
	  moduleIdentifier);                                                       \
	throw std::runtime_error(                                                  \
	  "Failed to allocate Alius module: " moduleIdentifier ". It is "          \
	  "required to run the application!");                                     \
  }

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T, typename... Args>
Ref<T>
MakeRef(Args... constructArgs)
{
  return std::make_shared<T>(constructArgs...);
}

#define BIT(shift) (1 << (shift))
