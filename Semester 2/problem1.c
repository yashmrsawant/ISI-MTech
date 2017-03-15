#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <pthread.h>

struct thread_info {
	pthread_t thread_id;
	unsigned int thread_number;
	unsigned long int offset;
	FILE* file_read;
	FILE* file_write;
	unsigned long int chunk_size;
}

int main(int argc, char** argv) {

	unsigned int size = 0;
	char ch;
	struct stat buf_v;
	struct thread_info* threads;
	FILE* fp;
	if(argc != 5) {
		printf("Usage : ./a.out -t <number_of_threads>	...\n");
		exit(-1);
	}
	// Getting the number of lines in the source file.
	fp = fopen(argv[3], "r");
	if(fp != NULL) {
		stat(argv[3], &buf_v);
		size = buf_v.st_size;
		while((opt = getopt(argc, argv, "t:")) != -1) {
			switch(opt) {
				case 't' :
						thread_num = strtoul(optarg, NULL, 0);
                   break;
				default :
					exit(EXIT_FAILURE);
			}
		}
		chunk_size = size / thread_num;
		threads = calloc(thread_num, sizeof(struct thread_info));
		for(i = 0 ; i < thread_num ; i++) {
			
		}
	}
	return 0;
}
static void* copy_thread(void *arg) {
	struct thread_info *tinfo = arg;
   	int* udarg = (int *)(malloc(sizeof(int)));
	int i = 0;
	char* ch = (char *)
					(malloc(sizeof(char) * tinfo -> chunk_size));
	fseek(tinfo -> file_read, tinfo -> thread_number * tinfo -> offset, 
			SEEK_SET);
	fread(ch, tinfo -> chunk_size, 1, tinfo -> file_read);
   	
	fseek(tinfo -> file_write, tinfo -> thread_number * tinfo -> offset,
			SEEK_SET);
	fwrite(ch, tinfo -> chunk_size, 1, tinfo -> file_write);
	*udarg = strlen(ch);
   	return udargv;
}
