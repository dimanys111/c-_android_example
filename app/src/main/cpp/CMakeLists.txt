# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(include_DIRECTORY /home/dima/AndroidStudioProjects/C/app/src/main/cpp/include/webp)

set(webp_DIRECTORY /home/dima/AndroidStudioProjects/C/app/src/main/lib/libwebp.a)
add_library(webp STATIC IMPORTED)
set_property(TARGET webp PROPERTY IMPORTED_LOCATION ${webp_DIRECTORY})


include_directories(${include_DIRECTORY})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
#set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${_FORTIFY_SOURCE_PREFIX}-U_FORTIFY_SOURCE ${_FORTIFY_SOURCE_PREFIX}-D_FORTIFY_SOURCE=1")
#string( REPLACE "-D_FORTIFY_SOURCE=2" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

add_library( # Sets the name of the library.
        my_lib
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        my_lib.h my_lib.cpp )


set(SOURCES native_lib.cpp)
add_library( # Sets the name of the library.
             native-lib
             # Sets the library as a shared library.
             SHARED
             # Provides a relative path to your source file(s).
             ${SOURCES})

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
                        my_lib
                        webp)