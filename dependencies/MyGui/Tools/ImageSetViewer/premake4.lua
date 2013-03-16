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

-- Configuration for module: MyGUI.ImageSetViewer


configuration( { "LINUX" } )
  project( "MyGUI.ImageSetViewer" )

configuration( { "WIN32" } )
  project( "MyGUI.ImageSetViewer" )

configuration( { "WIN64" } )
  project( "MyGUI.ImageSetViewer" )
location( os.getenv( "PM4OUTPUTDIR" ) )

configuration( {} )
language( "C" )

configuration( { "LINUX" } )
language( "C++" )

configuration( { "WIN32" } )
language( "C++" )

configuration( { "WIN64" } )
language( "C++" )

configuration( { "LINUX" } )


configuration( { LINUX } )
kind( "ConsoleApp" )
configuration( { "WIN32" } )


configuration( { WIN32 } )
kind( "WindowedApp" )
configuration( { "WIN64" } )


configuration( { WIN64 } )
kind( "WindowedApp" )
  
configuration( { LINUX } )
links( { "MyGUI.Engine", "MyGUI.OpenGLPlatform", "freetype" } )
  links( { "MyGUI.Engine", "MyGUI.OpenGLPlatform", "freetype" } )
  

configuration( { LINUX } )
defines( { "MYGUI_USE_FREETYPE" } )
  
configuration( { WIN32 } )
links( { "MyGUI.Engine", "MyGUI.OpenGLPlatform", "freetype" } )
  links( { "MyGUI.Engine", "MyGUI.OpenGLPlatform", "freetype" } )
  

configuration( { WIN32 } )
defines( { "MYGUI_USE_FREETYPE" } )
  
configuration( { WIN64 } )
links( { "MyGUI.Engine", "MyGUI.OpenGLPlatform", "freetype" } )
  links( { "MyGUI.Engine", "MyGUI.OpenGLPlatform", "freetype" } )
  

configuration( { WIN64 } )
defines( { "MYGUI_USE_FREETYPE" } )


configuration( { "LINUX" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "Controller.h",
      "View.h",
      "../../Common/Precompiled.h",
      "../../Common/Base/InputFocusInfo.h",
      "../../Common/Base/Main.h",
      "../../Common/Base/StatisticInfo.h",
      "../../Common/Base/OpenGL/BaseManager.h",
      "../../Common/Input/InputConverter.h",
      "../../Common/Input/OIS/InputManager.h",
      "../../Common/Input/OIS/PointerManager.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "Controller.cpp",
      "View.cpp",
      "../../Common/Precompiled.cpp",
      "../../Common/Base/OpenGL/BaseManager.cpp",
      "../../Common/Input/OIS/InputManager.cpp",
      "../../Common/Input/OIS/PointerManager.cpp"
    } )



configuration( { "WIN32" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "Controller.h",
      "View.h",
      "../../Common/Precompiled.h",
      "../../Common/Base/InputFocusInfo.h",
      "../../Common/Base/Main.h",
      "../../Common/Base/StatisticInfo.h",
      "../../Common/Base/OpenGL/BaseManager.h",
      "../../Common/Input/InputConverter.h",
      "../../Common/Input/Win32API/InputManager.h",
      "../../Common/Input/Win32API/PointerManager.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "Controller.cpp",
      "View.cpp",
      "../../Common/Precompiled.cpp",
      "../../Common/Base/OpenGL/BaseManager.cpp",
      "../../Common/Input/Win32API/InputManager.cpp",
      "../../Common/Input/Win32API/PointerManager.cpp"
    } )



configuration( { "WIN64" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "Controller.h",
      "View.h",
      "../../Common/Precompiled.h",
      "../../Common/Base/InputFocusInfo.h",
      "../../Common/Base/Main.h",
      "../../Common/Base/StatisticInfo.h",
      "../../Common/Base/OpenGL/BaseManager.h",
      "../../Common/Input/InputConverter.h",
      "../../Common/Input/Win32API/InputManager.h",
      "../../Common/Input/Win32API/PointerManager.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "Controller.cpp",
      "View.cpp",
      "../../Common/Precompiled.cpp",
      "../../Common/Base/OpenGL/BaseManager.cpp",
      "../../Common/Input/Win32API/InputManager.cpp",
      "../../Common/Input/Win32API/PointerManager.cpp"
    } )


configuration( {} )
includedirs( { "../../../freetype/include", "../../../freetype/include/freetype", "../../../freetype/include/freetype/config", "../../../freetype/include/freetype/internal", "../../../freetype/include/freetype/internal/services", "../../../freetype/src/winfonts", "../../Common/FileSystemInfo", "../../MyGUIEngine/include", "../../Platforms/OpenGL/OpenGLPlatform/include", "../../Platforms/OpenGL/OpenGLPlatform/include/GL" } )

configuration( { "LINUX" } )
includedirs( { "../ImageSetViewer", "../../Common", "../../Common/Base", "../../Common/Base/OpenGL", "../../Common/Input", "../../Common/Input/OIS" } )

configuration( { "WIN32" } )
includedirs( { "../ImageSetViewer", "../../Common", "../../Common/Base", "../../Common/Base/OpenGL", "../../Common/Input", "../../Common/Input/Win32API" } )

configuration( { "WIN64" } )
includedirs( { "../ImageSetViewer", "../../Common", "../../Common/Base", "../../Common/Base/OpenGL", "../../Common/Input", "../../Common/Input/Win32API" } )
