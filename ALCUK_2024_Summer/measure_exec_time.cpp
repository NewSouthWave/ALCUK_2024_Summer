//
//  measure_execution_time.cpp
//  ALCUK_2024_Summer
//
//  Created by Nam on 7/21/24.
//

#include <ctime>

clock_t start, finish;  //  시작 종료 시간 변수
double duration;         //  측정시간 변수

start = clock(); //  측정 시작

/*  측정 원하는 코드블럭 */

finish = clock();

duration = (double)(finish - start) / CLOCKS_PER_SEC;   //  실행시간
