#include <iostream>
#include "sol.h"
#include "tests.h"

//#define DEBUG

int vector_sizes[] = { 10, 100, 1000 };
int thread_numbers[] = { 1, 2, 3, 4 };

int run_test(bool fun(int, int), int vector_size, int threads_num, string test_name) {
	bool res = fun(vector_size, threads_num);
	int return_value = 0;
	if (!res) {
		cout << "ERROR! Check is not passed for " << test_name << endl;
	}
	else 
	{
#ifdef DEBUG
		cout << "Check is passed for " << test_name << endl;
#endif // DEBUG
		return_value++;
	}
	return return_value;
}

int main(int argc, char *argv[])
{
	int total_test_number = 0,
		passed_test_number = 0;

	for (auto &size : vector_sizes)
	{
		for (auto &thread_num : thread_numbers) {
			passed_test_number += run_test(&functor_test, size, thread_num, 
				"functor test: vector<list<char>> and functor that changes each vowel character in the list to 'A' and each consonant to 'H'; size " 
				+ to_string(size) + " , number of threads " + to_string(thread_num));

			passed_test_number += run_test(&functor_test_2, size, thread_num,
				"functor test: vector<double> and functor that multiplies value by 10; size "
				+ to_string(size) + " , number of threads " + to_string(thread_num));

			passed_test_number += run_test(&function_test, size, thread_num, 
				"function test: vector<vector<bool>>, function reverse value of each element;  size "	
				+ to_string(size) + " , number of threads " + to_string(thread_num));

			passed_test_number += run_test(&function_test_2, size, thread_num, 
				"function test: vector<int>, function set value to value*value, size "
				+ to_string(size) + " , number of threads " + to_string(thread_num));

			passed_test_number += run_test(&lambda_test, size, thread_num, 
				"lambda test: vector<tuple<int, double>>, lambda-function increases both int and double by 1; size "
				+ to_string(size) + " , number of threads " + to_string(thread_num));

			passed_test_number += run_test(&lambda_test, size, thread_num, 
				"lambda test: vector<tuple<string, string>>, lambda-function swap values in the tuple; size " 
				+ to_string(size) + " , number of threads " + to_string(thread_num));
			
			total_test_number+=6;
#ifdef DEBUG
			cout << endl;
#endif // DEBUG
		}
	}

#ifdef DEBUG
	cout << endl << endl;
#endif // DEBUG
	cout << "Total number of executed tests: " << total_test_number << endl;
	cout << "Number of passed tests: " << passed_test_number << " ("
		<< passed_test_number * 100 / total_test_number << "%)" << endl;
	cout << "Number of failed tests: " << total_test_number - passed_test_number << " ("
		<< (total_test_number - passed_test_number) * 100 / total_test_number << "%)" << endl;
	return 0;
}