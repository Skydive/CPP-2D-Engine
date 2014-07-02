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
  
### Commandline for compilation:
	mingw32-make -f *PATH TO MAKEFILE*

### TODO (Non-exhaustive list):
- Fix the OpenGL renderer
- Improve collision
- Make more utility functions
- Use a linked list to house the entities for faster iteration
- Make a linked list class for the linked list to house the entities.
- Fix Tick. (Make it an ACTUAL tick rather than being called when render is) {TICK IS A LIE}
