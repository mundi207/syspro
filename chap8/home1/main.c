#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
#include<string.h>

int main(int argc, char **argv) {
	extern char **environ;

	if(argc < 2) { // 예외처리
		fprintf(stderr, "How to use : %s\n", argv[0]);
		exit(1);
	}
	if((strcmp(argv[1], "-e")) == 0) {
		if(argv[2] != NULL) { // 환경변수를 지정했다면
			char *output = getenv(argv[2]);
			if(output != NULL)
				printf("%s\n", output); // 해당 환경변수 출력
			else 
				fprintf(stderr, "존재하지 않음 :%s\n", argv[2]); // 없을 때 예외처리
		}
		else { // 환경변수 지정하지 않았다면
			while(*environ != 0) { // 환경변수 모두 출력
				printf("%s\n", *environ);
				environ ++;
			}
		}
	}
	else if((strcmp(argv[1], "-u")) == 0) { // 사용자 id
		printf("My Realistic ID :%d(%s)\n", getuid(), getpwuid(getuid()) -> pw_name);
		printf("My Valid ID :%d(%s)\n", geteuid(), getpwuid(geteuid()) -> pw_name);
	}
	else if((strcmp(argv[1], "-g")) == 0) { // 그룹 id
		printf("My Realistic Group ID :%d(%s)\n", getgid(), getgrgid(getgid()) -> gr_name);
		printf("My Valid Group ID :%d(%s)\n", getegid(), getgrgid(getegid()) -> gr_name);
	}
	else if((strcmp(argv[1], "-i")) == 0) { // 프로세스 번호
		printf("My Process Number :%d\n", getpid());
	}
	else if((strcmp(argv[1], "-p")) == 0) { // 부모 프로세스 번호 
		printf("My parent's process Number :%d\n", getppid());
	}

	exit(0);
}


