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

-- Configuration for module: guidriverAndroidGLES


configuration( { "ANDROID" } )
  project( "guidriverAndroidGLES" )
location( os.getenv( "PM4OUTPUTDIR" ) )

configuration( {} )
language( "C" )

configuration( { "ANDROID" } )
language( "C++" )

configuration( { "ANDROID" } )


configuration( { ANDROID } )
kind( "SharedLib" )
  
configuration( { ANDROID } )
links( { "gucefCORE", "gucefGUI", "gucefMT" } )
  links( { "EGL", "GLESv1_CM", "android", "android_native_app_glue", "gucefCORE", "gucefGUI", "gucefMT" } )
  

configuration( { ANDROID } )
defines( { "GUIDRIVERANDROIDGLES_BUILD_MODULE" } )


configuration( { "ANDROID" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "include/guidriverAndroidGLES.h",
      "include/guidriverAndroidGLES_CAndroidGLESWindowContext.h",
      "include/guidriverAndroidGLES_CAndroidWindowManagerImp.h",
      "include/guidriverAndroidGLES_config.h",
      "include/guidriverAndroidGLES_macros.h",
      "include/guidriverAndroidGLES_pluginAPI.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "src/guidriverAndroidGLES_CAndroidGLESWindowContext.cpp",
      "src/guidriverAndroidGLES_CAndroidWindowManagerImp.cpp",
      "src/guidriverAndroidGLES_pluginAPI.cpp"
    } )


configuration( {} )
includedirs( { "../../../common/include", "../../../gucefCORE/include", "../../../gucefGUI/include", "../../../gucefIMAGE/include", "../../../gucefMT/include", "../../../gucefVFS/include" } )

configuration( { "ANDROID" } )
includedirs( { "../../../gucefCORE/include/android", "include" } )
