#pragma once

#include "Samurai/Events/Event.h"

namespace Samurai
{
	class SAMURAI_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int code)
			: keyCode(code) {}

		int keyCode;
	};

	class SAMURAI_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int code, int repeated)
			: KeyEvent(code), repeatCount(repeated) {}

		inline int GetRepeatCount() const { return repeatCount; }

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int repeatCount;
	};

	class SAMURAI_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int code)
			: KeyEvent(code) {}

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "KeyReleasedEvent: " << keyCode;
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class SAMURAI_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int code)
			: KeyEvent(code) {}

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "KeyTypedEvent: " << keyCode;
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}