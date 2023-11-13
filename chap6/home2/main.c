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
void InodeprintStat(char*, char*, struct stat*);
void op_PprintStat(char*, char*, struct stat*);
void op_QprintStat(char*, char*, struct stat*);

int main(int argc, char *argv[]) {
	DIR *dp;
	char *dir;
	struct dirent *d;
	struct stat st;
	char path[BUFSIZ + 1];

	dir = ".";

	if((dp = opendir(dir)) < 0) {
		perror(dir);
		exit(1);
	}
	while((d = readdir(dp)) != NULL) {
		sprintf(path, "%s/%s", dir, d -> d_name);
		if((lstat(path, &st)) < 0) {
			perror(path);
		}
		else if(argc >= 2) {
			if((strcmp(argv[1], "-i")) == 0) {
				InodeprintStat(path, d -> d_name, &st);
			}
			else if((strcmp(argv[1], "-p")) == 0) {
				op_PprintStat(path, d -> d_name, &st);
			}
			else {
				op_QprintStat(path, d -> d_name, &st);
			}
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
	printf("%5ld ", st -> st_blocks);
	printf("%c%s ", type(st -> st_mode), perm(st -> st_mode));
	printf("%3d ", st -> st_nlink);
	printf("%s %s ", getpwuid(st -> st_uid) -> pw_name, getgrgid(st -> st_uid) -> gr_name);
	printf("%9ld ", st -> st_size);
	printf("%.12s ", ctime(&st -> st_mtime) + 4);
	printf("%s\n", file);
}
void InodeprintStat(char *pathname, char *file, struct stat *st) {
	printf("%5ld ", st -> st_blocks);
	printf("%5ld ", st -> st_ino);
	printf("%c%s ", type(st -> st_mode), perm(st -> st_mode));
	printf("%3d ", st -> st_nlink);
	printf("%s %s ", getpwuid(st -> st_uid) -> pw_name, getgrgid(st -> st_uid) -> gr_name);
	printf("%9ld ", st -> st_size);
	printf("%.12s ", ctime(&st -> st_mtime) + 4);
	printf("%s\n", file);
}
void op_PprintStat(char *pathname, char *file, struct stat *st) {
	printf("%5ld ", st -> st_blocks);
	printf("%c%s ", type(st -> st_mode), perm(st -> st_mode));
	printf("%3d ", st -> st_nlink);
	printf("%s %s ", getpwuid(st -> st_uid) -> pw_name, getgrgid(st -> st_uid) -> gr_name);
	printf("%9ld ", st -> st_size);
	printf("%.12s ", ctime(&st -> st_mtime) + 4);
	printf("%s/\n", file);
}
void op_QprintStat(char *pathname, char *file, struct stat *st) {
	printf("%5ld ", st -> st_blocks);
	printf("%c%s ", type(st -> st_mode), perm(st -> st_mode));
	printf("%3d ", st -> st_nlink);
	printf("%s %s ", getpwuid(st -> st_uid) -> pw_name, getgrgid(st -> st_uid) -> gr_name);
	printf("%9ld ", st -> st_size);
	printf("%.12s ", ctime(&st -> st_mtime) + 4);
	printf("\"%s\"\n", file);
}

