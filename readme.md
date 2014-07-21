# CPP-2D-Engine
## Current Version: Alpha 0.05
A work in development, to say the least.

Compile using the GNU Compiler Collection (GCC) or CodeBlocks.

### DLL Dependencies:
- glew32.dll
- libFLAC-8.dll
- libfreetype-6.dll
- libgcc_s_dw2-1.dll
- libjpeg-9.dll
- libmodplug-1.dll
- libogg-0.dll
- libpng16-16.dll
- libstdc++-6.dll
- libtiff-5.dll
- libvorbis-0.dll
- libvorbisfile-3.dll
- libwebp-4.dll
- SDL2.dll
- SDL2_image.dll
- SDL2_mixer.dll
- SDL2_ttf.dll
- smpeg2.dll
- zlib1.dll

  
## Commandlines for compilation:
### Windows:
	mingw32-make -f *PATH TO MAKEFILE*
### Linux:
	make -f *PATH TO MAKEFILE*

### TODO (Non-exhaustive list):
- Engine (Major and Significant):
  - Engine.cpp: Platform independent basepath location.
  - Engine.cpp: ADD FPS AND DELTATIME!
  - Engine.cpp: Fix Tick. (Make it an ACTUAL tick rather than being called when render is) {TICK IS A LIE}
  - Engine.cpp: Implement pausing
  - Entity.h: Properly implement Entity:IDCount
  - Globals.h: Add GUI support
  - Globals.h: Make more utility functions
  - Globals.h: Make some sort of API documentation
  - Globals.h: 64 bit
  - Globals.h: Add Linux compatibility
  - Globals.h: Get rid of inconsistencies between char* and std::string, surely the latter is better.
  - Globals.h: BORING: Deal with licensing
  - LinkedList.h: Create proper iteration in contrast to lambda functions.
  - LinkedList.h: i>length check should not be necessary? (But apparently it is)
  - LinkedList.h: Figure out why an extra ->next is required.
  - RendererBase.cpp: Improve this
  - RendererBase.cpp: Improve this
  - RendererDirect3D.cpp: Complete the Direct3D renderer.
  - RendererOpenGL.cpp: Fix the OpenGL renderer to work with images
  - RendererSDL.h: make SDL_RendererFlip and SDL_Colour my own type to avoid SDL.h inclusion in RendererBase?
  - SoundManager.cpp: Implement an entire resource manager which encapsulated the soundmanager and renderer.
  - SoundManager.cpp: MP3s with SDL Mixer MUST be of a bitrate of 256kbps and 44100Hz sample rate. (Fix this is possible?)
  - SoundManager.cpp: Add validation to PlaySound()
  - Sprite.cpp: Shorten or Clean Collision Perhaps. Use an external handler?
  - Sprite.cpp: Implement Box/Sphere AND per pixel collision detection.
  - Sprite.h: Implement this in a useful way
- Game (Minor and virtually pointless:
  - Player.cpp: Fix stutter caused by Vector2 and Vector2f conversion
  - Player.cpp: Resolve -position issue.


### Changelog
- 2-7-14:
- Prepared for release:
  - Fixed a few warnings/errors
  - Redid the makefile to work in ANY directory.
  - Removed needless Entity.cpp class inside src/ which was there for no particular reason.
- 3-7-14:
  - Created THIS changelog.
  - Fixed filepaths containing '\' by replacing all '\' to '/'
  - Updated SDL from 2.0.1 to 2.0.3
  - Added launch message. Engine.h -> "virtual void LaunchMessage()"
  - Added version control Globals.h --> "Global::ENGINE_VERSION" type std::string
  - Added basic timer class
 - 4-7-14
  - Version -> Alpha 0.02
  - Implemented LinkedLists (TODO: Fix deletion, improve and add better iteration)
  - Changed compilation to C++ 14. (-std=C++1y)
  - Added a pointless linkedlist example to TestEntity.cpp DefaultProperties
- 5-7-14
  - Added SDL_ttf. (Yay more dependencies)
    - libfreetype-6.dll
	- SDL2_ttf.dll
  - Added some minor TODOs.
  - Version -> Alpha 0.03
  - RendererBase.cpp/RendererBase.h:
    - Added: Vector2 LocalToWorldVector(Vector2 in)
    - Added: Vector2 WorldToLocalVector(Vector2 in)
	- Self-explanatory, really.
- 6-7-14
  - Version -> Alpha 0.035
  - Made SetRenderView(int x, int y); set the view at the CENTRE of the screen
  - Added -Vector2 and -Vector2f operators.
  - Found the cause of the jitter. Remember to use .ToInteger() with Vectors. Vector -> FloatVector conversions need to be improved.
- 7-7-14
  - Version -> Alpha 0.04
  - Implemented SDL_mixer (badly?)
  - Fixed font directory finding by making it use a base directory of the executable folder. (Only works in windows) (Bye bye multiple OS support for a while.)
- 8-7-14
  - Version -> Alpha 0.045
  - Fixed vector magnitude functions. (Thanks Coi!)
  - Fixed LinkedList deletion!
- 9-7-14 / 10-7-14
  - Version -> Alpha 0.05
  - Added readme generation (python3) (23:59)
  - Moved SDL_mixer out of RendererBase class. (0:30)
  - Added lots of TODOS (1:05)
