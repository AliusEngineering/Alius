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

  Alius::ObjectData triangleData = {
	{ -1.0f, 1.0f }, // bottom left
	{ 1.0f, 1.0f },  // bottom right
	{ 0.0f, -1.0f }  // top middle
  };

  triangleData.SetVertexColor(0, { 0.792, 0.773, 0.192 });
  triangleData.SetVertexColor(1, { 0.953, 0.976, 0.655 });
  triangleData.SetVertexColor(2, { 1.0, 0.753, 0.796 });

  auto triangle = renderer->CreateObject<Alius::Triangle>(triangleData);

  app.PushLayer(new TestLayer());

  while (app.IsRunning()) {
	renderer->BeginFrame();

	renderer->Draw(triangle);

	renderer->EndFrame();

	app.OnUpdate();
  }
}
