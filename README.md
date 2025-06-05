# Needle
Universal threading library

> **NOTE**
> Needle currently only supports Windows and Linux operating systems

## Planned Updates
- Add support for more operating systems (Mac, BSD, etc.)

# How To Compile
## Dependencies
Win32 API for Windows and PThreads for Linux. Both of which should be preinstalled under normal circumstances.

## Compile Instructions
Run the following commands
```
mkdir build
cd build
cmake ../
cmake --build .
```

## Compile Example
Run the following commands
```
mkdir build
cd build
cmake ../
cmake --build . --target increment
```