# Binc

Binary clock written in C.

## Build from Source

External Dependencies:

### Linux

```console
$ cc -o nob nob.c # ONLY ONCE!!!
$ ./nob
$ ./build/binc
```

### Cross Compilation from Linux to Windows using MinGW-w64

Install [MinGW-w64](https://www.mingw-w64.org/) from your distro repository.

Edit `./build/config.h` and set `MUSIALIZER_TARGET` to `TARGET_WIN64_MINGW`.

```console
$ ./nob
$ wine ./build/musializer.exe
```
