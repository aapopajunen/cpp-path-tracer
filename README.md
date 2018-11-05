# cpp-path-tracer
A simple c++ path tracer.


Required installations

GLEW, OpenGL 3.0+, GLFW3


Compilation

Run cmake by navigating into the build directory. Type "cmake .." or run runCMake.sh. Then type "make" inside build directory.


Usage

Inside "build" directory run simplePathTracer. The program should open a window with a view of Susanne. You can move
in the 3D-world with WASD and SPACE / LEFT SHIFT. Camera pointing by cursor is going to implemented later.


## Windows development environment setup

### 1. Installing tools

You will need three tools to build the program **CMake**, **Make** and **MinGW-w64**

- [CMake](https://cmake.org/)\
    direct download:
    https://cmake.org/files/v3.13/cmake-3.13.0-rc2-win64-x64.msi

- [Make](http://gnuwin32.sourceforge.net/packages/make.htm)\
    direct dowload:
    http://gnuwin32.sourceforge.net/downlinks/make.php

- [MinGW-w64](https://mingw-w64.org/doku.php)\
    direct download:
    http://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download

### 2. Add the installed binaries to path
Default paths are:
```
C:\Program Files\CMake\bin;
C:\Program Files (x86)\GnuWin32\bin;
C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin;
```

After you've added them to path, check that the tools are working properly by running in the cmd:\
```cmake```\
```make```\
```gcc```

Each of the the commands should print something else than:\
 ```'command' is not reecognized as an internal or external command, operable program or batch file.```
### 3. Setting up GLFW and GLEW
Files you will need https://drive.google.com/open?id=1JwgpC7YV8ELuLEtArZXcK1IuQXu6795F

#### Copy include and lib files
Directory ```C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64``` will be refered as ```mingw64```.

From the provided files copy contents of include directory into ```mingw64\inculde```\
Form the provided files copy contents of lib directory into ```mingw64\lib```

#### Copy findglfw3.cmake to CMakeModules directory
From the provided files copy ```findglfw3.cmake``` into ```C:\Program Files\CMake\share\cmake-3.13\Modules```

#### Copy .dll files
From the provided files copy contents of dll files directory into project's build directory.

## Example setup for Windows using [Visual Studio Code](https://code.visualstudio.com/)
By now you should have completed the steps in section **Windows development environment setup**.

### Install extensions
You will need three extensions for development using VSCode, **C/C++**, **CMake**, **CMake Tools**. CMake and CMake Tools are not mandatory but highly recommended.

You can search and install the extension by pressing ```ctrl+shift+x```. Relaunch VSCode to activate extensions.

### Configuring CMake using CMake Tools extension
1. Bring up command palette by pressing ```ctrl+p```.
2. Search for "CMake: Scan for Kits" and choose it. CMake will now scan for different build options.
3. Search for "CMake: Select a Kit" and choose it. Now select GCC 8.1.0. (If you can't see it in the options, you propably haven't setup MinGW-w64 properly. Check **Windows development environment setup** section 2 and go back to step 2)
4. Search for "Cmake: Configure" and choose it. CMake will now configure your project into build directory.

To reconfigure, search for "Clean reconfigure".

### Building the project
Open up command palette and search for "CMake: Build" and choose it. It will now build the executable in the build directory.

To rebuild the project, search for "CMake: Clean rebuild".

#### Alternatively
After CMake has configured the project you should be able to build the project with make.
```
cd build
make
```

After that you should be able to run the generated executable see a beautiful path tracing application.