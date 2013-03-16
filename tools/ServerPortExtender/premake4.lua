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

-- Configuration for module: ServerPortExtender


project( "ServerPortExtender" )
location( os.getenv( "PM4OUTPUTDIR" ) )

configuration( {} )
language( "C++" )

configuration( { "WIN32" } )


configuration( { WIN32 } )
kind( "WindowedApp" )
configuration( { "NOT WIN32" } )
  

configuration( {} )
kind( "ConsoleApp" )

configuration( {} )
links( { "gucefCOMCORE", "gucefCORE", "gucefMT" } )
links( { "gucefCOMCORE", "gucefCORE", "gucefMT" } )


configuration( {} )
vpaths { ["Headers"] = { "**.h", "**.hpp", "**.hxx" } }
files( {
  "include/CServerPortExtender.h",
  "include/CServerPortExtenderClient.h",
  "include/ServerPortExtenderProtocol.h"
 } )



configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "src/CServerPortExtender.cpp",
  "src/CServerPortExtenderClient.cpp",
  "src/main.cpp"
 } )


configuration( {} )
includedirs( { "../../common/include", "../../gucefCOMCORE/include", "../../gucefCORE/include", "../../gucefMT/include", "include" } )

configuration( { "ANDROID" } )
includedirs( { "../../gucefCORE/include/android" } )

configuration( { "LINUX" } )
includedirs( { "../../gucefCORE/include/linux" } )

configuration( { "WIN32" } )
includedirs( { "../../gucefCOMCORE/include/mswin", "../../gucefCORE/include/mswin" } )

configuration( { "WIN64" } )
includedirs( { "../../gucefCOMCORE/include/mswin", "../../gucefCORE/include/mswin" } )
