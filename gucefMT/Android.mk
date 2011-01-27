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

LOCAL_MODULE := gucefMT

LOCAL_SRC_FILES := \
  $(LOCAL_PATH)/src/gucefMT.cpp \
  $(LOCAL_PATH)/src/gucefMT_CActiveObject.cpp \
  $(LOCAL_PATH)/src/gucefMT_CCondition.cpp \
  $(LOCAL_PATH)/src/gucefMT_CCriticalSection.cpp \
  $(LOCAL_PATH)/src/gucefMT_CGUCEFMTModule.cpp \
  $(LOCAL_PATH)/src/gucefMT_CICloneable.cpp \
  $(LOCAL_PATH)/src/gucefMT_CMutex.cpp \
  $(LOCAL_PATH)/src/gucefMT_CReadWriteLock.cpp \
  $(LOCAL_PATH)/src/gucefMT_CScopeMutex.cpp \
  $(LOCAL_PATH)/src/gucefMT_CSemaphore.cpp \
  $(LOCAL_PATH)/src/gucefMT_CTMailBox.cpp \
  $(LOCAL_PATH)/src/gucefMT_dvmtoswrap.c \
  $(LOCAL_PATH)/src/gucefMT_DVRWLOCK.c \
  $(LOCAL_PATH)/src/gucefMT_MUTEX.c

LOCAL_C_INCLUDES := \
  $(LOCAL_PATH)/include


LOCAL_LDLIBS := \
  -l${PLATFORM_LIBS}

include $(BUILD_SHARED_LIBRARY)

