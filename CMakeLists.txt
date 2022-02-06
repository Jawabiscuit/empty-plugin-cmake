cmake_minimum_required(VERSION 2.8)

include(RezBuild)

file(GLOB_RECURSE plugin_files "maya/*.mll")
rez_install_files(
    ${plugin_files}
    DESTINATION .
)
