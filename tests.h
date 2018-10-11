#pragma once
#include <iostream>
#include "sol.h"
#include <random>
#include <string>
#include <list>
#include <tuple>
#include <ctime>
#include <chrono>
#include <utility>

typedef std::chrono::high_resolution_clock::time_point TimeVar;
#define duration(a) std::chrono::duration_cast<std::chrono::milliseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

using namespace std;

typedef unsigned int uint;

/*loops through int vector with 6 elements and says "hey, i'm thread with such id, i'm processing this number"*/
bool dumb_test();

/*uses vector<bool> and function, it reverses each element in the vector (true -> false, false -> true)*/
bool function_test(int size, int num_threads);

/*uses int and function that makes set value to square*/
bool function_test_2(int size, int num_threads);

/*uses list<char> and functor, it changes each vowel character in the list to 'A' and each consonant to 'H'*/
bool functor_test(int size, int num_threads);

/*uses double and functor that multiplies value by 10*/
bool functor_test_2(int size, int num_threads);

/*uses tuple<int,double> and lambda function that increases value of both numbers in tuple sby 1*/
bool lambda_test(int size, int threads_num);

/*uses tuple<string,string> and lambda function that swaps values inside tuple*/
bool lambda_test_2(int size, int threads_num);