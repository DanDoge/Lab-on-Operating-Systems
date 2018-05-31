import msgpackrpc
import os
import sys
import time

client = msgpackrpc.Client(msgpackrpc.Address("localhost", 8080))
client.call('run', sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5], sys.argv[6], sys.argv[7]);
