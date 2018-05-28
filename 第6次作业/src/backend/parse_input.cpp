#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {
  ofstream out1("out.txt");
  if(argc < 6){
    cerr << "lose some parameters? in parse_input.cpp" << endl;
    out1 << "lose some parameters? in parse_input.cpp" << endl;
    out1.close();
  }else{
    char* jobname = argv[1];
    char* cmd_line = argv[2];
    int max_retry_time = atoi(argv[3]);
    int time_out = atoi(argv[4]);
    char* image_id = argv[5];

    out1 << "jobname is " << jobname << endl;
    out1 << "cmd_line is " << cmd_line << endl;
    out1 << "max_retry_time is " << max_retry_time << endl;
    out1 << "time_out is " << time_out << endl;
    out1 << "image_id is " << image_id << endl;
    out1.close();

    char cmd[1024] = {};

    sprintf(cmd, "sudo mkdir -p /var/www/shareddata/%s", jobname);
    system(cmd);

    system("sudo chmod -R 777 /var/www/shareddata");

    sprintf(cmd, "sudo touch /var/www/shareddata/%s/out.txt", jobname);
    system(cmd);

    sprintf(cmd, "sudo touch /var/www/shareddata/%s/config.txt", jobname);
    system(cmd);

    sprintf(cmd, "sudo touch /var/www/shareddata/%s/status.txt", jobname);
    system(cmd);

    sprintf(cmd, "sudo chmod -R 777 /var/www/shareddata/%s", jobname);
    system(cmd);

    sprintf(cmd, "/var/www/shareddata/%s/config.txt", jobname);
    ofstream out2(cmd);
    out2 << image_id << endl;
    out2.close();

    sprintf(cmd, "/var/www/shareddata/%s/status.txt", jobname);
    ofstream out3(cmd);
    out3 << 1 << endl; // 1 -> fail, 0 -> success
    out3.close();

    sprintf(cmd, "sudo chmod -R 777 /var/lib/lxc/%s/rootfs/var/www/shareddata", image_id);
    system(cmd);

    sprintf(cmd, "sudo lxc-start -n %s", image_id);
    system(cmd);

    int now_try_time = 0;
    while(now_try_time++ < max_retry_time){
        sprintf(cmd, "sudo lxc-attach -n %s -- %s > /var/www/shareddata/%s/out.txt && sudo echo 0 > /var/www/shareddata/%s/status.txt", image_id, cmd_line, jobname, jobname);
        system(cmd);

        sleep(time_out);

        sprintf(cmd, "/var/www/shareddata/%s/status.txt", jobname);
        ifstream in1(cmd);
        int status = 1;
        in1 >> status;
        in1.close();
        if(status == 0){
            break;
        }
    }

    sprintf(cmd, "sudo lxc-stop -n %s", image_id);
    system(cmd);

  }
  return 0;
}
