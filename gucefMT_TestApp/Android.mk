#-------------------------------------------------------------------
# This file has been automatically generated by ProjectGenerator    
# which is part of a build system designed for GUCEF                
#     (Galaxy Unlimited Framework)                                  
# For the latest info, see http://www.VanvelzenSoftware.com/        
#                                                                   
# The contents of this file are placed in the public domain. Feel   
# free to make use of it in any way you like.                       
#-------------------------------------------------------------------


LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := gucefMT_TestApp

LOCAL_SRC_FILES := \
  $(LOCAL_PATH)/src/gucefMT_TestApp.cpp

LOCAL_C_INCLUDES := \
  $(LOCAL_PATH)/../gucefMT/include


LOCAL_SHARED_LIBRARIES := \
  gucefMT

include $(BUILD_EXECUTABLE)

