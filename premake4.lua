
-- A solution contains projects, and defines the available configurations
solution "SimpleDelegate"
	configurations { "Debug", "Release" }
	platforms { "x32", "x64" }
	
	-- A project defines one build target
	project "Classy"
		kind "ConsoleApp"
		language "C++"
		files {
			"Samples/Classy/*.cpp"
		}
		
		includedirs {
			"include/"
		}
 
		configuration "Debug"
			defines({ "DEBUG" })
		
			if os.get() == "windows" then
				defines({ "_WIN32", "WIN32" })
			end
		
			if os.get() == "linux" then
				defines({ "__LINUX__" })

				buildoptions { "-std=c++0x" }
			end
		
			if os.get() == "macosx" then
				defines({ "__APPLE__" })
			end

			flags { "Symbols" }
 
		configuration "Release"
			defines({ "NDEBUG" })
			
			if os.get() == "windows" then
				defines({ "_WIN32", "WIN32" })
			end
		
			if os.get() == "linux" then
				defines({ "__LINUX__" })

				buildoptions { "-std=c++0x" }
			end
		
			if os.get() == "macosx" then
				defines({ "__APPLE__" })
			end

			flags { "Optimize" }
