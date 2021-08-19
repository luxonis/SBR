# SBR library
Library to manage sections of binary data.

## Description
SBR or Section Boot Record is a simple MBR like structure which organizes sections of data in an binary image

Its 512 long bytes and resides at the beginning of the image.

### Entries
Entries are composed of following fields:
 - Name - name of the section
 - Size - size of data inside section, unit: bytes
 - Offset - number of bytes from beggining of the image to the start of the section
 - Checksum - checksum useful for OTA updates of specific sections
 - Type - TBD: most likely to mark the type of data that resides inside the section
 - Flags - Bootable, ignore checksum, compression, ...

## Utility

Check [sbr-util](examples/sbr-util/README.md) example, for an utility program

To build, add the following CMake define: `-D SBR_BUILD_EXAMPLES=ON`

## Building

### Requirements
 - CMake > 3.2
 - C/C++ Compiler (MSVC, GCC, Clang)

### Steps
```
cmake -H. -Bbuild
cmake --build build
```
