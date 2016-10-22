#include <jni.h>
#include <android/log.h>
#include <assert.h>
#include "core/oxygine.h"
#include "core/Object.h"
#include "core/ThreadMessages.h"
#include "core/oxygine.h"
#include "core/android/jniHelper.h"
#include "core/android/jniUtils.h"
#include "json/json.h"
#include "src/charboost.h"


using namespace oxygine;

jclass _jCharboostClass = 0;
jobject _jCharboostObject = 0;

bool isCharboostEnabled()
{
    return _jCharboostClass && _jCharboostObject;
}


extern "C"
{
    JNIEXPORT void JNICALL Java_org_oxygine_charboost_CharboostAdapter_onChaned(JNIEnv* env, jobject obj, jstring location, int adType, int newStatus)
    {
        string data = jniGetString(env, json_data);

        core::getMainThreadDispatcher().postCallback([ = ]()
        {
            string loc_s = jniGetString(env, (jstring) location);
            charboost::internal::onChanged(loc_s, adType, newStatus);
        });
    }


}


void jniCharboostInit()
{
    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);
        JNI_NOT_NULL(env);

        _jCharboostClass = env->FindClass("org/oxygine/charboost/CharboostAdapter");
        JNI_NOT_NULL(_jCharboostClass);

        _jCharboostClass = (jclass) env->NewGlobalRef(_jCharboostClass);
        JNI_NOT_NULL(_jCharboostClass);

        _jCharboostObject = env->NewGlobalRef(jniFindExtension(env, _jCharboostClass));
        JNI_NOT_NULL(_jCharboostObject);
    }
    catch (const notFound&)
    {
        log::error("jniCharboostInit failed, class/member not found");
    }
}

void jniCharboostFree()
{
    if (!isCharboostEnabled())
        return;

    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);

        env->DeleteGlobalRef(_jCharboostClass);
        _jCharboostClass = 0;

        env->DeleteGlobalRef(_jCharboostObject);
        _jCharboostObject = 0;
    }
    catch (const notFound&)
    {
        log::error("jniCharboostFree failed, class/member not found");
    }
}


void jniShowInterstitial(const string& location)
{
    if (!isCharboostEnabled())
        return;

    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);
        jstring jlocation = env->NewStringUTF(location.c_str());
        jmethodID jisMethod = env->GetMethodID(_jCharboostClass, "showInterstitial", "()V");
        JNI_NOT_NULL(jisMethod);
        env->CallVoidMethod(_jCharboostObject, jisMethod, jlocation);
    }
    catch (const notFound&)
    {
        log::error("jniShowInterstitial failed, class/member not found");
    }
}

void jniShowRewardedVideo(const string& location)
{
    if (!isCharboostEnabled())
        return;

    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);
        jstring jlocation = env->NewStringUTF(location.c_str());
        jmethodID jisMethod = env->GetMethodID(_jCharboostClass, "showRewardedVideo", "()V");
        JNI_NOT_NULL(jisMethod);
        env->CallVoidMethod(_jCharboostObject, jisMethod, jlocation);
    }
    catch (const notFound&)
    {
        log::error("jniShowRewardedVideo failed, class/member not found");
    }
}

void jniShowMoreApps(const string& location)
{
    if (!isCharboostEnabled())
        return;

    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);
        jstring jlocation = env->NewStringUTF(location.c_str());
        jmethodID jisMethod = env->GetMethodID(_jCharboostClass, "showMoreApps", "()V");
        JNI_NOT_NULL(jisMethod);
        env->CallVoidMethod(_jCharboostObject, jisMethod, jlocation);
    }
    catch (const notFound&)
    {
        log::error("jniShowMoreApps failed, class/member not found");
    }
}


bool jniIsInterstitialLoaded(const string& location)
{
    if (!isCharboostEnabled())
        return false;

    bool result = false;
    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);
        jstring jlocation = env->NewStringUTF(location.c_str());
        jmethodID jisMethod = env->GetMethodID(_jCharboostClass, "isInterstitialLoaded", "()Z");
        JNI_NOT_NULL(jisMethod);
        jboolean jb = env->CallBooleanMethod(_jCharboostObject, jisMethod, jlocation);
        result = (bool) jb;
    }
    catch (const notFound&)
    {
        log::error("jniIsInterstitialLoaded failed, class/member not found");
    }

    return false;
}

bool jniIsRewardedVideoLoaded(const string& location)
{
    if (!isCharboostEnabled())
        return false;

    bool result = false;
    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);
        jstring jlocation = env->NewStringUTF(location.c_str());
        jmethodID jisMethod = env->GetMethodID(_jCharboostClass, "isRewardedVideoLoaded", "()Z");
        JNI_NOT_NULL(jisMethod);
        jboolean jb = env->CallBooleanMethod(_jCharboostObject, jisMethod, jlocation);
        result = (bool) jb;
    }
    catch (const notFound&)
    {
        log::error("jniIsRewardedVideoLoaded failed, class/member not found");
    }


    return false;
}

bool jniIsMoreAppsLoaded(const string& location)
{
    if (!isCharboostEnabled())
        return false;

    bool result = false;
    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);
        jstring jlocation = env->NewStringUTF(location.c_str());
        jmethodID jisMethod = env->GetMethodID(_jCharboostClass, "isMoreAppsLoaded", "()Z");
        JNI_NOT_NULL(jisMethod);
        jboolean jb = env->CallBooleanMethod(_jCharboostObject, jisMethod, jlocation);
        result = (bool) jb;
    }
    catch (const notFound&)
    {
        log::error("jniIsMoreAppsLoaded failed, class/member not found");
    }

    return false;
}


void jniCacheInterstitial(const string& location)
{
    if (!isCharboostEnabled())
        return;

    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);
        jstring jlocation = env->NewStringUTF(location.c_str());
        jmethodID jisMethod = env->GetMethodID(_jCharboostClass, "cacheInterstitial", "()V");
        JNI_NOT_NULL(jisMethod);
        env->CallVoidMethod(_jCharboostObject, jisMethod, jlocation);
    }
    catch (const notFound&)
    {
        log::error("jniCacheInterstitial failed, class/member not found");
    }
}

void jniCacheRewardedVideo(const string& location)
{
    if (!isCharboostEnabled())
        return;

    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);
        jstring jlocation = env->NewStringUTF(location.c_str());
        jmethodID jisMethod = env->GetMethodID(_jCharboostClass, "cacheRewardedVideo", "()V");
        JNI_NOT_NULL(jisMethod);
        env->CallVoidMethod(_jCharboostObject, jisMethod, jlocation);
    }
    catch (const notFound&)
    {
        log::error("jniCacheRewardedVideo failed, class/member not found");
    }
}

void jniCacheMoreApps(const string& location)
{
    if (!isCharboostEnabled())
        return;

    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);
        jstring jlocation = env->NewStringUTF(location.c_str());
        jmethodID jisMethod = env->GetMethodID(_jCharboostClass, "cacheMoreApps", "()V");
        JNI_NOT_NULL(jisMethod);
        env->CallVoidMethod(_jCharboostObject, jisMethod, jlocation);
    }
    catch (const notFound&)
    {
        log::error("jniCacheMoreApps failed, class/member not found");
    }
}



/*
bool jniCharboostSomeBoolFunc()
    {
    if (!isCharboostEnabled())
        return false;

    bool result = false;
    try
    {
        JNIEnv* env = jniGetEnv();
        LOCAL_REF_HOLDER(env);
        //jstring jappLinkUrl = env->NewStringUTF(appLinkUrl.c_str()); //to jstring example
        jmethodID jisMethod = env->GetMethodID(_jCharboostClass, "FUNC_NAME_JAVA", "()Z");
        JNI_NOT_NULL(jisMethod);
        //string data = jniGetString(env, (jstring) obj); //string example
        jboolean jb = env->CallBooleanMethod(_jCharboostObject, jisMethod);
        result = (bool) jb;

    }
    catch (const notFound&)
    {
        log::error("jniCharboostSomeBoolFunc failed, class/member not found");
    }

    return result;
}
*/
