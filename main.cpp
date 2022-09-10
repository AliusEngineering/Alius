/* Test application, not intended for actual use */

#include "Alius/Alius.hpp"

#include "Alius/Events/EventBus.hpp"

int
main()
{
  SQD::Logger::EnableLogger();
  Alius::Application app(960, 540, "New Alius App");

  ALS_EVENTS_SUBSCRIBE(WindowResize, [](Alius::WindowResizeEvent& e) {
	SQD_LOG("First WindowResize handler");
	SQD_LOG("WindowResizeEvent: w: {}, h: {}", e.GetWidth(), e.GetHeight());
  });

  ALS_EVENTS_SUBSCRIBE(MouseButtonPress, [](Alius::MouseButtonPressEvent& e) {
	SQD_LOG("Mouse button pressed! Button code: {}", e.GetMouseButton());
  });

  ALS_EVENTS_SUBSCRIBE(KeyPress, [](Alius::KeyPressEvent& e) {
	SQD_LOG("Caught key press event. Keycode: {}. Is repeated: {}.\nMods: "
	        "Shift - {}, Ctrl - {}, Alt - {}, CapsLk - {}",
	        std::to_string(e.GetKeyCode()),
	        e.IsRepeated(),
	        e.HasModPressed(Alius::Modifiers::ModShift) ? "1" : "0",
	        e.HasModPressed(Alius::Modifiers::ModCtrl) ? "1" : "0",
	        e.HasModPressed(Alius::Modifiers::ModAlt) ? "1" : "0",
	        e.HasModPressed(Alius::Modifiers::ModCapsLk) ? "1" : "0");
  });

  ALS_EVENTS_SUBSCRIBE(WindowMinimize, [](Alius::WindowMinimizeEvent& e) {
	SQD_LOG("Window minimized!");
  });

  while (app.IsRunning()) {
	// Render stuff and execute commands
	// ...

	// Poll and process events
	app.OnUpdate();
  }
}
