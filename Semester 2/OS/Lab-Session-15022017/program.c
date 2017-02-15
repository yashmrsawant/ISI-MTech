#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void solution3();
void solution4();
void solution5();
void solution6();

int main(int argc, char** argv) {
	
	//solution3();
	//solution4();
	//solution5();
	solution6();
	return 0;
}
void solution3() {
	int pid_i = fork();
	const char* path = "/bin/ls";
	char* const arguments[] = {"/bin/ls", NULL};
	if(pid_i == 0) {
		//Child
		execv(path, arguments);
		exit(pid_i);
	} else {
		if(pid_i != -1) {
			printf("%d\n", pid_i);
		}
	}
}
void solution4() {
	int parent_pid = getpid();
	int pid_i = fork();
	int i;
	for(i = 0; i < 9 ; i ++) {
		
		if(pid_i == 0) {
			break;
		} else {
			if(pid_i != -1) {
					pid_i = fork();
			} else {
				exit(-1);
			}
		}
	}
	if((pid_i = getpid()) != parent_pid) {
		printf("PID %d\n", pid_i);
	}
}

void solution5() {
	int pid_i;
	
	printf("Hello World");
	fflush(stdout);
	fork();
}
void solution6() {
	/**
	* When a parent process forks n children, and waits for these n
	*	children to terminate, in what order are the zombie children cleaned
	*	up: based on the order in which they were created, or based on the
	*	order in which they terminate? Write a program to empirically find
	*	the answer to this question.
	**/
	int n;
	scanf("%d", &n);
	printf("%d\n", getpid());
	int i = 0, status;
	int pid_i = fork();
	for(; i < n - 1; i ++) {
		if(pid_i == 0) {
			sleep(n - i);
			exit(getpid());
		} else {
			if(pid_i != -1) {
				pid_i = fork();
				printf("%d\n", pid_i);
			} else {
				exit(-1);
			}
		}
	}
	while(-- n) {
		if((pid_i = wait(&status)) != -1) {
			printf("%d %d\n", pid_i, status);
		} else {
			printf("%d", getpid());
			break;
		}
	}
}