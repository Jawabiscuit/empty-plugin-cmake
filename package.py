# -*- coding: utf-8 -*-

name = "empty_plugin_cmake"

description = "Hello world Maya C++ plugin using the cmake build generator"

version = "0.1.0"

requires = [
    "platform-windows",
    "~maya-2020",
]

private_build_requires = [
    "msvc-14.16",
]

uuid = "example-maya-plugins.empty_plugin_cmake"


def commands():
    import os

    env.MAYA_PLUG_IN_PATH.append(os.path.join("{root}", "maya", "plug-ins", "x64-Debug"))
    env.MAYA_PLUG_IN_PATH.append(os.path.join("{root}", "maya", "plug-ins", "x64-Release"))
