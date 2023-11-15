# GSA-PongInvaders
GSA project, Pong x Invaders Fusion.

Pong
Game Clocks (timeSinceStart, deltaTime)
Player Input, Second Player Input
AI movement - X
Ball physics (World bounce, Paddle bounce) - X
Music, game sound effects - X
Main Menu ( Play/Quit, Solo/2Player )
Score ( file I/O )

Scene abstraction
Camera abstraction
Game Fail State
Intro 



# Prerequisites
- git
- Visual Studio 22 with C++ Package Installed

If you don't want to install Visual Studio 22 you'll also need:
- Cmake
- Ninja
- Your favorite compiler
- Additional configuration preset in CmakePresets.txt

# How to install
1. Clone repo with submodule using: 
git clone https://github.com/KrzBan/GSA-PongInvaders --recurse-submodules

If you only want to only update submodules, run:
git submodule update --init

2. Go to "vcpkg" directory and run "bootstrap-vcpkg.bat" (or .sh on Linux)

3. Open Visual Studio with "GSA-PongInvaders" directory as root.

4. Once open, you can force CMake to run by simply saving any CMakeLists.txt file.
To do so, open any CMakeLists.txt (preferably root one) and press Ctrl+S.
In console output, you will see vcpkg being ran, installing all dependencies.

5. Run PongInvaders.exe and enjoy!

