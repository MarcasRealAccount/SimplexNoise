workspace("SimplexNoise")
	common:setConfigsAndPlatforms()
	common:addCoreDefines()

	cppdialect("C++20")
	rtti("Off")
	exceptionhandling("Off")
	flags("MultiProcessorCompile")

	project("SimplexNoise")
		location("")
		warnings("Extra")

		kind("StaticLib")
		common:outDirs(true)

		includedirs({ "%{prj.location}/Inc/" })
		files({
			"%{prj.location}/Inc/**",
			"%{prj.location}/Src/**"
		})
		removefiles({ "*.DS_Store" })

		common:addActions()