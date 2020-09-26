#include <stdio.h>
#include <sys/time.h>

long long getmSecs(){
	struct timeval time;
	gettimeofday(&time,NULL);
	long long ms=((long long) time.tv_sec*1000)+((long long)time.tv_usec/1000);
	return ms;
}