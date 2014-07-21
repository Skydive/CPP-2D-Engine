# CPP-2D-Engine
## Current Version: Alpha 0.045
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
  - Platform independent basepath location.
  - ADD FPS AND DELTATIME!
  - GET KEY
  - FIX THIS. Why doesn't it work!?
  - Why do an extra next. Why on earth does this work!?
  - Improve this
  - Improve this
  - make SDL_RendererFlip my own type?
  - Add validation
  - Shorten or Clean Collision Perhaps. Use an external handler?
  - Implement Box/Sphere AND per pixel collision detection.
- Game (Minor and virtually pointless:
  - Create a Sprite class. (Useful for image property handling and collision detection).
  - Fix stutter caused by Vector2 and Vector2f conversion
  - Resolve this.


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
