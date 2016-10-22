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
    /*JNIEXPORT void JNICALL Java_org_oxygine_charboost_CharboostAdapter_YOUR_FUNC_NAME(JNIEnv* env, jobject obj, jstring json_data, jboolean error)
    {
        string data = jniGetString(env, json_data);

        core::getMainThreadDispatcher().postCallback([ = ]()
        {
            //call internal function there from src/charboost/charboost.h
            charboost::internal::callItFromNativeCallback();
        });
    }*/


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
