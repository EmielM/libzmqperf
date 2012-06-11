#include <stdint.h>
#include <assert.h>

#define private public
	// hack to access the internal zmq symbols

#include <zmq.hpp>
#include "pull.hpp"
#include "xreq.hpp"

#undef private

uint64_t zmq_queue_size_in(zmq::socket_t* socket) {
	int type;
	size_t type_size = sizeof(type);

	socket->getsockopt(ZMQ_TYPE, &type, &type_size);

	zmq::fq_t* fq;

	if(type == ZMQ_PULL)
		fq = &((zmq::pull_t*)(socket->ptr))->fq;
	else if (type == ZMQ_DEALER)
		fq = &((zmq::xreq_t*)(socket->ptr))->fq;
	else
		return 0;

	uint64_t queued = 0;

	int pipes = fq->pipes.size();
	for (int i = 0; i < pipes; i++) {
		zmq::reader_t* r = fq->pipes[i];
		zmq::writer_t* w = r->writer;
		queued += (w->msgs_written - r->msgs_read);
	}

	return queued;
}
