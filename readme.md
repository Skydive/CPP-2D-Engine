# CPP-2D-Engine
## Current Version: Alpha 0.02
A work in development, to say the least.

Compile using the GNU Compiler Collection (GCC) or CodeBlocks.

### DLL Dependencies:
- OpenGL and SDL:
  - glew32.dll
  - SDL2.dll
  - SDL2_image.dll
  - SDL2_ttf.dll
- For images and fonts:
  - libjpeg-9.dll
  - libpng16-16.dll
  - libtiff-5.dll
  - libwebp-4.dll
  - libfreetype-6.dll
- Weird GCC Dependencies:
  - libgcc_s_dw2-1.dll
  - libstdc++-6.dll
- Is this really a dependency, I'm not sure:
  - zlib1.dll
  
## Commandlines for compilation:
### Windows:
	mingw32-make -f *PATH TO MAKEFILE*
### Linux:
	make -f *PATH TO MAKEFILE*
	
### TODO (Non-exhaustive list):
- ~~Add launch message + version notify~~ (3-7-2014)
- ~~Use a linked list to house the entities for faster insertion~~ (4-7-2014)
- ~~Make a linked list class for the linked list to house the entities.~~ (4-7-2014)
- ~~Add SDL TTF support~~ (5-7-2014)
- ~~Code Local/World position converters and rename arguments+variables to avoid confusion.~~ (5-7-2014)
- Fix the OpenGL renderer to work with images
- Complete the Direct3D renderer.
- Improve collision
- Make more utility functions
- Fix Tick. (Make it an ACTUAL tick rather than being called when render is) {TICK IS A LIE}
- Add FPS counter
- Add GUI support
- Make some sort of API documentation
- 64 bit
- Fix the cause of the render jitter when dealing with coordinate translations.
  - Renderer->SetRenderView(Vector2((-position.x)+(CentrePosition.x-(dimensions.x/2)), (-position.y)+(CentrePosition.y-(dimensions.y/2))));
  - Might be to do with int->float conversion.
- Make coordinate render view setting a lot easier.
- Add a negate operator to -vector2 and -vector2f.
- Add SDL Mixer support
- Add Linux compatability
- Fix deletion, improve and add better iteration to LinkedLists
- Get rid of inconsistencies between char* and std::string, surely the latter is better.
- Fix font directory finding. Should be local with debugger.
- Deal with licencing
By Khalid Aleem
(Open source. Do whatever the heck you want with it!)
