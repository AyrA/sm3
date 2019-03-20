#ifndef MAIN_H
#define MAIN_H

//Standard includes
#include <stdio.h>

//Local includes
#include "sm3.h"

//Input buffer; 8192 is usual stdin buffer size
#define BUFSIZE (1024*8)

//Line break character
#define LF "\n"

//Argument for calling help is different on linux and windows
#ifdef __linux__
	#define HELP_ARG "--help"
#elif _WIN32
	#define HELP_ARG "/?"
#else
	#error HELP_ARG not declared for your architecture
#endif

//Help text shown for help argument
#define HELP_TEXT \
	"sm3.exe [content]"LF\
	"Hashes data using the SM3 algorithm. Application version 2.0"LF\
	LF\
	"content  - If supplied, the given value is hashed"LF\
	"           If absent, command line input is used instead"

//Writes a hash to the console as hexadecimal
void dumpHash(const unsigned char*);
//Hashes a given string
void processString(const char*,const int);
//Hashes standard input
void processStdin();
#endif
