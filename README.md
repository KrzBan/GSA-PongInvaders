# GSA-PongInvaders
GSA project, Pong x Invaders Fusion.

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
You will be asked for root CMakeLists.txt. Choose "PongInvaders/CmakeLists.txt"
TODO: get rid of this point

4. Once open, you can force CMake to run by simply saving any CMakeLists.txt file.
To do so, open any CMakeLists.txt (preferably root one) and press Ctrl+S.
In console output, you will see vcpkg being ran, installing all dependencies.

5. Run PongInvaders.exe and enjoy!

