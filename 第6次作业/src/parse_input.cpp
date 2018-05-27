#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  ofstream out("out.txt");
  if(argc < 6){
    cerr << "lose some parameters? in parse_input.cpp" << endl;
    out << "lose some parameters? in parse_input.cpp" << endl;
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

    int rand_ip = max(rand() % 256, 2);
/*
    char cmd[1024];
    sprintf(cmd, "%s %s %d", "./aufs_shell.sh", image_id, rand_ip);
    printf("command line is: %s", cmd);
    system(cmd);
*/
    char cmd[1024] = {};
    sprintf(cmd, "sudo lxc-create -t ubuntu -n %s", image_id);
    //system(cmd);
    sprintf(cmd, "sudo ./config_ip.sh %s %d", image_id, rand_ip);
    //system(cmd);
    sprintf(cmd, "sudo mkdir -p /var/www/shareddata/%s", jobname);
    system(cmd);
    system("sudo chmod -R 777 /var/www/shareddata"); // 我是个傻子
    sprintf(cmd, "sudo touch /var/www/shareddata/%s/out.txt", jobname);
    system(cmd);
    sprintf(cmd, "sudo chmod -R 777 /var/lib/lxc/%s/rootfs/var/www/shareddata", image_id);
    system(cmd);
    sprintf(cmd, "sudo lxc-attach -n %s -- %s > /var/www/shareddata/%s/out.txt", image_id, cmd_line, jobname);
    cout << cmd << endl;
    system(cmd);
  }
  out.close();
  return 0;
}
