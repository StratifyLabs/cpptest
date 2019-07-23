#include "ContainerTest.hpp"

#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <string>

using namespace std;

ContainerTest::ContainerTest() : Test("ContainerTest"){}


bool ContainerTest::execute_class_api_case(){


#if defined ARRAY_TEST
	open_case("array");
	execute_array_api_case();
	close_case();
#endif

#if defined BITSET_TEST
	open_case("bitset");
	execute_bitset_api_case();
	close_case();
#endif

#if defined DEQUE_TEST
	open_case("deque");
	execute_deque_api_case();
	close_case();
#endif

#if defined FORWARD_LIST_TEST
	open_case("forward_list");
	execute_forward_list_api_case();
	close_case();
#endif

#if defined LIST_TEST
	open_case("list");
	execute_list_api_case();
	close_case();
#endif

#if defined MAP_TEST
	open_case("map");
	execute_map_api_case();
	close_case();
#endif

#if defined QUEUE_TEST
	open_case("queue");
	execute_queue_api_case();
	close_case();
#endif

#if defined SET_TEST
	open_case("set");
	execute_set_api_case();
	close_case();
#endif

#if defined STACK_TEST
	open_case("stack");
	execute_stack_api_case();
	close_case();
#endif

#if defined UNORDERED_MAP_TEST
	open_case("unordered_map");
	execute_unordered_map_api_case();
	close_case();
#endif

#if defined UNORDERED_SET_TEST
	open_case("unordered_set");
	execute_unordered_set_api_case();
	close_case();
#endif

#if defined VECTOR_TEST
	open_case("vector");
	execute_vector_api_case();
	close_case();
#endif

	return case_result();
}


bool ContainerTest::execute_array_api_case(){
	array<int, 5> value;

	for(u32 i=0; i < value.size(); i++){
		value.at(i) = i;
	}

	for(u32 i=0; i < value.size(); i++){
		if( value.at(i) != value[i] ){ print_case_failed("%s():%d\n", __FUNCTION__, __LINE__); }
		if( value.at(i) != (int)i ){ print_case_failed("%s():%ld\n", __FUNCTION__, __LINE__); }
	}

	if( value.front() == value.back() ){
		print_case_failed("%s():%d\n", __FUNCTION__, __LINE__);
	}

	for(auto v : value){
		print_case_message("value is %d", v);
	}

	for (auto it = value.begin(); it != value.end(); ++it ){
		print_case_message("value is %d", *it);
	}

	if( value.empty() == true ){
		print_case_failed("%s():%d\n", __FUNCTION__, __LINE__);
	}

	return case_result();
}

bool ContainerTest::execute_bitset_api_case(){
	return case_result();
}

bool ContainerTest::execute_deque_api_case(){
	return case_result();
}

bool ContainerTest::execute_forward_list_api_case(){
	return case_result();
}

bool ContainerTest::execute_list_api_case(){
	return case_result();
}

bool ContainerTest::execute_map_api_case(){
	return case_result();
}

bool ContainerTest::execute_queue_api_case(){
	return case_result();
}
bool ContainerTest::execute_set_api_case(){
	return case_result();
}
bool ContainerTest::execute_stack_api_case(){
	return case_result();
}
bool ContainerTest::execute_unordered_map_api_case(){
	return case_result();
}
bool ContainerTest::execute_unordered_set_api_case(){
	return case_result();
}

bool ContainerTest::execute_vector_api_case(){

	vector<u32> vector_u32;

	const u32 max = 200;

	for(u32 i=0; i < max; i++){
		vector_u32.push_back(i);
	}

	if( vector_u32.at(9) != 9 ){
		print_case_failed("failed %s():%d", __FUNCTION__, __LINE__);
	}

	if( vector_u32.size() != max ){
		print_case_failed("failed %s():%d", __FUNCTION__, __LINE__);
	}

	while( vector_u32.size() > 0 ){
		vector_u32.pop_back();
	}

	for(auto v : vector_u32){
		print_case_message("value is %ld", v);
	}

	return case_result();
}
