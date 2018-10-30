#include "tests.h"

//#define TIME_MEASUREMENT

/*dumb test which simply prints that function was called by _thread_id_ thread with given argument*/
mutex mu; //for cout
auto name_yourself = [](int n) {
	std::lock_guard<mutex> lock(mu);
	cout << " Called " << std::this_thread::get_id() << " thread, element is " << n << endl;
};
bool dumb_test() {
	bool res = true;
	vector<int> vect;
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);
	vect.push_back(5);
	vect.push_back(6);
	int n = 4;
	apply_parallel(vect, name_yourself, n);
	return res;
}

/*initialization connected*/
//supported data types for initialization: integer, double, tuple_string_string, tuple_int_double, vector_of_bool, list_of_chars

std::string randomString(uint maxLength = 5, std::string charIndex = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
{ 
	uint length = rand() % maxLength + 1; 
	uint indexesOfRandomChars[5];
	for (uint i = 0; i < length; ++i)
		indexesOfRandomChars[i] = rand() % charIndex.length();
	std::string randomString = "";
	for (uint i = 0; i < length; ++i)
	{
		randomString += charIndex[indexesOfRandomChars[i]];
	}
	return randomString;
}
void initialize(vector<int> &res, int size) {
	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++)
	{
		res.push_back(rand());
	}
}
void initialize(vector<double> &res, int size) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		res.push_back(((double)rand()) / rand());
	}
}
void initialize(vector<tuple<string, string>> &res, int size) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		tuple<string, string> t(randomString(), randomString());
		res.push_back(t);
	}
}
void initialize(vector<tuple<int, double>> &res, int size) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		tuple<int, double> t(rand(), ((double)rand()) / rand());
		res.push_back(t);
	}
}
void initialize(vector<vector<bool>> &res, int size) {
	srand((unsigned)time(NULL));
	int inner_vector_max_size = 10, tmp_size = 0;
	for (int i = 0; i < size; i++)
	{
		vector<bool> tmp_vect;
		tmp_size = rand() % inner_vector_max_size;
		for (int j = 0; j < tmp_size; j++) {
			tmp_vect.push_back((rand() % 2) == 0);
		}
		res.push_back(tmp_vect);
	}
}	
void initialize(vector<list<char>> &res, int size) {
	string charIndex = "abcdefghijklmnaoqrstuvwxyz";
	int charIndLength = charIndex.length();
	for (int i = 0; i < size; i++)
	{
		list<char> tmp_list;
		for (int j = 0; j < 5; j++)
		{
			tmp_list.push_back(charIndex[rand() % charIndLength]);
			tmp_list.push_front(charIndex[rand() % charIndLength]);
		}
		res.push_back(tmp_list);
	}
}

/*check that result is correct*/
template<typename T, typename func> 
bool check_result(vector<T> res_vector, vector<T> init_vector, func comprator) {
	auto ItA = res_vector.begin(), ItB = init_vector.begin();
	while (ItA != res_vector.end() || ItB != init_vector.end())
	{
		if (!comprator((*ItA), (*ItB))) { return false; }
		if (ItA != res_vector.end())
		{
			++ItA;
		}
		if (ItB != init_vector.end())
		{
			++ItB;
		}
	}
	return true;
}

/*********************** function ********************************/

void reverse(vector<bool> &l) {
	for (auto el : l)
		el = !el;
}

void square(int &el) { el *= el; }

bool function_test(int size, int num_threads) {
	//pre-test activities
	vector<vector<bool>> m, m_init;
	initialize(m, size);
	m_init = m;

#ifdef TIME_MEASUREMENT
	TimeVar t1 = timeNow();
#endif // TIME_MEASUREMENT	
	//run test itself
	apply_parallel(m, &reverse, num_threads);
#ifdef TIME_MEASUREMENT
	double time = duration(timeNow() - t1);
	cout << "Execution time: " << time << endl;
#endif // TIME_MEASUREMENT	

	//check that everything is correct
	bool isCorrect = check_result(m, m_init, [](vector<bool> &a, vector<bool> &b) -> bool {
		for (unsigned int i = 0; i < a.size(); i++) {
			//if a is false b should be true and vice versa
			if ((a[i] && b[i]) || (!a[i] && !b[i])) {
				return false;
			}
		}
		return true;
	});
	return isCorrect;
}

bool function_test_2(int size, int num_threads) {
	//pre-test activities
	vector<int> m, m_init;
	initialize(m, size);
	m_init = m;

#ifdef TIME_MEASUREMENT
	TimeVar t1 = timeNow();
#endif // TIME_MEASUREMENT	
	//run test itself
	apply_parallel(m, &square, num_threads);
#ifdef TIME_MEASUREMENT
	double time = duration(timeNow() - t1);
	cout << "Execution time: " << time << endl;
#endif // TIME_MEASUREMENT	

	//check that everything is correct
	bool isCorrect = check_result(m, m_init, [](int &a, int &b) -> bool {
			if (a != b*b) {
				return false;
			} 
			return true;
	});
	return isCorrect;
}

/*********************** functor ********************************/

class myFunctor {
public:
	void operator()(list<char> &l) {
		for (auto &el : l)
		{
			char c = tolower(el);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			{
				el = 'A';
			}
			else
			{
				el = 'H';
			}
		}
	}
};

class incrDoubleFunctor {
public:
	void operator()(double &el) {
		el *= 10;
	}
};

bool functor_test(int size, int num_threads) {
	//pre-test activities
	vector<list<char>> m, m_init;
	initialize(m, size);
	m_init = m;

#ifdef TIME_MEASUREMENT
	TimeVar t1 = timeNow();
#endif // TIME_MEASUREMENT	
	//run test itself
	apply_parallel(m, myFunctor(), num_threads);
#ifdef TIME_MEASUREMENT
	double time = duration(timeNow() - t1);
	cout << "Execution time: " << time << endl;
#endif // TIME_MEASUREMENT	

	//check that everything is correct
	bool isCorrect = check_result(m, m_init, [](list<char> &a, list<char> &b) -> bool {
		auto ItA = a.begin(), ItB = b.begin();
		while (ItA != a.end() || ItB != b.end())
		{
			char c = (*ItB), d = (*ItA);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			{
				if (d != 'A')
				{
					return false;
				}
			}
			else
			{
				if (d != 'H')
				{
					return false;
				}
			}
			if (ItA != a.end())
			{
				++ItA;
			}
			if (ItB != b.end())
			{
				++ItB;
			}
		}
		return true;
	});
	return isCorrect;
}

bool functor_test_2(int size, int num_threads) {
	//pre-test activities
	vector<double> m, m_init;
	initialize(m, size);
	m_init = m;

#ifdef TIME_MEASUREMENT
	TimeVar t1 = timeNow();
#endif // TIME_MEASUREMENT	
	//run test itself
	apply_parallel(m, incrDoubleFunctor(), num_threads);
#ifdef TIME_MEASUREMENT
	double time = duration(timeNow() - t1);
	cout << "Execution time: " << time << endl;
#endif // TIME_MEASUREMENT	

	//check that everything is correct
	bool isCorrect = check_result(m, m_init, [](double &a, double &b) -> bool {
		if (abs(a - b*10) < 0.1) {
			return true;
		}
		return false;
	});
	return isCorrect;
}


/*********************** lambda *********************************/
bool lambda_test(int size, int num_threads) {
	//pre-test activities
	vector<tuple<int, double>> m, m_init;
	initialize(m, size);
	m_init = m;

#ifdef TIME_MEASUREMENT
	TimeVar t1 = timeNow();
#endif // TIME_MEASUREMENT	
	//run test itself
	apply_parallel(m, [](tuple<int, double>& e) {
		get<0>(e) += 1;
		get<1>(e) += 1.;
	}, num_threads);
#ifdef TIME_MEASUREMENT
	double time = duration(timeNow() - t1);
	cout << "Execution time: " << time << endl;
#endif // TIME_MEASUREMENT	

	//check that everything is correct
	bool isCorrect = check_result(m, m_init, [](tuple<int, double> &a, tuple<int, double>&b) -> bool {
		//for integer check that difference is 1, for double check that difference is between 0.9 and 1.1
		if (get<0>(a) != get<0>(b) + 1 &&
			(get<1>(a) - get<1>(b) > 1.1 ||
				get<1>(a) - get<1>(b) < 0.9)) {
			return false;
		}
		return true;
	});
	return isCorrect;
}

bool lambda_test_2(int size, int num_threads) {
	//pre-test activities
	vector<tuple<string, string>> m, m_init;
	initialize(m, size);
	m_init = m;

#ifdef TIME_MEASUREMENT
	TimeVar t1 = timeNow();
#endif // TIME_MEASUREMENT	
	//run test itself
	apply_parallel(m, [](tuple<string, string>& e) {
		//swap values in the tuple
		e = tuple<string,string>(get<1>(e), get<0>(e));
	}, num_threads);
#ifdef TIME_MEASUREMENT
	double time = duration(timeNow() - t1);
	cout << "Execution time: " << time << endl;
#endif // TIME_MEASUREMENT	

	//check that everything is correct
	bool isCorrect = check_result(m, m_init, [](tuple<string, string> &a, tuple<string, string>&b) -> bool {
		if (get<0>(a) != get<1>(b) || get<1>(a) != get<0>(b)) {
			return false;
		}
		return true;
	});
	return isCorrect;
}