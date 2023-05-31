workspace "EngineA"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "EngineA/Vendor/GLFW/include"

include "EngineA/Vendor/GLFW"

project "EngineA"
	location "EngineA"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/" .. outputdir .. "/%{prj.name}")

	pchheader "eapch.h"
	pchsource "EngineA/src/eapch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.c"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/Vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EA_PLATFORM_WINDOWS",
			"EA_BUILD_DLL"
		}

		postbuildcommands
		{
			 ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "EA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EA_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "EA_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.c"
	}

	includedirs
	{
		"EngineA/Vendor/spdlog/include",
		"EngineA/src"
	}

	links
	{
		"EngineA"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "EA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EA_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "EA_DIST"
		symbols "On"