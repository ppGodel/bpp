/*
 * tools.cpp
 *
 *  Created on: Oct 7, 2016
 *      Author: ppGodel
 */
#include "tools.h"

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
#ifndef TOOLS_CPP_
#define TOOLS_CPP_

namespace Tools {
static int GetRandomIntNumberBetween(int min, int max) {

//		std::random_device                  rand_dev;
//		std::mt19937                        generator(rand_dev());
//		std::uniform_int_distribution<int>  distr(min, max);
//		return distr(generator);
//	    std::srand((time(NULL)));
	return rand() % (max - min + 1) + min;
}

static std::string to_string(int value) {
	return SSTR(value);
}

template<typename T>
static std::string to_string(const T& value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

static vector<vector<string> > file_toString(const string& file_address) {
	string line;
	vector<vector<string> > result;
	string currentWord;
	ifstream myfile;
	myfile.open(file_address.c_str());
	if (myfile.is_open()) {
		//while (getline(myfile, line))
		while (!myfile.eof()) {
			//myfile >> line;
			//myfile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(myfile, line);
			stringstream iss(line);
			string aux;
			vector<string> strWords;
			while (iss >> aux) {
				strWords.push_back(aux);
			}
			if (strWords.size() > 0) {
				result.push_back(strWords);
			}
		}
		myfile.close();
	} else {
		cout << "not open " << myfile.rdstate() << endl;
	}
	return result;
}
static const std::string currentDateTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}
}

#endif /* TOOLS_CPP_ */

