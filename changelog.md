# Changelog

- 2-7-14:
- Prepared for release:
  - Fixed a few warnings/errors
  - Redid the makefile to work in ANY directory.
  - Removed needless Entity.cpp class inside src/ which was there for no particular reason.
- 3-7-14:
  - Fixed filepaths containing '\' by replacing all '\' to '/'
  - Updated SDL from 2.0.1 to 2.0.3
  - Added launch message. Engine.h -> "virtual void LaunchMessage()"
  - Added version control Globals.h --> "Global::ENGINE_VERSION" type std::string
  - Added basic timer class
 - 4-7-14
  - Alpha 0.02
  - Implemented LinkedLists (TODO: Fix deletion, improve and add better iteration)
  - Changed compilation to C++ 14. (-std=C++1y)
  - Added a pointless linkedlist example to TestEntity.cpp DefaultProperties

  