# SM3

SM3 Algorithm implementation for piping content on the command line.

This is a stripped down version from [zhao07](https://github.com/zhao07/libsm3),
made to work on windows.

# Algorithm

See [The SM3 Cryptographic Hash Function draft-oscca-cfrg-sm3-01](https://tools.ietf.org/id/draft-oscca-cfrg-sm3-01.html)

## Usage

Hashing a file

	SM3.exe < SomeFile

Hashing command output

	SomeCommand | SM3.exe

Hashing a string

	SM3.exe "Test String"

## Building

This project is written in Dev-C++,
the easiest way of building is opening it there and build from the menu.

Manually building is possible after editing the makefile with the correct paths,
then using the command below.

	mingw32-make.exe -f Makefile.win clean all

You likely have to edit the inclusion paths for the libraries to match your system first.

To manually build from scratch:

	::Main function
	gcc.exe -c main.c -o main.o
	::SM3 Library
	gcc.exe -c sm3.c -o sm3.o
	::Properties file
	windres.exe -i SM3_private.rc -F pe-i386 --input-format=rc -o SM3_private.res -O coff
	::Build executable
	gcc.exe main.o sm3.o SM3_private.res -o SM3.exe -static-libgcc -s

## License

Licensed under the MIT license

See LICENSE file for details
