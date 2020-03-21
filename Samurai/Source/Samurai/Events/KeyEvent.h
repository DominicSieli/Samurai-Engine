#pragma once

#include "Samurai/Events/Event.h"

namespace Samurai
{
	class KeyEvent : public Event
	{
	protected:
		int keyCode;

	public:
		inline int GetKeyCode() const
		{
			return keyCode;
		}

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

		KeyEvent(int code)
			: keyCode(code)
		{

		}
	};

	class KeyPressedEvent : public KeyEvent
	{
	private:
		int repeatCount;

	public:
		KeyPressedEvent(int code, int repeated)
			: KeyEvent(code), repeatCount(repeated)
		{

		}

		inline int GetRepeatCount() const
		{
			return repeatCount;
		}

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int code)
			: KeyEvent(code)
		{

		}

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "KeyReleasedEvent: " << keyCode;
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int code)
			: KeyEvent(code)
		{

		}

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "KeyTypedEvent: " << keyCode;
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}