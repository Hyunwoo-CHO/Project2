#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

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
    char* filename1 = "text1.txt";
    stat(filename1, &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    char* filename2 = "text2.txt";
    stat(filename2, &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
	localtime_r(&stat1.st_mtime, time1);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
        localtime_r(&stat2.st_mtime, time2);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
	printf("size compare\n");
	int size_stat1, size_stat2;
	size_stat1=(int)stat1.st_size;
	size_stat2=(int)stat2.st_size;

	if(size_stat1==size_stat2){
		printf("sizes are equal\n");
	}
	else if(size_stat1>>size_stat2){
		printf("text1 is bigger\n");
	}
	else{
		printf("text2 is bigger\n");
	}
	printf("\n");
    
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
	printf("block compare\n");
	int bsize_stat1, bsize_stat2;
        bsize_stat1=(int)stat1.st_blocks;
        bsize_stat2=(int)stat2.st_blocks;

        if(bsize_stat1==bsize_stat2){
                printf("sizes are equal\n");
        }
        else if(bsize_stat1>>bsize_stat2){
                printf("text1 is bigger\n");
        }
        else{
                printf("text2 is bigger\n");
        }
        printf("\n");

}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
	printf("%d, %d, %d, %d\n",time1->tm_hour, time1->tm_min, time2->tm_hour, time2->tm_min);	
	
	
	printf("date compare\n");
	int date_month_stat1, date_month_stat2;
	int date_day_stat1, date_day_stat2;
        
	date_month_stat1=time1->tm_mon+1;
        date_month_stat2=time2->tm_mon+1;
	
	date_day_stat1=time1->tm_mday;
	date_day_stat2=time2->tm_mday;

        if(date_month_stat1==date_month_stat2){
               	if(date_day_stat1==date_day_stat2){
			printf("same date\n");
		}
		else if(date_day_stat1<date_day_stat2){
			printf("text1 is early\n");
		}
		else{
			printf("text2 is early\n");
		}
        }
        else if(date_month_stat1<date_month_stat2){
                printf("text1 is early\n");
        }
        else{
                printf("text2 is early\n");
        }
        printf("\n");    
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    
}
