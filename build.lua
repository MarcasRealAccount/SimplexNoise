local pkg       = premake.extensions.pkg
local scriptDir = common:scriptDir()

local buildTool = pkg:setupPremake("SimplexNoise", "amd64", { "Debug", "Release", "Dist" }, scriptDir, "build/", "%{targetpath}/%{config}")
buildTool:mapConfigs({
	Debug = {
		config  = "Debug",
		targets = { SimplexNoise = { path = "SimplexNoise/", outputFiles = common:libName("SimplexNoise", true) } }
	},
	Release = {
		config  = "Release",
		targets = { SimplexNoise = { path = "SimplexNoise/", outputFiles = common:libName("SimplexNoise", true) } }
	},
	Dist = {
		config  = "Dist",
		targets = { SimplexNoise = { path = "SimplexNoise/", outputFiles = common:libName("SimplexNoise", false) } }
	}
})
buildTool:build()
buildTool:cleanTemp()