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
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "SamuraiPCH.h"
	pchsource "%{prj.name}/src/SamuraiPCH.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"SAMURAI_PLATFORM_WINDOWS",
			"SAMURAI_BUILD_DLL"
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
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Samurai/src",
		"Samurai/vendor/spdlog/include"
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