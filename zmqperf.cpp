#include <stdint.h>
#include <assert.h>

#define private public
	// hack to access the internal zmq symbols

#include <zmq.hpp>
#include "pull.hpp"
#include "xreq.hpp"
#include "xrep.hpp"

#undef private

uint64_t zmq_queue_size_in(zmq::socket_t* socket) {

	int type;
	size_t type_size = sizeof(type);

	socket->getsockopt(ZMQ_TYPE, &type, &type_size);

	uint64_t qs = 0;

	if(type == ZMQ_PULL || type == ZMQ_DEALER) {

		zmq::fq_t* fq;
		if (type == ZMQ_PULL)
			fq = &((zmq::pull_t*)(socket->ptr))->fq;
		else
			fq = &((zmq::xreq_t*)(socket->ptr))->fq;

		for (int i = 0; i < fq->pipes.size(); i++) {
			zmq::reader_t* r = fq->pipes[i];
			zmq::writer_t* w = r->writer;
			qs += w->msgs_written - r->msgs_read;
		}
	}
	else if (type == ZMQ_ROUTER) {
		zmq::xrep_t::inpipes_t* inpipes = &((zmq::xrep_t*)(socket->ptr))->inpipes;

		for (int i = 0; i < inpipes->size(); i++) {
			zmq::reader_t* r = (*inpipes)[i].reader;
			zmq::writer_t* w = r->writer;
			qs += w->msgs_written - r->msgs_read;
		}
	}

	return qs;
}
