workspace "MyOpenGL"
	architecture "x86_64"
	configurations {"Debug", "Release"}

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

project "MyOpenGL"
	location "MyOpenGL"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name})")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name})")

	--pchheader
	--pchsource

	--includedirs
	
	files { "%{prj.name}/src/**.cpp" }

	-- links{"glew32s", "glfw3" , "opengl32" }

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		--defines	{ "GLEW_STATIC"  }
	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
