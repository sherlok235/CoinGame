# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev/proj.linux

# Utility rule file for SYNC_RESOURCE-TestDev.

# Include the progress variables for this target.
include CMakeFiles/SYNC_RESOURCE-TestDev.dir/progress.make

CMakeFiles/SYNC_RESOURCE-TestDev:
	/usr/bin/cmake -E echo Copying\ resources\ for\ TestDev\ ...

SYNC_RESOURCE-TestDev: CMakeFiles/SYNC_RESOURCE-TestDev
SYNC_RESOURCE-TestDev: CMakeFiles/SYNC_RESOURCE-TestDev.dir/build.make
	/usr/bin/cmake -E echo \ \ \ \ copying\ to\ /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev/proj.linux/bin/TestDev/Resources
	/usr/bin/python2 /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev/cocos2d/cmake/scripts/sync_folder.py -s /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev/Resources -d /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev/proj.linux/bin/TestDev/Resources
.PHONY : SYNC_RESOURCE-TestDev

# Rule to build all files generated by this target.
CMakeFiles/SYNC_RESOURCE-TestDev.dir/build: SYNC_RESOURCE-TestDev

.PHONY : CMakeFiles/SYNC_RESOURCE-TestDev.dir/build

CMakeFiles/SYNC_RESOURCE-TestDev.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SYNC_RESOURCE-TestDev.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SYNC_RESOURCE-TestDev.dir/clean

CMakeFiles/SYNC_RESOURCE-TestDev.dir/depend:
	cd /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev/proj.linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev/proj.linux /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev/proj.linux /home/teo/Documents/code/C++/COCO/cocos2d-x-4.0/build/TestDev/proj.linux/CMakeFiles/SYNC_RESOURCE-TestDev.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SYNC_RESOURCE-TestDev.dir/depend

