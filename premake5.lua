workspace "Samurai"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"Master"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Samurai"
	location "Samurai"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Binaries-Intermediate/" .. outputdir .. "/%{prj.name}")
	
	pchheader "PCH.h"
	pchsource "%{prj.name}/Source/PCH.cpp"
	
	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/Source",
		"%{prj.name}/Libraries/SPD-Log/include"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"SAMURAI_BUILD_DLL",
			"SAMURAI_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "SAMURAI_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "SAMURAI_RELEASE"
		runtime "Release"
		optimize "on"
	
	filter "configurations:Master"
		defines "SAMURAI_MASTER"
		runtime "Release"
		optimize "on"
	
	filter {"system:windows", "configurations:Release"}
		buildoptions "/MT"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Binaries-Intermediate/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}
	
	includedirs
	{
		"Samurai/Source",
		"Samurai/Libraries/SPD-Log/include"
	}
	
	links
	{
		"Samurai"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"SAMURAI_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "SAMURAI_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "SAMURAI_RELEASE"
		runtime "Release"
		optimize "on"
	
	filter "configurations:Master"
		defines "SAMURAI_MASTER"
		runtime "Release"
		optimize "on"