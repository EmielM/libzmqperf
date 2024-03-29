libzmqperf
==========

Helper lib to do some measurements on ZMQ internals. Currently, it supports guestimating the size of unprocessed incoming messages for `ZMQ_PULL` and `ZMQ_DEALER` sockets.

### Disclaimer ###

  * It is very, very, very hacky.
  * It is untested.

### Build instructions ###

  * Possibly adjust the source or version of your zmq source tree in `Makefile`.
  * The resulting `zmqperf.o` could be linked to your project.
  * Don't forget to include `zmqperf.hpp`.

### License ###
	Copyright 2012 Emiel Mols. All rights reserved.
	
	Redistribution and use in source and binary forms, with or without modification, are
	permitted provided that the following conditions are met:
	
	   1. Redistributions of source code must retain the above copyright notice, this list of
	      conditions and the following disclaimer.
	
	   2. Redistributions in binary form must reproduce the above copyright notice, this list
	      of conditions and the following disclaimer in the documentation and/or other materials
	      provided with the distribution.
	
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER ``AS IS'' AND ANY EXPRESS OR IMPLIED
	WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
	FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> OR
	CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
	ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
	ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	
	The views and conclusions contained in the software and documentation are those of the
	authors and should not be interpreted as representing official policies, either expressed
	or implied, of Emiel Mols.
