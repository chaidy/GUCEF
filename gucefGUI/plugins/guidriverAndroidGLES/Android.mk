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
LOCAL_MODULE := guidriverAndroidGLES
LOCAL_MODULE_FILENAME := libguidriverAndroidGLES
@echo Module name: $(LOCAL_MODULE)

LOCAL_SRC_FILES := \
  src/guidriverAndroidGLES_CAndroidGLESWindowContext.cpp \
  src/guidriverAndroidGLES_CAndroidWindowManagerImp.cpp \
  src/guidriverAndroidGLES_pluginAPI.cpp

LOCAL_C_INCLUDES := \
  $(MY_MODULE_PATH)/include \
  $(MY_MODULE_PATH)/../../../common/include \
  $(MY_MODULE_PATH)/../../../gucefCORE/include \
  $(MY_MODULE_PATH)/../../../gucefCORE/include/android \
  $(MY_MODULE_PATH)/../../../gucefGUI/include \
  $(MY_MODULE_PATH)/../../../gucefIMAGE/include \
  $(MY_MODULE_PATH)/../../../gucefMT/include \
  $(MY_MODULE_PATH)/../../../gucefVFS/include

LOCAL_CFLAGS := -DGUIDRIVERANDROIDGLES_BUILD_MODULE


LOCAL_SHARED_LIBRARIES := \
  gucefCORE \
  gucefGUI \
  gucefMT


LOCAL_STATIC_LIBRARIES := \
  android_native_app_glue


LOCAL_LDLIBS := \
  -lEGL \
  -lGLESv1_CM \
  -landroid

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)
