if os.is "linux" then
	suffix = "linux"
elseif os.is "macosx" then
	suffix = "osx"
elseif os.is "windows" then
	suffix = "win32"
end

solution "io"
	language "C++"
	location(string.format("project/%s/%s", os.get(), _ACTION))

	flags {
		"NoEditAndContinue",
		"StaticRuntime",
		"EnableSSE",
		"FloatFast",
		"Optimize",
		"NoPCH",
	}
	defines {
		"NO_SDK"
	}
	links {
		"bootil_static"
	}
	libdirs {
		"lib"
	}
	includedirs {
		"include/"
	}
	configurations {
		"debug",
		"release"
	}

	configuration "debug"
		flags	{
			"Symbols"
		}
		defines {
			"DEBUG"
		}
		linkoptions {
			"/INCREMENTAL:NO"
		}

		targetdir(string.format("bin/%s/debug/", os.get()))
	configuration "release"
		defines {
			"NDEBUG",
			"RELEASE"
		}
		targetdir(string.format("bin/%s/release/", os.get()))

	project "client"
		files 	{
			"src/**.*",
			"include/**.*"
		}
		defines {
			"CLIENT",
			"GMMODULE"
		}
		kind "SharedLib"
		targetname(string.format("gmcl_io_%s", suffix))
	project "server"
		files {
			"src/**.*",
			"include/**.*"
		}
		defines {
			"SERVER",
			"GMMODULE"
		}
		kind "SharedLib"
		targetname(string.format("gmsv_io_%s", suffix))