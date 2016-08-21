//
// Created by chan on 16/8/18.
//
#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include "com_chan_ypatchcore_YPatch.h"
#include "patch/bspatch.h"

char* jstringTostring(JNIEnv* env, jstring jstr)
{
    char* rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0)
    {
        rtn = (char*)malloc(alen + 1);

        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

JNIEXPORT void JNICALL Java_com_chan_ypatchcore_YPatch_patch
        (JNIEnv * env, jclass clazz, jstring oldFile, jstring newFile, jstring patchFile) {

    char* old_file = jstringTostring(env, oldFile);
    char* new_file = jstringTostring(env, newFile);
    char* patch_file = jstringTostring(env, patchFile);

    run_patch(old_file, new_file, patch_file);

    free(old_file);
    free(new_file);
    free(patch_file);
}