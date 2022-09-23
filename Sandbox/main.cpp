/* Test application, not intended for actual use */

#include "Alius/Alius.hpp"

class TestLayer : public Alius::Layer
{
public:
  TestLayer() = default;

  void OnUpdate() override{};

  void OnAttach() override { SQD_LOG("TestLayer attached!"); };
  void OnDetach() override { SQD_LOG("TestLayer detached!"); };
};

int
main()
{
  Alius::Application app(960, 540, "New Alius App");

  auto renderer = Alius::Application::GetRenderer();

  app.PushLayer(new TestLayer());

  while (app.IsRunning()) {
	renderer->BeginFrame();
	renderer->Draw(3, 0, 1, 0);
	renderer->EndFrame();

	app.OnUpdate();
  }
}
