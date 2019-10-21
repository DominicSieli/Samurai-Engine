#pragma once

#include "PCH.h"
#include "Samurai/Core/Core.h"

#define BITSHIFT(x) (1 << x)

namespace Samurai
{
	// To do: Implement event que system.

	enum class EventType
	{
		None = 0,

		Tick = 1,
		Update = 2,
		Render = 3,

		KeyTyped = 4,
		KeyPressed = 5,
		KeyReleased = 6,

		WindowClose = 7,
		WindowFocus = 8,
		WindowMoved = 9,
		WindowResize = 10,
		WindowLostFocus = 11,

		MouseMoved = 12,
		MouseScrolled = 13,
		MouseButtonPressed = 14,
		MouseButtonReleased = 15
	};

	enum EventCategory
	{
		None = 0,
		
		EventCategoryInput = BITSHIFT(0),
		EventCategoryMouse = BITSHIFT(1),
		EventCategoryKeyboard = BITSHIFT(2),
		EventCategoryMouseButton = BITSHIFT(3),
		EventCategoryApplication = BITSHIFT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                               virtual EventType GetEventType() const override { return GetStaticType(); }\
                               virtual const char* GetName() const override { return type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class SAMURAI_API Event
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
	public:
		EventDispatcher(Event& eventID) : event(eventID)
		{

		}

		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& function)
		{
			if (event.GetEventType() == T::GetStaticType())
			{
				event.handled = function(static_cast<T&>(event));
				return true;
			}
			return false;
		}
	private:
		Event& event;
	};

	inline std::ostream& operator<<(std::ostream& output, const Event& eventID)
	{
		return output << eventID.ToString();
	}
}