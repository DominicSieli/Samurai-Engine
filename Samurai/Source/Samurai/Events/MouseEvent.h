#pragma once

#include "Samurai/Events/Event.h"

namespace Samurai
{
	class SAMURAI_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: mouseX(x), mouseY(y) {}

		inline float GetX() const { return mouseX; }
		inline float GetY() const { return mouseY; }

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "MouseMovedEvent: " << mouseX << ", " << mouseY;
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float mouseX, mouseY;
	};

	class SAMURAI_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x, float y)
			: offsetX(x), offsetY(y) {}

		inline float GetOffsetX() const { return offsetX; }
		inline float GetOffsetY() const { return offsetY; }

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "MouseScrolledEvent: " << GetOffsetX() << ", " << GetOffsetY();
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float offsetX, offsetY;
	};

	class SAMURAI_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int buttonID)
			: button(buttonID) {}

		int button;
	};

	class SAMURAI_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int buttonID)
			: MouseButtonEvent(buttonID) {}

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "MouseButtonPressedEvent: " << button;
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class SAMURAI_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int buttonID)
			: MouseButtonEvent(buttonID) {}

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "MouseButtonReleasedEvent: " << button;
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}