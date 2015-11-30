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

-- Configuration for module: ProjectGenVSImporter


project( "ProjectGenVSImporter" )

configuration( {} )
  location( os.getenv( "PM4OUTPUTDIR" ) )

configuration( {} )
  targetdir( os.getenv( "PM4TARGETDIR" ) )

configuration( {} )
language( "C++" )



configuration( {} )
kind( "SharedLib" )

configuration( {} )
links( { "ProjectGen", "gucefCORE", "gucefMT" } )
links( { "ProjectGen", "gucefCORE", "gucefMT" } )


configuration( {} )
defines( { "PROJECTGENVSIMPORTER_BUILD_MODULE" } )


configuration( {} )
vpaths { ["Headers"] = { "**.h", "**.hpp", "**.hxx" } }
files( {
  "include/ProjectGenVSImporter.h",
  "include/ProjectGenVSImporter_CDirPreprocessor.h",
  "include/ProjectGenVSImporter_config.h",
  "include/ProjectGenVSImporter_macros.h"
 } )



configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "src/ProjectGenVSImporter.cpp",
  "src/ProjectGenVSImporter_CDirPreprocessor.cpp"
 } )


configuration( {} )
includedirs( { "../../../../common/include", "../../../../gucefCORE/include", "../../../../gucefMT/include", "../../../ProjectGen/include", "include" } )

configuration( { "ANDROID" } )
includedirs( { "../../../../gucefCORE/include/android" } )

configuration( { "LINUX" } )
includedirs( { "../../../../gucefCORE/include/linux" } )

configuration( { "WIN32" } )
includedirs( { "../../../../gucefCORE/include/mswin" } )

configuration( { "WIN64" } )
includedirs( { "../../../../gucefCORE/include/mswin" } )
