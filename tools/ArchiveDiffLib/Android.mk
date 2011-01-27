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

LOCAL_MODULE := ArchiveDiffLib

LOCAL_SRC_FILES := \
  $(LOCAL_PATH)/src/ArchiveDiffLib.cpp

LOCAL_C_INCLUDES := \
  $(LOCAL_PATH)/include \
  $(LOCAL_PATH)/../../gucefCOM/include \
  $(LOCAL_PATH)/../../gucefCOMCORE/include \
  $(LOCAL_PATH)/../../gucefCORE/include \
  $(LOCAL_PATH)/../../gucefMT/include \
  $(LOCAL_PATH)/../../gucefPATCHER/include


LOCAL_SHARED_LIBRARIES := \
  gucefCORE \
  gucefMT \
  gucefPATCHER

include $(BUILD_SHARED_LIBRARY)

