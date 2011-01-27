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

LOCAL_MODULE := gucefPATCHER

LOCAL_SRC_FILES := \
  $(LOCAL_PATH)/src/gucefPATCHER.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CModule.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchConfig.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchEngine.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchListEngine.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchListEngineEvents.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchListParser.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchManager.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchSetDirEngine.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchSetDirEngineEvents.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchSetEngine.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchSetEngineEvents.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchSetFileEngine.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchSetFileEngineEvents.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchSetGenerator.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchSetParser.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchTaskConsumer.cpp \
  $(LOCAL_PATH)/src/gucefPATCHER_CPatchTaskData.cpp

LOCAL_C_INCLUDES := \
  $(LOCAL_PATH)/include \
  $(LOCAL_PATH)/../gucefCOM/include \
  $(LOCAL_PATH)/../gucefCOMCORE/include \
  $(LOCAL_PATH)/../gucefCORE/include \
  $(LOCAL_PATH)/../gucefMT/include


LOCAL_SHARED_LIBRARIES := \
  gucefCOM \
  gucefCOMCORE \
  gucefCORE \
  gucefMT

include $(BUILD_SHARED_LIBRARY)

