local pkg = premake.extensions.pkg

libdirs({ pkg:scriptDir() .. string.format("/Bin/%s-%s-", os.host(), pkg.arch) .. "%{cfg.buildcfg}" })
links({ "SimplexNoise" })
externalincludedirs({ pkg:scriptDir() .. "/Inc/" })