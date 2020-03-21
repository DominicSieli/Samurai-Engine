#pragma once

#include "PCH.h"

namespace Samurai
{
	enum class EventType
	{
		None = 0,
		
		KeyTyped = 1,
		KeyPressed = 2,
		KeyReleased = 3,

		WindowClose = 4,
		WindowFocus = 5,
		WindowMoved = 6,
		WindowResize = 7,
		WindowLostFocus = 8,

		MouseMoved = 9,
		MouseScrolled = 10,
		MouseButtonPressed = 11,
		MouseButtonReleased = 12
	};

	enum EventCategory
	{
		None = 0,
		
		EventCategoryInput = (1 << 0),
		EventCategoryMouse = (1 << 1),
		EventCategoryKeyboard = (1 << 2),
		EventCategoryMouseButton = (1 << 3),
		EventCategoryApplication = (1 << 4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
	public:
		bool handled = false;

		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual EventType GetEventType() const = 0;

		virtual std::string ToString() const
		{
			return GetName();
		}

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
	private:
		Event& event;

	public:
		EventDispatcher(Event& eventID)
			: event(eventID)
		{

		}
		
		template<typename T, typename F>
		bool Dispatch(const F& function)
		{
			if(event.GetEventType() == T::GetStaticType())
			{
				event.handled = function(static_cast<T&>(event));
				return true;
			}

			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& output, const Event& eventID)
	{
		return output << eventID.ToString();
	}
}