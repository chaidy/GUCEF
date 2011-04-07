@echo off

SET GUCEF_THEBATCHDIR=%CD%
GOTO FIND_GUCEF_CMAKE_SLN_DEBUG_MVC9_CMAKELISTGENERATOR


REM -----------------------------------------------------

:FIND_GUCEF_RELEASE_CMAKELISTGENERATOR

SET GENERATORPATH=%GUCEF_THEBATCHDIR%\..\..\tools\ProjectGenerator\bin\ReleasedBins\Win32\5April2010\
SET GENERATOREXE=ProjectGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = "%EXETEST%"
IF EXIST "%EXETEST%" (
  ECHO Using released version of ProjectGenerator dated 5'th April 2011
  GOTO RUN_CMAKELISTGENERATOR
)

IF NOT EXIST "%EXETEST%" (
  ECHO Error: Unable to locate GUCEF released CMakeListGenerator
  GOTO END
)
    
cd "%GUCEF_THEBATCHDIR%"
GOTO RUN_CMAKELISTGENERATOR

REM -----------------------------------------------------

:FIND_GUCEF_CMAKE_SLN_DEBUG_MVC9_CMAKELISTGENERATOR

SET GENERATORPATH=%GUCEF_THEBATCHDIR%\..\..\common\bin\MVC9\bin\Debug
SET GENERATOREXE=ProjectGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = "%EXETEST%"
IF EXIST "%EXETEST%" (
  ECHO Warning: Using CMake debug development version of the ProjectGenerator
  GOTO RUN_CMAKELISTGENERATOR
)

IF NOT EXIST "%EXETEST%" (
  ECHO Cannot locate CMake debug development version of the ProjectGenerator
  GOTO FIND_GUCEF_RELEASE_CMAKELISTGENERATOR
)

cd "%GUCEF_THEBATCHDIR%"
GOTO RUN_CMAKELISTGENERATOR

REM -----------------------------------------------------

:RUN_CMAKELISTGENERATOR

SET PATH="%GENERATORPATH%";%PATH%

cd %GUCEF_THEBATCHDIR%\..\..\

IF NOT DEFINED GUCEF_HOME (
  ECHO GUCEF environment variable not found, setting it
  SET GUCEF_HOME=%CD%
  ECHO GUCEF_HOME=%CD%
)

%GENERATOREXE% *rootDir=%GUCEF_HOME%* *dirsToIgnore=.svn;_svn* *projectName=GUCEF* *generators=cmake* *outputDir=%GUCEF_HOME%* *cmakgen:TemplateDir=%GUCEF_HOME%\projects\CMake\ProjectGenTemplates*
cd "%GUCEF_THEBATCHDIR%"
GOTO END


REM -----------------------------------------------------

:END

IF NOT DEFINED NOPAUSE (
  PAUSE
)