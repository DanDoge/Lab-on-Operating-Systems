#include <iostream>
#include "rpc/client.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv) {

    ofstream out1("out.txt");

    if(argc == 8){
        char* jobname = argv[1];
        char* cmd_line = argv[2];
        int max_retry_time = atoi(argv[3]);
        int time_out = atoi(argv[4]);
        char* image_id = argv[5];
        char* cpu_limit = argv[6];
        char* mem_limit = argv[7];

        out1 << "jobname is " << jobname << endl;
        out1 << "cmd_line is " << cmd_line << endl;
        out1 << "max_retry_time is " << max_retry_time << endl;
        out1 << "time_out is " << time_out << endl;
        out1 << "image_id is " << image_id << endl;
        out1 << "cpuset is " << cpu_limit << endl;
        out1 << "mem limit is " << mem_limit << endl;
        out1.close();

        rpc::client client("127.0.0.1", 8080);
        auto result = client.call("run", jobname, cmd_line, max_retry_time, time_out, image_id, cpu_limit, mem_limit).as<int>();
        std::cout << "The result is: " << result << std::endl;
    }/* else if(argc == 2){
        char* jobname = argv[1];

        rpc::client client("127.0.0.1", 8080);
        auto result = client.call("query", jobname).as<int>();
        std::cout << "the result is " << result << std::endl;
    }*/
    return 0;
}
