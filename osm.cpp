#include <iostream>
#include "osm.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>


#define SEC_TO_MICRO 1000000
#define MICRO_TO_NANO 1000

#define DEFAULT_ITER 1000


int osm_init(){
    return 0;
}

int osm_finalizer(){
    return 0;
}
void michalIsTheQueen(){ return;}

double osm_function_time(unsigned int iterations){
    struct timeval tv;

    time_t curtimesec, curtimemicro;
    iterations = (iterations == 0) ? DEFAULT_ITER : iterations;

    if (gettimeofday(&tv, NULL) == -1) {
        return -1;
    }
    curtimesec = tv.tv_sec;
    curtimemicro = tv.tv_usec;

    for (unsigned int i=0;  i<iterations ; i+=5) {
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
    }
    if (gettimeofday(&tv, NULL) == -1) {
        return -1;
    }
    curtimesec = tv.tv_sec - curtimesec;
    curtimemicro = tv.tv_usec - curtimemicro;
    long to_micro = curtimesec * SEC_TO_MICRO;
    long to_nano = (to_micro + curtimemicro) * MICRO_TO_NANO;
    double res = (to_nano / (double)iterations)*5;
    return res;
    //return (double)((curtimesec * SEC_TO_MICRO + curtimemicro) * MICRO_TO_NANO / iterations);
}

double osm_syscall_time(unsigned int iterations){
    struct timeval tv;

    time_t curtimesec, curtimemicro;
    iterations = (iterations == 0) ? DEFAULT_ITER : iterations;

    if (gettimeofday(&tv, NULL) == -1) {
        return -1;
    }
    curtimesec = tv.tv_sec;
    curtimemicro = tv.tv_usec;

    for (unsigned int i=0;  i<iterations ; i+=5) {
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;

    }
    if (gettimeofday(&tv, NULL) == -1) {
        return -1;
    }
    curtimesec = tv.tv_sec - curtimesec;
    curtimemicro = tv.tv_usec - curtimemicro;
    long to_micro = curtimesec * SEC_TO_MICRO;
    long to_nano = (to_micro + curtimemicro) * MICRO_TO_NANO;
    double res = (to_nano / (double)iterations)*5;
    return res;
    //return (double)((curtimesec * SEC_TO_MICRO + curtimemicro) * MICRO_TO_NANO / iterations);
}

double osm_operation_time(unsigned int iterations){
    struct timeval tv;

    time_t curtimesec, curtimemicro;
    iterations = (iterations == 0) ? DEFAULT_ITER : iterations;

    if (gettimeofday(&tv, NULL) == -1) {
     return -1;
    }
    curtimesec = tv.tv_sec;
    curtimemicro = tv.tv_usec;

    int num;
    // in case number of iteration is lower then 5 we will still run the command 5 times.
    for (unsigned int i=0;  i<iterations ; i+=5) {
        num = 1+0;
        num = 1+0;
        num = 1+0;
        num = 1+0;
        num = 1+0;
    }

    // for the warning part in the makefile
    if(num){}

    if (gettimeofday(&tv, NULL) == -1) {
        return -1;
    }
//    printf("yaron: %ld,%ld\n", tv.tv_usec,curtimemicro);
    curtimesec = tv.tv_sec - curtimesec;
    curtimemicro = tv.tv_usec - curtimemicro;
    long to_micro = curtimesec * SEC_TO_MICRO;
    long to_nano = (to_micro + curtimemicro) * MICRO_TO_NANO;
    double res = (to_nano / (double)iterations)*5;
//    printf("to_mic: %lu, to_nano: %lu, res: %f\n", to_micro, to_nano, res);
    return res;

}

int main(int args, char* argv[]) {
    unsigned long number;
    std::string numbuf;
    std::cin >> numbuf;
    number = strtoul(numbuf.c_str(), 0, 10);
//    double temo = osm_operation_time(number);
//    printf("op: %lf\n",temo );
//    printf("func: %lf\n", osm_function_time(number));
//    printf("sys: %lf\n", osm_syscall_time(number));
    std::cout << "op\n"<<osm_operation_time(number)<<"\n";
    std::cout << "func\n"<<osm_function_time(number)<<"\n";
    std::cout << "sys\n"<<osm_syscall_time(number)<<"\n";

    return 0;
}