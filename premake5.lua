workspace "Tetra"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include files relative to the root folder (.sln)
includedir = {}
includedir['GLFW'] = "Tetra/vendor/GLFW/include"
includedir['Glad'] = "Tetra/vendor/Glad/include"
includedir["ImGui"] = "Tetra/vendor/imgui"
includedir['glm'] = "Tetra/vendor/glm"

include "Tetra/vendor/GLFW"
include "Tetra/vendor/Glad"
include "Tetra/vendor/imgui"


project "Tetra"
	location "Tetra"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "trpch.h"
	pchsource "Tetra/src/trpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		-- Caused by:
		-- 4 > ImGuiBuild.cpp
		-- 4 > C:\dev\Tetra\Tetra\vendor\imgui\examples\imgui_impl_opengl3.cpp(194, 5) : warning C4996 : 'strcpy' : This function or variable may be unsafe.Consider using strcpy_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.
		-- 4 > C:\dev\Tetra\Tetra\vendor\imgui\examples\imgui_impl_opengl3.cpp(195, 5) : warning C4996 : 'strcat' : This function or variable may be unsafe.Consider using strcat_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.
		-- 4 > C:\dev\Tetra\Tetra\vendor\imgui\examples\imgui_impl_opengl3.cpp(521, 5) : warning C4996 : 'sscanf' : This function or variable may be unsafe.Consider using sscanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{includedir.GLFW}",
		"%{includedir.Glad}",
		"%{includedir.ImGui}",
		"%{includedir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOWS",
			"TR_BUILD_DLL",
			"GLFW_INCLUDE_NONE" -- Doesn't include OpenGL headers when including GLFW cause they're included with GLAD
		}

	filter "configurations:Debug"
		defines "TR_DEBUG"
		symbols "on"
		runtime "Debug"

	filter "configurations:Release"
		defines "TR_RELEASE"
		optimize "on"
		runtime "Release"

	filter "configurations:Dist"
		defines "TR_DIST"
		optimize "on"
		runtime "Release"

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
		"Tetra/vendor/spdlog/include",
		"Tetra/src",
		"Tetra/vendor",
		"%{includedir.glm}"
	}

	links
	{
		"Tetra"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TR_DEBUG"
		symbols "on"
		runtime "Debug"

	filter "configurations:Release"
		defines "TR_RELEASE"
		optimize "on"
		runtime "Release"

	filter "configurations:Dist"
		defines "TR_DIST"
		optimize "on"
		runtime "Release"
