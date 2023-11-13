#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>
#include<stdlib.h>
#include<string.h>

char type(mode_t);
char* perm(mode_t);
void printStat(char*, char*, struct stat*);

int main(int argc, char *argv[]) {
	DIR *dp; // 디렉터리를 가리키는 포인터
	char *dir; // 경로 문자열로 받음
	struct stat st;
	struct dirent *d; // readdir 반환값 -> 구조체포인터
	char path[BUFSIZ + 1]; 

	if(argc == 1) {
		dir = ".";
	}
	else {
		dir = argv[1];
	}
	if((dp = opendir(dir)) < 0) {
		perror(dir);
		exit(1);
	}
	while((d = readdir(dp)) > 0) {
		sprintf(path, "%s/%s", dir, d -> d_name); // path에 경로저장
		if((lstat(path, &st)) < 0) {
			perror(path);
		}
		else {
			printStat(path, d -> d_name, &st);
		}
	}
	closedir(dp);
	exit(0);
}
char type(mode_t mode) {
	if(S_ISREG(mode)) {
		return '-';
	}
	if(S_ISDIR(mode)) {
		return 'd';
	}
	if(S_ISCHR(mode)) {
		return 'c';
	}
	if(S_ISBLK(mode)) {
		return 'b';
	}
	if(S_ISLNK(mode)) {
		return 'l';
	}
	if(S_ISFIFO(mode)) {
		return 'p';
	}
	if(S_ISSOCK(mode)) {
		return 's';
	}
}
char* perm(mode_t mode) {
	static char perms[10];
	strcpy(perms, "---------");

	for(int i = 0; i < 3; i ++) {
		if(mode & (S_IRUSR >> i * 3)) {
			perms[i * 3] = 'r';
		}
		if(mode & (S_IWUSR >> i * 3)) {
			perms[i * 3 + 1] = 'w';
		}
		if(mode & (S_IXUSR >> i * 3)) {
			perms[i * 3 + 2] = 'x';
		}
	}
	return perms;
}
void printStat(char *pathname, char *file, struct stat *st) {
	printf("%5d ", st -> st_blocks);
	printf("%c%s ", type(st -> st_mode), perm(st -> st_mode));
	printf("%3d ", st -> st_nlink);
	printf("%s %s ", getpwuid(st -> st_uid) -> pw_name, getgrgid(st -> st_uid) -> gr_name);
	printf("%9d ", st -> st_size);
	printf("%.12s ", ctime(&st -> st_mtime) + 4);
	printf("%s\n" , file);
}
	

