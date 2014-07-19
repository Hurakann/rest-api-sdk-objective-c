rest-api-sdk-objective-c
=================

Hover API Rest SDK for iOS bindings 

Welcome to the Hover SDK for Objective-C, this SDK is for building a robust Objective-C application based on the Hover API.
The Hover SDK for Objective-C makes it easy to integrate a full Hover API services into Objective-C apps.

Static Library
============

This contains the project of static library to communicate with hover API. Also in *include* folder are compiled files generated by running the static library. The folder contains the library (*libSDK_API_REST.a*) and headers (*.h files*) according to what you require (ios simulator or ios device): 

  * Debug-iphoneos
  * Debug-iphoneSimulator 
  * Debug-universal

Also contains *Configuration.plist* file. You need when implement a static library in your project.

Json Model
============

This project use JsonModel to make automatically introspects model classes and the structure of JSON input and reduces drastically the amount of code. You can find this library [here](https://github.com/icanzilb/JSONModel)

Run static library
============

We need now to build **.a** file (compiled library file). We must compile for ios device and for ios simulator (i386 arch)
 * Select SDK_API_REST > iOs Device and Build (⌘ + B)
 * Select SDK_API_REST > iPhone 7.1 Simulator and Build (⌘ + B)

> Note: This project contains a .a file and headers in the *include* folder.

Get library compiled
====================

Localize headers and **.a** file, it can be two methods:

* **Method A.** If you'd like use *.a* generated when run static library project.

   1. Expand Products in File Browser view
   2. Select libMyStaticLibrary.a
   3. Right Button > Show in Finder
   4. Move up in directory
   
   You must have this hierarchy:
      * Products/Debug-iphoneos/libSDK_API_REST.a
      * Products/Debug-iphonesimulator/libSDK_API_REST.a 

* **Method B.** Use contents of *include* folder, this folders contains headers and library compiled (*.h and .a files*).

  * Products/Debug-iphoneos/libSDK_API_REST.a
  * Products/Debug-iphonesimulator/libSDK_API_REST.a
  * Products/Debug-universal/libSDK_API_REST.a

  Open your project with finder and create a directory with *include* name. This folder will be contain the library (libSDK_API_REST.a) and headers inside a folder (SDK_API_REST) like this hierarchy :

	* include
	    * SDK_API_REST
	        * headers files (.h)
	    * libSDK_API_REST.a

Instalation
===========

1. Add library to your project.

  1. Click on the project root node in the project navigator, and select the project name target. 
     * Select _Build Settings_, and locate the _Header Search Paths_ setting in the list. You can type "header search”  in the search box to filter the big list of settings if necessary.
     * Double click on the _Header Search Paths_ item, and a popover will appear. Click the + button, and enter the following: __$SOURCE_ROOT/include__.
  2. Return to the build settings. 
     * Select the Build Phases tab and expand the _Link Binary With Libraries_ section. 
     * Click the + button in that section. click on the _Add Other_ button and locate the __libSDK_API_REST.a__ library file in the lib subdirectory inside the project’s root folder.
  3. Click on the _Build Settings_ tab, and locate the _Other linker Flags_ setting.
     * Click on the + button and type __-ObjC__.

2. Drag **Configuration.plist** to your project. In this file you must provide the basic datas to SDK:
	
	* **proxyURL**: server IP.
	* **port**: port to IP.
	* **timeOut**: range time to make petition.
	* **readTimeOut**: when connection is sucessful, range time to read response.
 	

And finally you'll have installed SDK for hover API !

Manage the request
==================

 All requests to the RESTful API on the SDK are made using a serialized class, so, each request has their own translation from json to class, for example: to register a single user use User class and its attributes instead build a json file.

Manage the response
===================

All responses from the RESTful API on the SDK are managed by Response class, this class stores the HTTP Status Code, the raw response (json, xml, etc ...) as a string and the body response casted to a desired class. For example if you register a user, then your response instance stores the serialized object, just provide the class to map: 

```objectivec
User *userInfo = [[User alloc] initWithDictionary:response.bodyResponseT];
```
SDK samples
===========
Under test directory exists a bunchet of code snippets that allow testing diferent scenarios and shows you how to use the API with the SDK.

Registering a user
------------------
Shows how to register an user using the default fields and extending of your own user settings

Getting user info
-----------------
Shows how to get information about the registered user

Login
-----
Shows how to login an user using username, password, nfc and/or fingerprint

Assign services to the user
---------------------------
Shows how to assign services to the user

Get services for the user
-------------------------
Shows how to get services assigned to the user

Searching an user
-----------------
Shows how to search a user using default fields or customizing settings
