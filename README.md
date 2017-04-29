# clixel

Prototyping game engine for the Universal Windows Platform derived from Flixel

## Project Setup Notes on UWA Initial Project

* App: Has basic system linkages, nothing useful

* App1Main:
** Root of the actual app implementation
** Owns the resource synchronizing critical section (for some reason)
** Has a render loop worker where update and render are performed
** Is the object that gets notified of device loss

* DirectXPage:
** Has the XAML view layout with the DirectX and XAML layers
** Created by the App component, implements the root of the app
** Has Window related changes: vis, dpi, orientation, size, etc.
** Input worker is created here and the callbacks route through the page's member functions
** Creates and owns the device resources, updates it on Window change events

## Major TODOs

* Loading screen to present while all game assets are loaded into memory since the scripting language doesn't have a good context of async other than frame by frame checks for completion
* UI: XAML vs some form of immediate mode? Looks like we should be able to get away with some form of XAML mapping
* Build clixel as a lib separate from the UWA host 