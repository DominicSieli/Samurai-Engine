#pragma once

#include "Samurai/Events/Event.h"

namespace Samurai
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent()
		{

		}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowResizeEvent : public Event
	{
	private:
		unsigned int width = 0;
		unsigned int height = 0;

	public:
		WindowResizeEvent(unsigned int w, unsigned int h)
			: width(w), height(h)
		{

		}

		inline unsigned int GetWidth() const
		{
			return width;
		}

		inline unsigned int GetHeight() const
		{
			return height;
		}

		std::string ToString() const override
		{
			std::stringstream stringstr;
			stringstr << "WindowResizeEvent: " << width << ", " << height;
			return stringstr.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}