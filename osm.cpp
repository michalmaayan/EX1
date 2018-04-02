#include <iostream>
#include "osm.h"
#include <sys/time.h>


#define SEC_TO_MICRO 1000000
#define MICRO_TO_NANO 1000
#define DEFAULT_ITER 1000
#define LOOP_ITER 10


int osm_init(){
    return 0;
}

int osm_finalizer(){
    return 0;
}
void michalIsTheQueen(){ }

double osm_function_time(unsigned int iterations){
    struct timeval tv1, tv2;
    time_t curtimesec, curtimemicro;
    iterations = (iterations == 0) ? DEFAULT_ITER : iterations;

    if (gettimeofday(&tv1, nullptr) == -1) {
        return -1;
    }

    for (unsigned int i=0;  i<iterations ; i+=LOOP_ITER) {
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
    }
    if (gettimeofday(&tv2, nullptr) == -1) {
        return -1;
    }
    curtimesec = tv2.tv_sec - tv1.tv_sec;
    curtimemicro = tv2.tv_usec - tv1.tv_usec;


    double to_micro = curtimesec * SEC_TO_MICRO;
    double to_nano = (to_micro + curtimemicro) * MICRO_TO_NANO;
    double res = (to_nano / (double)iterations);
    return res;
}

double osm_syscall_time(unsigned int iterations){
    struct timeval tv1, tv2;

    time_t curtimesec, curtimemicro;
    iterations = (iterations == 0) ? DEFAULT_ITER : iterations;

    if (gettimeofday(&tv1, nullptr) == -1) {
        return -1;
    }

    for (unsigned int i=0;  i<iterations ; i+=LOOP_ITER) {
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
    }
    if (gettimeofday(&tv2, nullptr) == -1) {
        return -1;
    }

    curtimesec = tv2.tv_sec - tv1.tv_sec;
    curtimemicro = tv2.tv_usec - tv1.tv_usec;
    double to_micro = curtimesec * SEC_TO_MICRO;
    double to_nano = (to_micro + curtimemicro) * MICRO_TO_NANO;
    double res = (to_nano / (double)iterations);
    return res;
}

double osm_operation_time(unsigned int iterations){
    struct timeval tv1, tv2;

    time_t curtimesec, curtimemicro;
    iterations = (iterations == 0) ? DEFAULT_ITER : iterations;

    if (gettimeofday(&tv1, nullptr) == -1) {
     return -1;
    }

    int num;
    // in case number of iteration is lower then 5 we will still run the command 5 times.
    for (unsigned int i=0;  i<iterations ; i+=LOOP_ITER) {
        num = 1+0;
        num = 1+0;
        num = 1+0;
        num = 1+0;
        num = 1+0;
        num = 1+0;
        num = 1+0;
        num = 1+0;
        num = 1+0;
        num = 1+0;
    }

    // for the warning part in the makefile
    if(num){}

    if (gettimeofday(&tv2, nullptr) == -1) {
        return -1;
    }

    curtimesec = tv2.tv_sec - tv1.tv_sec;
    curtimemicro = tv2.tv_usec - tv1.tv_usec;
    double to_micro = curtimesec * SEC_TO_MICRO;
    double to_nano = (to_micro + curtimemicro) * MICRO_TO_NANO;
    double res = (to_nano / (double)iterations);
    return res;

}




int main(int args, char* argv[]) {
    std::cout << "op\n"<<osm_operation_time(1000)<<"\n";
    std::cout << "func\n"<<osm_function_time(1000)<<"\n";
    std::cout << "sys\n"<<osm_syscall_time(1000)<<"\n";

    return 0;
}