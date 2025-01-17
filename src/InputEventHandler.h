#pragma once

class InputEventHandler : public RE::BSInputDeviceManager::Sink
{
public:
	using Event = RE::InputEvent*;

	static auto GetSingleton() -> InputEventHandler*;
	void Register();

	auto ProcessEvent(const Event* a_event, RE::BSTEventSource<Event>* a_eventSource)
		-> RE::BSEventNotifyControl override;

	bool IsUsingGamepad() const;

	bool analogKeyboard;

private:
	InputEventHandler();

	static void RefreshMenus();

	static void DoRefreshMenus();

	static void ComputeMouseLookVector(std::int32_t a_mouseInputX, std::int32_t a_mouseInputY);

	bool _usingGamepad;
};
