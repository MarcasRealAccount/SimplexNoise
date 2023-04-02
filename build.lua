local pkg       = premake.extensions.pkg
local scriptDir = pkg:scriptDir()
local premake   = pkg.builders.premake

local buildTool = premake:setup("SimplexNoise", "amd64", { "Debug", "Release", "Dist" }, scriptDir, "build/", "%{targetname}/%{config}")
buildTool:mapConfigs({
	Debug = {
		config  = "Debug",
		targets = { SimplexNoise = { path = "SimplexNoise/", outputFiles = pkg:libName("SimplexNoise", true) } }
	},
	Release = {
		config  = "Release",
		targets = { SimplexNoise = { path = "SimplexNoise/", outputFiles = pkg:libName("SimplexNoise", true) } }
	},
	Dist = {
		config  = "Dist",
		targets = { SimplexNoise = { path = "SimplexNoise/", outputFiles = pkg:libName("SimplexNoise", false) } }
	}
})
buildTool:build()
buildTool:cleanTemp()