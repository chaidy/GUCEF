#-------------------------------------------------------------------
# This file has been automatically generated by ProjectGenerator    
# which is part of a build system designed for GUCEF                
#     (Galaxy Unlimited Framework)                                  
# For the latest info, see http://www.VanvelzenSoftware.com/        
#                                                                   
# The contents of this file are placed in the public domain. Feel   
# free to make use of it in any way you like.                       
#-------------------------------------------------------------------


ifndef MY_MODULE_PATH
  MY_MODULE_PATH := $(call my-dir)
endif
LOCAL_PATH := $(MY_MODULE_PATH)

include $(CLEAR_VARS)

@echo Module path: $(MY_MODULE_PATH)
LOCAL_MODULE := guidriverRocketOpenGL
LOCAL_MODULE_FILENAME := libguidriverRocketOpenGL
@echo Module name: $(LOCAL_MODULE)

LOCAL_SRC_FILES := \
  src/guidriverRocketOpenGL_CRocketGuiDriver.cpp \
  src/guidriverRocketOpenGL_CRocketRenderInterfaceOpenGL.cpp \
  src/guidriverRocketOpenGL_pluginAPI.cpp

LOCAL_C_INCLUDES := \
  $(MY_MODULE_PATH)/include \
  $(MY_MODULE_PATH)/../../../common/include \
  $(MY_MODULE_PATH)/../../../dependencies/freetype/include \
  $(MY_MODULE_PATH)/../../../dependencies/freetype/include/freetype \
  $(MY_MODULE_PATH)/../../../dependencies/freetype/include/freetype/config \
  $(MY_MODULE_PATH)/../../../dependencies/freetype/include/freetype/internal \
  $(MY_MODULE_PATH)/../../../dependencies/freetype/include/freetype/internal/services \
  $(MY_MODULE_PATH)/../../../dependencies/freetype/src/winfonts \
  $(MY_MODULE_PATH)/../../../dependencies/libRocket/Include \
  $(MY_MODULE_PATH)/../../../dependencies/libRocket/Include/Rocket \
  $(MY_MODULE_PATH)/../../../dependencies/libRocket/Include/Rocket/Controls \
  $(MY_MODULE_PATH)/../../../dependencies/libRocket/Include/Rocket/Core \
  $(MY_MODULE_PATH)/../../../dependencies/libRocket/Include/Rocket/Core/Python \
  $(MY_MODULE_PATH)/../../../dependencies/libRocket/Include/Rocket/Debugger \
  $(MY_MODULE_PATH)/../../../dependencies/libRocket/Source/Controls \
  $(MY_MODULE_PATH)/../../../dependencies/libRocket/Source/Core \
  $(MY_MODULE_PATH)/../../../gucefCORE/include \
  $(MY_MODULE_PATH)/../../../gucefCORE/include/android \
  $(MY_MODULE_PATH)/../../../gucefGUI/include \
  $(MY_MODULE_PATH)/../../../gucefIMAGE/include \
  $(MY_MODULE_PATH)/../../../gucefINPUT/include \
  $(MY_MODULE_PATH)/../../../gucefMT/include \
  $(MY_MODULE_PATH)/../../../gucefVFS/include \
  $(MY_MODULE_PATH)/../guidriverRocket/include

LOCAL_CFLAGS := -DGUIDRIVERROCKETGL_BUILD_MODULE


LOCAL_SHARED_LIBRARIES := \
  RocketControls \
  RocketCore \
  gucefCORE \
  gucefGUI \
  gucefMT \
  guidriverRocket


LOCAL_LDLIBS := \
  -lEGL \
  -lGLESv1_CM

include $(BUILD_SHARED_LIBRARY)

