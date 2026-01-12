workspace "Hive"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to the root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Hive/vendor/GLFW/include"
IncludeDir["glad"] = "Hive/vendor/glad/include"

include "Hive/vendor/GLFW"
include "Hive/vendor/glad"

project "Hive"
    location "Hive"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "HivePreCompiledHeader.h"
    pchsource "Hive/src/HivePreCompiledHeader.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.glad}"
    }

    --libdirs
    --{
    --    "%{prj.name}/vendor/GLFW/lib/GLFW"
    --}

    links
    {
        "opengl32.lib",
        "GLFW",
        "glad"
    }

    filter "system:windows"
        cppdialect "C++23"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "HV_PLATFORM_WINDOWS",
            "HV_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        -- buildoptions
        -- {
        --     "/utf-8",
        --     "/MT"
        -- }

    filter "configurations:Debug"
        defines "HV_DEBUG"
        symbols "On"
        buildoptions
        {
            "/utf-8",
            "/MDd"
        }

    filter "configurations:Release"
        defines "HV_RELEASE"
        optimize "On"
        buildoptions
        {
            "/utf-8",
            "/MD"
        }

    filter "configurations:Dist"
        defines "HV_DIST"
        optimize "On"
        buildoptions
        {
            "/utf-8",
            "/MD"
        }

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Hive/vendor/spdlog/include",
        "Hive/src"
    }

    links
    {
        "Hive"
    }

    -- buildoptions
    -- {
    --     "/utf-8",
    --     "/MT"
    -- }

    filter "system:windows"
        cppdialect "C++23"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "HV_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "HV_DEBUG"
        symbols "On"
        buildoptions
        {
            "/utf-8",
            "/MDd"
        }

    filter "configurations:Release"
        defines "HV_RELEASE"
        optimize "On"
        buildoptions
        {
            "/utf-8",
            "/MD"
        }

    filter "configurations:Dist"
        defines "HV_DIST"
        optimize "On"
        buildoptions
        {
            "/utf-8",
            "/MD"
        }