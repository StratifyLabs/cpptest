
#include <cstdio>
#include <sapi/sys.hpp>
#include <sapi/var.hpp>
#include "StringTest.hpp"
#include "ContainerTest.hpp"

bool handle_tests(const Cli & cli);

int main(int argc, char * argv[]){
	Cli cli(argc, argv, SOS_GIT_HASH);

#if defined __link

	String path = cli.get_option("path");
	Vector<String> directories = Dir::read_list(path);
	Printer p;

	for(u32 i=0; i < directories.count(); i++){
		if( directories.at(i).find("build_") != String::npos && directories.at(i).find("_link") == String::npos){
			FileInfo info;
			info = File::get_info(String() << path << "/" << directories.at(i) << "/cpptest");
			p.info("'%s' is %d", directories.at(i).cstring(), info.size());
		}
	}

#else

	if( handle_tests(cli) ){
		exit(0);
	}

#endif

	return 0;
}


bool handle_tests(const Cli & cli){


	if( cli.get_option("test") == "true" ){

		u32 o_execute_flags = 0;

		if( cli.get_option("api") == "true" ){ o_execute_flags |= Test::EXECUTE_API; }
		if( cli.get_option("stress") == "true" ){ o_execute_flags |= Test::EXECUTE_STRESS; }
		if( cli.get_option("performance") == "true" ){ o_execute_flags |= Test::EXECUTE_PERFORMANCE; }

		if( o_execute_flags == 0 ){
			o_execute_flags = Test::EXECUTE_ALL;
		}

		Test::initialize(cli.name(), cli.version(), SOS_GIT_HASH);

#if defined STRING_TEST
		if( cli.get_option("string") == "true" ){
			StringTest test;
			test.execute(o_execute_flags);
		}
#endif

		if( cli.get_option("container") == "true" ){
			ContainerTest test;
			test.execute(o_execute_flags);
		}

		Test::finalize();

		return true;
	}

	return false;

}
