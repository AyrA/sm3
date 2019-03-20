#include "main.h"

int main(int argc,char* argv[]){
	if(argc<2){
		processStdin();
	}
	else if(strcmp(argv[1],HELP_ARG)==0){
		puts(
			HELP_TEXT LF
			LF
			LICENSE LF
			LF
			DISCLAIMER);
	}
	else {
		processString(argv[1],strlen(argv[1]));
	}
	return 0;
}

void dumpHash(const unsigned char hash[SM3_DIGEST_LENGTH]){
	//Dump hexadecimal hash
	for (int i=0;i<SM3_DIGEST_LENGTH;i++)
	{
    	printf("%02X",hash[i]);
	}
	//Print Newline
	puts("");
}

void processString(const char* str,const int length){
	//Output hash
	unsigned char result[SM3_DIGEST_LENGTH];
	//Hash function context
	sm3_ctx_t ctx;

	//Compute SM3
	sm3_init(&ctx);
	sm3_update(&ctx,str,length);
	sm3_final(&ctx,result);
	//Done
	dumpHash(result);
}

void processStdin(){
	//Input buffer
	unsigned char buffer[BUFSIZE];
	//Output hash
	unsigned char result[SM3_DIGEST_LENGTH];
	//Hash function context
	sm3_ctx_t ctx;

	//Initialize SM3
	sm3_init(&ctx);

	//Open stdin in binary mode if running windows
	#if _WIN32
	freopen(NULL,"rb",stdin);
	#endif

	//Pipe input to hash function
	while(!feof(stdin)){
		sm3_update(&ctx,buffer,fread(buffer,1,BUFSIZE,stdin));
	}
	//Done
	sm3_final(&ctx,result);
	dumpHash(result);
}

