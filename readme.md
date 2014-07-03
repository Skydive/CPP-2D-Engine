# CPP-2D-Engine

A work in development, to say the least.

Compile using the GNU Compiler Collection (GCC) or CodeBlocks.

### DLL Dependencies:
- OpenGL and SDL:
  - glew32.dll
  - SDL2.dll
  - SDL2_image.dll
- For images and fonts:
  - libjpeg-9.dll
  - libpng16-16.dll
  - libtiff-5.dll
  - libwebp-4.dll
- Weird GCC Dependencies:
  - libgcc_s_dw2-1.dll
  - libstdc++-6.dll
- Is this really a dependency, I'm not sure:
  - zlib1.dll
  
### Commandlines for compilation:
## Windows:
	mingw32-make -f *PATH TO MAKEFILE*
## Linux:
	make -f *PATH TO MAKEFILE*
### TODO (Non-exhaustive list):
- Fix the OpenGL renderer to work with images
- Complete the Direct3D renderer.
- Improve collision
- Make more utility functions
- Use a linked list to house the entities for faster iteration
- Make a linked list class for the linked list to house the entities.
- Fix Tick. (Make it an ACTUAL tick rather than being called when render is) {TICK IS A LIE}
- Make some sort of API documentation
- 64 bit
- Add launch message + version notify
- Code Local/World position converters and rename arguments+variables to avoid confusion.

By Khalid Aleem
(Open source. Do whatever the heck you want with it!)
