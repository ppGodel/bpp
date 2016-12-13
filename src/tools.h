#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
//#include <random>

#ifndef TOOLS_H_
#define TOOLS_H_

namespace Tools
{
	using namespace std;
	static int GetRandomIntNumberBetween(int ,int );
	static string to_string(int value);
	template<typename T>
	static std::string to_string(const T& value);
	static vector<vector<string> >file_toString(const string& file_address);
	static const std::string currentDateTime();
	template<class T,class U>
	class bitype
	{
	public:
		T value1;
		U value2;
		bitype(T t,U u):value1(t),value2(u){};
		bool operator==(const bitype<T,U>& a)
		{
			return this->value1 == a.value1 && this->value2 == a.value2;
		};

	};
}

#endif /* TOOLS_H_ */
