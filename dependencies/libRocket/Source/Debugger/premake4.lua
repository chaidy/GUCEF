--------------------------------------------------------------------
-- This file was automatically generated by ProjectGenerator
-- which is tooling part the build system designed for GUCEF
--     (Galaxy Unlimited Framework)
-- For the latest info, see http://www.VanvelzenSoftware.com/
--
-- The contents of this file are placed in the public domain. Feel
-- free to make use of it in any way you like.
--------------------------------------------------------------------
--

-- Configuration for module: RocketDebugger


project( "RocketDebugger" )
location( os.getenv( "PM4OUTPUTDIR" ) )

configuration( {} )
language( "C++" )



configuration( {} )
kind( "SharedLib" )

configuration( {} )
links( { "RocketCore", "freetype" } )
links( { "RocketCore", "freetype" } )


configuration( {} )
vpaths { ["Headers"] = { "**.h", "**.hpp", "**.hxx" } }
files( {
  "BeaconSource.h",
  "CommonSource.h",
  "ElementContextHook.h",
  "ElementInfo.h",
  "ElementLog.h",
  "FontSource.h",
  "Geometry.h",
  "InfoSource.h",
  "LogSource.h",
  "MenuSource.h",
  "Plugin.h",
  "SystemInterface.h"
 } )



configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "Debugger.cpp",
  "ElementContextHook.cpp",
  "ElementInfo.cpp",
  "ElementLog.cpp",
  "Geometry.cpp",
  "Plugin.cpp",
  "SystemInterface.cpp"
 } )


configuration( {} )
includedirs( { "../../../freetype/include", "../../../freetype/include/freetype", "../../../freetype/include/freetype/config", "../../../freetype/include/freetype/internal", "../../../freetype/include/freetype/internal/services", "../../../freetype/src/winfonts", "../../Include", "../../Include/Rocket", "../../Include/Rocket/Controls", "../../Include/Rocket/Core", "../../Include/Rocket/Core/Python", "../../Include/Rocket/Debugger", "../Core" } )
