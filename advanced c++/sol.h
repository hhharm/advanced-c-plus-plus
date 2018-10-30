#pragma once
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

template<typename value_type, typename func_type>
void apply_parallel(vector<value_type> &v, func_type calculate_func, const int &num_threads) {
	mutex calc_mu;
	vector<thread> thread_pool(num_threads);
	int index = 0;
	//start threads
	for (int i = 0; i < num_threads; i++)
	{
		thread_pool[i] = thread([&]() {
			int size = v.size();
			int inner_ind;
			unique_lock<mutex> ulock(calc_mu);
			while (index < size)
			{
				inner_ind = index;
				index++;
				ulock.unlock();
				calculate_func(v[inner_ind]);
				ulock.lock();
				
			}
		});
	}

	// wait for threads to finish
	for (auto & t : thread_pool)
		t.join();
}
