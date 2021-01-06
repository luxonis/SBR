# sbr-util
Utility to view and manipulate SBR binary images

## Description
SBR or Section Boot Record is a simple MBR like structure which organizes sections of data in an binary image

Its long 512 bytes and resides at the beginning of the image.
### Entries
Entries are composed of following fields:
 - Name - name of the section
 - Size - size of data inside section, unit: bytes
 - Offset - number of bytes from beggining of the image to the start of the section
 - Checksum - checksum useful for OTA updates of specific sections
 - Type - TBD: most likely to mark the type of data that resides inside the section
 - Flags - Bootable, ignore checksum, ...

## Usage

```
./sbr-util path/to/sbr/image
```

### Example

```
./sbr-util my_app.dap 
ID        BR                       
VALID     Name                     Size(B)     Offset      Checksum      Type    Flags   
true      __firmware               14980448    512         0x1C735FE6    0       1       
true      pipeline                 868         15728640    0xA74C03E0    0       0       
true      assets                   43          16777216    0x361B3B02    0       0       
true      asset_storage            14488768    17825792    0x5B3280FC    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
false                              0           0           0x00000000    0       0       
```

## Building
### Requirements
 - CMake > 3.2
 - C/C++ Compiler (MSVC, GCC, Clang) 

### Steps
```
mkdir -p build && cd build
cmake ..
cmake --build . --parallel
```
