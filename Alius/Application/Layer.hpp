#pragma once

namespace Alius {

class Layer
{
public:
  virtual ~Layer() = default;

  virtual void OnUpdate() = 0;

  virtual void OnAttach() = 0;
  virtual void OnDetach() = 0;
};

}
