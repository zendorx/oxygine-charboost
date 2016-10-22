package org.oxygine.charboost;

import android.app.Activity;
import android.content.Intent;
import android.util.Log;

import com.chartboost.sdk.Chartboost;
import com.chartboost.sdk.ChartboostDelegate;
import com.chartboost.sdk.Model.CBError;

import org.oxygine.lib.extension.ActivityObserver;

public class CharboostAdapter extends ActivityObserver
{
    private static String TAG = "CharboostAdapter";
    private Activity _activity;

    final int AD_INTER = 1;
    final int AD_REWARDED = 2;
    final int AD_MOREAPPS = 3;

    final int ADA_LOADED = 10;
    final int ADA_FAILED = 11;
    final int ADA_SHOWED = 12;
    final int ADA_CLOSED = 13;

    public static native void onChaned(String locatiom, int adType, int newStatus);

    public CharboostAdapter(Activity a, final String APP_ID, final String APP_SIG) {
        Log.i(TAG, "CharboostAdapter");

        _activity = a;

        Chartboost.startWithAppId(_activity, APP_ID, APP_SIG);
        Chartboost.setDelegate(cbDelegateObject);
        Chartboost.onCreate(_activity);


    }

    void showInterstitial(final String location)
    {
        Log.i(TAG, "showInterstitial");
        _activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Chartboost.showInterstitial(location);
            }
        });
    }

    void showRewardedVideo(final String location)
    {
        Log.i(TAG, "showRewardedVideo");
        _activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Chartboost.showRewardedVideo(location);
            }
        });
    }

    void showMoreApps(final String location)
    {
        Log.i(TAG, "showMoreApps");
        _activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Chartboost.showMoreApps(location);
            }
        });
    }

    boolean isInterstitialLoaded(final String location)
    {
        Log.i(TAG, "isInterstitialLoaded");
        return Chartboost.hasInterstitial(location);
    }

    boolean isRewardedVideoLoaded(final String location)
    {
        Log.i(TAG, "isRewardedVideoLoaded");
        return Chartboost.hasRewardedVideo(location);
    }

    boolean isMoreAppsLoaded(final String location)
    {
        Log.i(TAG, "isMoreAppsLoaded");
        return Chartboost.hasMoreApps(location);
    }

    void cacheInterstitial(final String location)
    {
        Log.i(TAG, "cacheInterstitial");
        _activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Chartboost.cacheInterstitial(location);
            }
        });
    }

    void cacheRewardedVideo(final String location)
    {
        Log.i(TAG, "cacheRewardedVideo");
        _activity.runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                Chartboost.cacheRewardedVideo(location);
            }
        });
    }

    void cacheMoreApps(final String location)
    {
        Log.i(TAG, "cacheMoreApps");
        _activity.runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                Chartboost.cacheMoreApps(location);
            }
        });
    }

    @Override
    public void onStart()
    {
        Chartboost.onStart(_activity);
    }

    @Override
    public void onStop()
    {
        Chartboost.onStop(_activity);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {

    }

    @Override
    public void onDestroy()
    {
        Chartboost.onDestroy(_activity);
    }

    @Override
    public void onResume()
    {
        Chartboost.onResume(_activity);
    }

    @Override
    public void onPause() {
        Chartboost.onPause(_activity);
    }

    @Override
    public boolean onBackPressed() {

        // If an interstitial is on screen, close it. Otherwise continue as normal.
        if (Chartboost.onBackPressed())
            return false;

        return true;
    }


    /* DELEGATE METHODS */

    private ChartboostDelegate cbDelegateObject = new ChartboostDelegate() {

        //Interstitial
        @Override
        public void didDisplayInterstitial(String location)
        {
            Log.i(TAG, "didDisplayInterstitial");
            onChaned(location, AD_INTER, ADA_SHOWED);
        }

        @Override
        public void didCacheInterstitial(String location)
        {
            Log.i(TAG, "didCacheInterstitial");
            onChaned(location, AD_INTER, ADA_LOADED);
        }

        @Override
        public void didFailToLoadInterstitial(String location, CBError.CBImpressionError error)
        {
            Log.i(TAG, "didFailToLoadInterstitial");
            onChaned(location, AD_INTER, ADA_FAILED);
        }

        @Override
        public void didCloseInterstitial(String location)
        {
            Log.i(TAG, "didCloseInterstitial");
            onChaned(location, AD_INTER, ADA_CLOSED);
        }

        //MOREAPPS
        @Override
        public void didDisplayMoreApps(String location)
        {
            Log.i(TAG, "didDisplayMoreApps");
            onChaned(location, AD_MOREAPPS, ADA_SHOWED);
        }

        @Override
        public void didCacheMoreApps(String location)
        {
            Log.i(TAG, "didCacheMoreApps");
            onChaned(location, AD_MOREAPPS, ADA_LOADED);
        }

        @Override
        public void didCloseMoreApps(String location)
        {
            Log.i(TAG, "didCloseMoreApps");
            onChaned(location, AD_MOREAPPS, ADA_CLOSED);
        }

        @Override
        public void didFailToLoadMoreApps(String location, CBError.CBImpressionError error)
        {
            Log.i(TAG, "didFailToLoadMoreApps");
            onChaned(location, AD_MOREAPPS, ADA_FAILED);
        }


        //REWARDED VIDEO

        // Called after a rewarded video has been loaded from the Chartboost API
// servers and cached locally.
        public void didCacheRewardedVideo(String location)
        {
            Log.i(TAG, "didCacheRewardedVideo");
            onChaned(location, AD_REWARDED, ADA_LOADED);
        }

        // Called after a rewarded video has attempted to load from the Chartboost API
// servers but failed.
        public void didFailToLoadRewardedVideo(String location, CBError.CBImpressionError error)
        {
            Log.i(TAG, "didFailToLoadRewardedVideo");
            onChaned(location, AD_REWARDED, ADA_FAILED);
        }

        // Called after a rewarded video has been closed.
        public void didCloseRewardedVideo(String location)
        {
            Log.i(TAG, "didCloseRewardedVideo");
            onChaned(location, AD_REWARDED, ADA_CLOSED);
        }

        // Called after a rewarded video has been viewed completely and user is eligible for reward.
        public void didCompleteRewardedVideo(String location, int reward)
        {
            Log.i(TAG, "didCompleteRewardedVideo");
            onChaned(location, AD_REWARDED, ADA_SHOWED);
        }
    };
}