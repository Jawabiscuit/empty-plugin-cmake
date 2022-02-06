# empty_plugin_cmake Package

A [rez](https://github.com/nerdvegas/rez) package that contains source code for an empty "hello world" style Maya C++ plugin.

This package can be used as an example or a template for what is minimally needed to build a Maya C++ plugin on any platform. All that is needed for more complex plugins are potentially slight modifications to the `CMakeLists.txt`, or `CMakeSettings.json`, and of course your source files.


## Structure

- package root
  - maya/plug-ins (install target)
  - src
    - CMakeLists.txt (C++ project config)
    - CMakeSettings.json (C++ build and install config)
    - *.cpp
    - *.h
  - CMakeLists.txt (rez install config)
  - package.py (rez package config)


## Dependencies

1. `Maya 2020`+ - The Maya executable should be on the `PATH` or, even better, `MAYA_LOCATION` can be set to the installation directory. Note, **not** the `bin` directory. Even if those aren't set, it's still possible for cmake to find Maya.

2. `FindMaya.cmake` preferably the module found in [vfxcmake](https://github.com/Jawabiscuit/vfxcmake/blob/master/cmake/FindMaya.cmake)

That file must be on the `CMAKE_MODULE_PATH`, so either clone that package or copy the file and put it somewhere where cmake can find it.

3. `Ninja` - The CMake project uses the `ninja` generator which, compared to msvc generators, keeps project files down to a minimum and it is very fast.

4. `rez` - While not a strict dependency, it is the preferred way of installing the package so that it may be loaded into any environment easily. If `rez` is not used, it's up to you to place the `.mll`, that is installed into the project, somewhere Maya will find it, i.e. Maya's `MAYA_PLUG_IN_PATH`. 


## Building

Building is untested on platforms other than Windows but the recommended `FindMaya.cmake` should enable building on other platforms. Help with testing and feedback is welcome!

__Windows__

The TLDR? If you know what you're doing, open a shell configured with the dependencies, `cd` to the `src` dir, generate, build, and install with cmake!

Otherwise, I recommend using features in Visual Studio IDE to configure, generate, build, and install using cmake for more of a beginner-friendly experience. The package should be ready to build if you have the aformentioned dependencies just by opening the `src` folder up in Visual Studio (File->Open->Folder or File->Open->CMake), right-click `CMakeLists.txt`, and build. Install with the `CMakeLists.txt` right-click install menu.

More info here: [CMake projects in Visual Studio](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-150)


## Building the Rez Package

Building the rez package is straight-forward if you have `rez`.

`rez build -i`

Release, if want to simulate releasing to a production environment, with...

`rez release`


## Misc

Since this project was configured using Visual Studio, it's good to know the CMakeSettings.json file name has changed in more recent versions.

[CMakeSettings.json reference](https://docs.microsoft.com/en-us/cpp/build/cmakesettings-reference?view=msvc-150)

[CMakeSettings.json will be replaced by CMakePresets.json](https://github.com/boostorg/gil/issues/598)

