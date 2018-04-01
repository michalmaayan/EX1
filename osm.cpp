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
    struct timeval tv1, tv2;
    time_t curtimesec, curtimemicro;
    iterations = (iterations == 0) ? DEFAULT_ITER : iterations;

    if (gettimeofday(&tv1, NULL) == -1) {
        return -1;
    }
//    curtimesec = tv1.tv_sec;
//    curtimemicro = tv1.tv_usec;

    for (unsigned int i=0;  i<iterations ; i+=5) {
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
        michalIsTheQueen();
    }
    if (gettimeofday(&tv2, NULL) == -1) {
        return -1;
    }
    curtimesec = tv2.tv_sec - tv1.tv_sec;
    curtimemicro = tv2.tv_usec - tv1.tv_usec;


    double to_micro = curtimesec * SEC_TO_MICRO;
    double to_nano = (to_micro + curtimemicro) * MICRO_TO_NANO;
    double res = (to_nano / (double)iterations);
    return res;
    //return (double)((curtimesec * SEC_TO_MICRO + curtimemicro) * MICRO_TO_NANO / iterations);
}

double osm_syscall_time(unsigned int iterations){
    struct timeval tv1, tv2;

    time_t curtimesec, curtimemicro;
    iterations = (iterations == 0) ? DEFAULT_ITER : iterations;

    if (gettimeofday(&tv1, NULL) == -1) {
        return -1;
    }
//    curtimesec = tv1.tv_sec;
//    curtimemicro = tv1.tv_usec;

    for (unsigned int i=0;  i<iterations ; i+=5) {
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;
        OSM_NULLSYSCALL ;

    }
    if (gettimeofday(&tv2, NULL) == -1) {
        return -1;
    }
//    curtimesec = tv.tv_sec - curtimesec;
//    curtimemicro = tv.tv_usec - curtimemicro;
    curtimesec = tv2.tv_sec - tv1.tv_sec;
    curtimemicro = tv2.tv_usec - tv1.tv_usec;
    double to_micro = curtimesec * SEC_TO_MICRO;
    double to_nano = (to_micro + curtimemicro) * MICRO_TO_NANO;
    double res = (to_nano / (double)iterations);
    return res;
    //return (double)((curtimesec * SEC_TO_MICRO + curtimemicro) * MICRO_TO_NANO / iterations);
}

double osm_operation_time(unsigned int iterations){
    struct timeval tv1, tv2;

    time_t curtimesec, curtimemicro;
    iterations = (iterations == 0) ? DEFAULT_ITER : iterations;

    if (gettimeofday(&tv1, NULL) == -1) {
     return -1;
    }
//    curtimesec = tv1.tv_sec;
//    curtimemicro = tv1.tv_usec;

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

    if (gettimeofday(&tv2, NULL) == -1) {
        return -1;
    }
//    curtimesec = tv2.tv_sec - curtimesec;
//    curtimemicro = tv2.tv_usec - curtimemicro;
    curtimesec = tv2.tv_sec - tv1.tv_sec;
    curtimemicro = tv2.tv_usec - tv1.tv_usec;
    double to_micro = curtimesec * SEC_TO_MICRO;
    double to_nano = (to_micro + curtimemicro) * MICRO_TO_NANO;
    double res = (to_nano / (double)iterations);
    return res;

}

//#include <iostream>
//#include <sys/time.h>
//#include "osm.h"
//
////--  Constants  --//
//const int UNROLLING_FACTOR = 10;
//const int NUM_OF_ITERS = 1000;
//const double CONVERTER = 1000;
//const double SECOND_CONVERTER = 1000000;
//
//
///* Initialization function that the user must call
// * before running any other library function.
// * The function may, for example, allocate memory or
// * create/open files.
// * Pay attention: this function may be empty for some desings. It's fine
// * Returns 0 uppon success and -1 on failure
// */
//int osm_init(){
//    return 0;
//}
//
//
///* finalizer function that the user must call
// * after running any other library function.
// * The function may, for example, free memory or
// * close/delete files.
// * Returns 0 uppon success and -1 on failure
// */
//int osm_finalizer(){ return 0;}
//
//
///*
// * An empty function.
// */
//void empty_call(){}
//
//
///* Time measurement function for a simple arithmetic operation.
//   returns time in nano-seconds upon success,
//   and -1 upon failure.
//   */
//double osm_operation_time(unsigned int iterations){
//    struct timeval t1, t2;
//    double elapsedTime;
//    int cur_iter = iterations;
//    int a = 0;
//
//    if (iterations == 0){
//        cur_iter = NUM_OF_ITERS;
//    }
//
//    // Get current time of day:
//    if(gettimeofday(&t1, nullptr) == -1){
//        return -1;
//    }
//
//    // Perform arithmetic operations:
//    for(int i = 0; i < cur_iter; i += UNROLLING_FACTOR){
//        a++;
//        a++;
//        a++;
//        a++;
//        a++;
//        a++;
//        a++;
//        a++;
//        a++;
//        a++;
//    }
//
//    // Get current time of day:
//    if (gettimeofday(&t2, nullptr) == -1){
//        return -1;
//    }
//
//    // Calculate the elapsed time:
//    elapsedTime = (t2.tv_sec - t1.tv_sec) * CONVERTER;      // sec to ms
//    elapsedTime += (t2.tv_usec - t1.tv_usec) / CONVERTER;   // us to ms
//    elapsedTime = elapsedTime * SECOND_CONVERTER;
//    return elapsedTime/cur_iter;
//
//}
//
//
///* Time measurement function for an empty function call.
//   returns time in nano-seconds upon success,
//   and -1 upon failure.
//   */
//double osm_function_time(unsigned int iterations){
//    struct timeval t1, t2;
//    double elapsedTime;
//    int cur_iter = iterations;
//
//    if (iterations == 0){
//        cur_iter = NUM_OF_ITERS;
//    }
//    // Get current time of day:
//    if(gettimeofday(&t1, nullptr) == -1){
//        return -1;
//    }
//
//    // Perform function calls:
//    for(int i = 0; i < cur_iter; i += UNROLLING_FACTOR){
//        empty_call();
//        empty_call();
//        empty_call();
//        empty_call();
//        empty_call();
//        empty_call();
//        empty_call();
//        empty_call();
//        empty_call();
//        empty_call();
//    }
//
//    // Get current time of day:
//    if (gettimeofday(&t2, nullptr) == -1){
//        return -1;
//    }
//
//    // Calculate the elapsed time:
//    elapsedTime = (t2.tv_sec - t1.tv_sec) * CONVERTER;      // sec to ms
//    elapsedTime += (t2.tv_usec - t1.tv_usec) / CONVERTER;   // us to ms
//    elapsedTime = elapsedTime * SECOND_CONVERTER;
//
//    return elapsedTime/cur_iter;
//
//}
//
//
///* Time measurement function for an empty trap into the operating system
//   returns time in nano-seconds upon success,
//   and -1 upon failure.
//   */
//double osm_syscall_time(unsigned int iterations){
//    struct timeval t1, t2;
//    double elapsedTime;
//    int cur_iter = iterations;
//
//    if (iterations == 0){
//        cur_iter = NUM_OF_ITERS;
//    }
//
//    // Get current time of day:
//    if(gettimeofday(&t1, nullptr) == -1){
//        return -1;
//    }
//
//    // Perform the system calls:
//    for(int i = 0; i < cur_iter; i += UNROLLING_FACTOR){
//        OSM_NULLSYSCALL;
//        OSM_NULLSYSCALL;
//        OSM_NULLSYSCALL;
//        OSM_NULLSYSCALL;
//        OSM_NULLSYSCALL;
//        OSM_NULLSYSCALL;
//        OSM_NULLSYSCALL;
//        OSM_NULLSYSCALL;
//        OSM_NULLSYSCALL;
//        OSM_NULLSYSCALL;
//    }
//
//    // Get current time of day:
//    if (gettimeofday(&t2, nullptr) == -1){
//        return -1;
//    }
//
//    // Calculate the elapsed time:
//    elapsedTime = (t2.tv_sec - t1.tv_sec) * CONVERTER;      // sec to ms
//    elapsedTime += (t2.tv_usec - t1.tv_usec) / CONVERTER;   // us to ms
//    elapsedTime = elapsedTime * SECOND_CONVERTER;
//
//    return elapsedTime/cur_iter;
//}


int main(int args, char* argv[]) {
    unsigned long number;
    std::string numbuf;
//    std::cin >> numbuf;
//    number = strtoul(numbuf.c_str(), 0, 10);
//    double temo = osm_operation_time(number);
//    printf("op: %lf\n",temo );
//    printf("func: %lf\n", osm_function_time(number));
//    printf("sys: %lf\n", osm_syscall_time(number));
    std::cout << "op\n"<<osm_operation_time(1000)<<"\n";
    std::cout << "func\n"<<osm_function_time(1000)<<"\n";
    std::cout << "sys\n"<<osm_syscall_time(1000)<<"\n";

    return 0;
}