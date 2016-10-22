#pragma once

#include <string>

using namespace std;

void jniCharboostInit();
void jniCharboostFree();

void jniShowInterstitial(const string& location);
void jniShowRewardedVideo(const string& location);
void jniShowMoreApps(const string& location);

bool jniIsInterstitialLoaded(const string& location);
bool jniIsRewardedVideoLoaded(const string& location);
bool jniIsMoreAppsLoaded(const string& location);

void jniCacheInterstitial(const string& location);
void jniCacheRewardedVideo(const string& location);
void jniCacheMoreApps(const string& location);