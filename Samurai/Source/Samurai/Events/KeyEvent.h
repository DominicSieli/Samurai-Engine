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
		KeyEvent(int keycodeValue) : keyCode(keycodeValue) {}

		int keyCode;
	};

	class SAMURAI_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycodeValue, int repeatCountValue) : KeyEvent(keycodeValue), m_RepeatCount(repeatCountValue) {}

		inline int GetRepeatCount() const { return repeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int repeatCount;
	};

	class SAMURAI_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycodeValue) : KeyEvent(keycodeValue) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class SAMURAI_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycodeValue) : KeyEvent(keycodeValue) {}

		std::string ToString() const override
		{
			std::stringstream stringstr;
			stringstr << "KeyTypedEvent: " << keyCode;
			return stringstr.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}