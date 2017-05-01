# clixel

Prototyping game engine for the Universal Windows Platform derived from Flixel

## Project Setup Notes on UWA Initial Project

https://docs.microsoft.com/en-us/windows/uwp/gaming/tutorial--create-your-first-metro-style-directx-game

## Major TODOs

* Loading screen to present while all game assets are loaded into memory since the scripting language doesn't have a good context of async other than frame by frame checks for completion
* UI: XAML vs some form of immediate mode? Looks like we should be able to get away with some form of XAML mapping
* Build clixel as a lib separate from the UWA host 
* Objects that need to be inheritted from: FlxState, FlxSprite, others?

## Design

Four projects: 
* uwahost: Native host that implements rendering, input gathering, asset loading, etc.
* clixel: Game engine itself with native dependencies injected by uwahost
* scrpt: Scripting language project with just the compiler and virtual machine
* game: Actual game project. Implements linkages between clixel and scrpt and triggers the runtime.

Startup:
* uwahost gets started up by the system, creates the native abstraction object, and 'new's up the Game with the abstraction bits
* Game inherits from ClxGame and specifies the initial state
* Game starts loading everything while uwahost displays a static loading screen
* Once done, uwahost starts invoking Game's update and render calls which in turn invokes the current state's update and render calls which are implemented in scrpt