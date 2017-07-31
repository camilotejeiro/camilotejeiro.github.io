---
title: Android Quotes Display Apps v2.1
---

This is a continuation of my 
[previous efforts]({% post_url 2016-01-08-android-quotes-display-apps-v2 %}).

> A quote a day? That would be nice, wouldn't it?

That's what we thought too, and that's why we created these apps.

You can use these _open source_ apps to display personal/book quotes in your
Android device. The quotes are read from text file(s) and displayed (one by one)
in random order at periodic intervals (or on screen-tap).

## Random Quotes App

Application to turn an Android device into a "picture frame" for displaying
quotes.
	
* [Google Play Store Download Link](https://play.google.com/store/apps/details?id=org.osohm.randomquotesapp&hl=en)
	
* [More Details - Source Code](https://github.com/camilotejeiro/android_quotes_display_apps/tree/master/android_gradle/RandomQuotes/RandomQuotesApp)

## Random Quotes Widget

Application to display your quotes in a small widget in the Android device front
screen.
	
* [Google Play Store Download Link](https://play.google.com/store/apps/details?id=org.osohm.randomquoteswidget&hl=en) 

* [More Details - Source Code](https://github.com/camilotejeiro/android_quotes_display_apps/tree/master/android_gradle/RandomQuotes/RandomQuotesWidget)

## Documentation

For documentation and upcoming features, see the 
[user documentation](https://github.com/camilotejeiro/android_quotes_display_apps/blob/master/documentation/user_functional_specification.md).

## Development

All the development was done using
[Gradle](https://en.wikipedia.org/wiki/Gradle) and the android tools directly
from the command line (No bloated IDEs). It's actually pretty straightforward
after you get the hold of it.

[Using gradle to build Android apps from the CLI](https://spring.io/guides/gs/gradle-android)

The Gradle build process mostly involves two commands:
	
* Build Debug:

`gradle assembleDebug`
	
* Build Release (signed apps with your own keys):

`gradle assembleRelease`

Once the application builds you can use the 
[following scripts](https://github.com/camilotejeiro/android_quotes_display_apps/tree/master/android_gradle/bin)
to install and debug your application.

If you need more, you can write your own little scripts, it's actually quite
nice.

## License

These applications were created to meet our needs, we are sharing them under the
assumption that they can provide some value to others, but with no warranties of
any kind; without even the implied warranty of merchantability or fitness for
any particular purpose. See the 
[GPLv3 license file](https://github.com/camilotejeiro/android_quotes_display_apps/blob/master/license.md)
for more details.

{% include issues_comments.md %}
