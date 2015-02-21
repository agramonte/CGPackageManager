/*
 * android-specific implementation of the CGPackageManager extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "CGPackageManager_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_getInstallerPackageName;

s3eResult CGPackageManagerInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("CGPackageManager");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_getInstallerPackageName = env->GetMethodID(cls, "getInstallerPackageName", "()Ljava/lang/String;");
    if (!g_getInstallerPackageName)
        goto fail;

    IwTrace(CGPACKAGEMANAGER, ("CGPACKAGEMANAGER init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(CGPackageManager, ("One or more java methods could not be found"));
    }

    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);
    return S3E_RESULT_ERROR;

}

void CGPackageManagerTerminate_platform()
{ 
    // Add any platform-specific termination code here
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->DeleteGlobalRef(g_Obj);
    g_Obj = NULL;
}

const char* getInstallerPackageName_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring returnString = (jstring)env->CallObjectMethod(g_Obj, g_getInstallerPackageName);
    
    if (returnString == NULL) {
        return NULL;
    }
    
    return env->GetStringUTFChars(returnString, NULL);
}
