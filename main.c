﻿#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){

    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    stat("test1", &stat1);
   // printf("#inod: %d\n",(int)stat1.st_ino);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    stat("test2", &stat2);
  //  printf("#inod: %d\n",(int)stat2.st_ino);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    time1 = localtime(&stat1.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    time2 = localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    int size1 = 0; int size2 = 0;
    size1 = (int)stat1.st_size;
    size2 = (int)stat2.st_size;

    printf("size compare\n");
    if (size1 > size2) {
        printf("test1 is bigger\n\n");
    }
    else if (size1 < size2) {
        printf("test2 is bigger\n\n");
    }
    else {
        printf("sizes are equal\n\n");
    }
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    printf("blcok compare\n");

    int size1, size2;
    size1 = (int)stat1.st_blksize;
    size2 = (int)stat2.st_blksize;

    if (size1 > size2) {
        printf("test1 is bigger\n");
    }
    else if (size1 < size2) {
        printf("test2 is bigger\n");
    }
    else {
        printf("sizes are equal\n");
    }
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    time1 = localtime(&stat1.st_mtime);
    time2 = localtime(&stat2.st_mtime);

    printf("data compare\n");
    if ((time1->tm_mon + 1) != (time2->tm_mon + 1)) {
        if ((time1->tm_mon + 1) > (time2->tm_mon + 1)) {
            printf("test1 is early\n\n");
        }
        else {
            printf("test2 is early\n\n");
        }

    }
    else {
        if ((time1->tm_mday) > (time2->tm_mday)) {
            printf("test1 is early\n\n");
        }
        else if ((time1->tm_mday) < (time2->tm_mday)) {
            printf("test2 is early\n\n");
        }
        else {
            printf("same time\n\n");
        }
    }
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    printf("time compare\n");
    if (&stat1.st_mtime > & stat2.st_mtime)
        printf("text1 is early\n");
    else if (&stat1.st_mtime < &stat2.st_mtime)
        printf("text2 is early\n");
    else
        printf("same time");
}
