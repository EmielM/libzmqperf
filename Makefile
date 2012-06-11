ZMQ_SOURCE=/usr/local/src/zeromq-2.1.10/src

zmqperf.o: zmqperf.cpp
	g++ -c -I/usr/local/include -I$(ZMQ_SOURCE) -o $@ $^

clean:
	rm -f zmqperf.o

.PHONY: clean