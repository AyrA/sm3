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

## Building

    gcc main.c -o main.exe

## License

See LICENSE file
