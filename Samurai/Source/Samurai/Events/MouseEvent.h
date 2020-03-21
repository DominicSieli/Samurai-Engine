#pragma once

#include "Samurai/Events/Event.h"

namespace Samurai
{
	class MouseMovedEvent : public Event
	{
	private:
		float mouseX, mouseY;

	public:
		MouseMovedEvent(float x, float y)
			: mouseX(x), mouseY(y)
		{

		}

		inline float GetX() const
		{
			return mouseX;
		}

		inline float GetY() const
		{
			return mouseY;
		}

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "MouseMovedEvent: " << mouseX << ", " << mouseY;
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class MouseScrolledEvent : public Event
	{
	private:
		float offsetX, offsetY;

	public:
		MouseScrolledEvent(float x, float y)
			: offsetX(x), offsetY(y)
		{

		}

		inline float GetOffsetX() const
		{
			return offsetX;
		}

		inline float GetOffsetY() const
		{
			return offsetY;
		}

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "MouseScrolledEvent: " << GetOffsetX() << ", " << GetOffsetY();
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class MouseButtonEvent : public Event
	{
	protected:
		MouseButtonEvent(int buttonID)
			: button(buttonID)
		{

		}

		int button;

	public:
		inline int GetMouseButton() const
		{
			return button;
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int buttonID)
			: MouseButtonEvent(buttonID)
		{

		}

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "MouseButtonPressedEvent: " << button;
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int buttonID)
			: MouseButtonEvent(buttonID)
		{

		}

		std::string ToString() const override
		{
			std::stringstream stringStrm;
			stringStrm << "MouseButtonReleasedEvent: " << button;
			return stringStrm.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}