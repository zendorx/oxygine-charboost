#include "charboost.h"

#ifdef __ANDROID__
    #include "android/AndroidCharboost.h"
#elif __APPLE__
    #include <TargetConditionals.h>
    #include "ios/iosCharboost.h"
#else
    #include "sim/CharboostSimulator.h"
#endif



#define CHARBOOST_EXT_ENABLED 1

namespace charboost
{

    spEventDispatcher _dispatcher;

    spEventDispatcher dispatcher()
    {
        return _dispatcher;
    }

    void init()
    {
#if !CHARBOOST_EXT_ENABLED
        return;
#endif

        log::messageln("charboost::init");

        OX_ASSERT(_dispatcher == 0);
        _dispatcher = new EventDispatcher;

#ifdef __ANDROID__
        jniCharboostInit();
#elif TARGET_OS_IPHONE

#else
        charboostSimulatorInit();
#endif
        log::messageln("charboost::init done");
    }

    void free()
    {
#if !CHARBOOST_EXT_ENABLED
        return;
#endif

        log::messageln("charboost::free");

        OX_ASSERT(_dispatcher);

#ifdef __ANDROID__
        jniCharboostFree();
#endif
        _dispatcher->removeAllEventListeners();
        _dispatcher = 0;
        log::messageln("charboost::free done");
    }

    /*void doSomething()
    {
#ifdef __ANDROID__
        jniDoSomethingInJava();
#elif TARGET_OS_IPHONE
        jniDoSomethingInObjectiveC();
#else
        simulatorFunction();
#endif
        
    }*/


    namespace internal
    {

        /*void callItFromNativeCallback()
        {
            YourEventExample ev;
            _dispatcher->dispatchEvent(&ev);
        }*/
    }
}

