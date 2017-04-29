# clixel

Prototyping game engine for the Universal Windows Platform derived from Flixel

## Project Setup Notes on UWA Initial Project

https://docs.microsoft.com/en-us/windows/uwp/gaming/tutorial--create-your-first-metro-style-directx-game

## Major TODOs

* Loading screen to present while all game assets are loaded into memory since the scripting language doesn't have a good context of async other than frame by frame checks for completion
* UI: XAML vs some form of immediate mode? Looks like we should be able to get away with some form of XAML mapping
* Build clixel as a lib separate from the UWA host 