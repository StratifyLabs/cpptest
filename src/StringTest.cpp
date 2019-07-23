#include <string>
#include "StringTest.hpp"

using namespace std;

StringTest::StringTest() : Test("StringTest"){

}


bool StringTest::execute_class_api_case(){
	string one("one");
	string two("two");
	string sample_string;

	sample_string = "this is a sample string";
	print_case_message("Sample string '%s'", sample_string.c_str());

	if( one == two ){
		print_case_failed("'%s' == '%s'", one.c_str(), two.c_str());
	}

	one = two;
	if( one != two ){
		print_case_failed("'%s' != '%s'", one.c_str(), two.c_str());
	}

	one.clear();
	two.clear();

	for(u32 i = 0; i < sample_string.size(); i++){
		if( sample_string.at(i) != sample_string[i] ){
			print_case_failed("%s():%d", __FUNCTION__, __LINE__);
		}
	}

	if( sample_string.front() == sample_string.back() ){
		print_case_failed("%s():%d", __FUNCTION__, __LINE__);
	}

	if( sample_string.size() != strlen(sample_string.c_str()) ){
		print_case_failed("%s():%d", __FUNCTION__, __LINE__);
	}

	sample_string.append("hello");
	sample_string.insert(5, "testing");
	sample_string.assign("revert back to another string");
	sample_string.replace(0, 5, "hello");
	sample_string.erase(0, 3);
	sample_string.pop_back();

	print_case_message("hello at %ld", sample_string.find("hello"));
	print_case_message("rhello at %ld", sample_string.rfind("hello"));

	string sample = sample_string.substr(0,3);

	print_case_message("sample is %s", sample.c_str());
	for(auto a : sample_string){
		print_case_message("char is %c", a);
	}


	return case_result();
}
