#include <stdio.h>

#include "sm3.c"

#define BUFSIZE (2048)

int main(){
	int i;
	//Input buffer
	unsigned char buffer[BUFSIZE];
	//Output hash
	unsigned char result[SM3_DIGEST_LENGTH];
	//Hash function context
	sm3_ctx_t ctx;

	//Initialize SM3
	sm3_init(&ctx);
	
	//Open stdin in binary mode
	freopen(NULL, "rb", stdin);
	
	//Pipe input to hash function
	while(!feof(stdin)){
		sm3_update(&ctx, buffer,fread(buffer,1,BUFSIZE,stdin));
	}
	//Done
	sm3_final(&ctx, result);
	//Dump hexadecimal hash
	for (i = 0; i < SM3_DIGEST_LENGTH; i++)
	{
    	printf("%02X", result[i]);
	}
	//Print Newline
	puts("");
}

