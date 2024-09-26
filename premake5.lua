workspace "BDEngine"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "BDEngine"
	location "BDEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"BD_PLATFORM_WINDOWS",
			"BD_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "BD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BD_DIST"
		optimize "On"

	--filter { "system:windows", "configurations:Release" }
	--	buildoptions = "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"BDEngine/vendor/spdlog/include",
		"BDEngine/src"
	}

	links{
		"BDEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"BD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BD_DIST"
		optimize "On"