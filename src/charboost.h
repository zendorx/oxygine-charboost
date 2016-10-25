#pragma once

#include "EventDispatcher.h"
#include "Event.h"
#include "json/json.h"
#include <string>
#include <list>

using namespace std;
using namespace oxygine;

namespace charboost
{

    void init();
    void free();

	const static int AD_INTER = 1;
	const static int AD_REWARDED = 2;
	const static int AD_MOREAPPS = 3;
	
	const static int ADA_LOADED = 10;
	const static int ADA_FAILED = 11;
	const static int ADA_SHOWED = 12;
	const static int ADA_CLOSED = 13;

    class OnChangeEvent : public Event
    {
    public:
        enum { EVENT = sysEventID('C', 'B', 'E')};
        OnChangeEvent(const string& location, int adType, int adAction) :
			Event(EVENT), 
			adAction(adAction), 
			adType(adType),
			location(location) {};

        int adType = 0;
        int adAction = 0;
		string location;
    };

    spEventDispatcher dispatcher();

    void showInterstitial(const string& location);
    void showRewardedVideo(const string& location);
    void showMoreApps(const string& location);

    bool isInterstitialLoaded(const string& location);
    bool isRewardedVideoLoaded(const string& location);
    bool isMoreAppsLoaded(const string& location);

    void cacheInterstitial(const string& location);
    void cacheRewardedVideo(const string& location);
    void cacheMoreApps(const string& location);


    namespace internal
    {
        void onChanged(const string& location, int adType, int newStatus);
    }
};