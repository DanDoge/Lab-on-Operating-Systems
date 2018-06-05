import msgpackrpc
import os
import sys
import time

class deamon_server(object):
    def run(self, jobname, cmd_line, max_retry_time, time_out, image_id, cpu_limit, mem_limit, path_to_file):
        print(jobname);
        print(cmd_line);
        print(max_retry_time);
        print(time_out);
        print(image_id);
        print(cpu_limit);
        print(mem_limit);
        print(path_to_file);

        os.system("mkdir -p /var/www/shareddata/%s" % jobname);
        print("mkdir -p /var/www/shareddata/%s" % jobname);

        os.system("touch /var/www/shareddata/%s/out.txt" % jobname);
        os.system("touch /var/www/shareddata/%s/config.txt" % jobname);
        os.system("touch /var/www/shareddata/%s/status.txt" % jobname);

        print("touch /var/www/shareddata/%s/out.txt" % jobname);
        print("touch /var/www/shareddata/%s/config.txt" % jobname);
        print("touch /var/www/shareddata/%s/status.txt" % jobname);

        with open("/var/www/shareddata/%s/config.txt" % jobname, "w") as fp:
            print("writing config file...");
            fp.write(image_id);

        with open("/var/www/shareddata/%s/out.txt" % jobname, "w") as fp:
            print("writing output file...");
            fp.write("something must be wrong if you see this!");

        with open("/var/www/shareddata/%s/status.txt" % jobname, "w") as fp:
            print("writing status file...");
            fp.write("-1");
            print("done");
            time.sleep(1);

        print("lxc-start -n %s" % image_id);
        os.system("lxc-start -n %s" % image_id);
        print("lxc-start -n %s" % image_id);

        os.system("lxc-cgroup -n %s cpuset.cpus \"%s\" " % (image_id, cpu_limit) );
        os.system("lxc-cgroup -n %s memory.limit_in_bytes \"%s\" " % (image_id, mem_limit) );
        print("lxc-cgroup -n %s cpuset.cpus \"%s\" " % (image_id, cpu_limit) );
        print("lxc-cgroup -n %s memory.limit_in_bytes \"%s\" " % (image_id, mem_limit) );

        print(max_retry_time);
        if max_retry_time > 0:
            now_try_time = 0;
            while now_try_time < max_retry_time:
                now_try_time += 1;
                print("lxc-attach -n %s -- /bin/bash -c 'cd /var/www/shareddata%s && %s > /var/www/shareddata/%s/out.txt && echo 0 > /var/www/shareddata/%s/status.txt' " % (image_id, path_to_file, cmd_line, jobname, jobname) );
                os.system("lxc-attach -n %s -- /bin/bash -c 'cd /var/www/shareddata%s && %s > /var/www/shareddata/%s/out.txt && echo 0 > /var/www/shareddata/%s/status.txt' " % (image_id, path_to_file, cmd_line, jobname, jobname) );

                time.sleep(time_out);

                with open("/var/www/shareddata/%s/status.txt" % jobname, "r") as fp:
                    status_now = fp.read();
                    if status_now == 0:
                        break;
        return 0;

    def delete(self, job_name):
        with open("/var/www/shareddata/%s/config.txt" % job_name, "r") as fp:
            image_id = fp.read();
        print(image_id);
        print(job_name);
        os.system("rm -rf /var/www/shareddata/%s" %job_name); # am i right...? rm -rf


server = msgpackrpc.Server(deamon_server())
server.listen(msgpackrpc.Address("localhost", 8080));
server.start()
