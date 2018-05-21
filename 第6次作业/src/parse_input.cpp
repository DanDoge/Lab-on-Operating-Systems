#include <iostream>
#include <oftream>
using namespace std;

int main(int argc, char const *argv[]) {
  ofstream out("out.txt");
  if(argc < 6){
    cerr << "lose some parameters? in parse_input.cpp" << endl;
  }else{
    char* jobname = argv[1];
    char* cmd_line = argv[2];
    char* max_retry_time = argv[3];
    char* time_out = argv[4];
    char* image_id = argv[5];

    out << "jobname is " << jobname << endl;
    out << "cmd_line is " << cmd_line << endl;
    out << "max_retry_time is " << max_retry_time << endl;
    out << "time_out is " << time_out << endl;
    out << "image_id is " << image_id << endl;
  }
  out.close();
  return 0;
}
