#include "threadsafe_queue.h"
#include "Segment.h"
#include "MPProducer.h"
#include "UDPClientSuper.h"
#include "UDPClientSuperLite.h"
#include "UDPServer.h"
#include "mpparas.h"

namespace mp {

class mpcb {

	//for sender
	threadsafe_queue<Segment> sendQueue;
	int dss_root;
	int segment_size;
	int numPaths;
	int UDPportsHead;
	int RoundRuby;
	std::vector<std::string> UDPIP1;
	std::vector<std::string> UDPIP2;
	std::vector<std::string> UDPport1;
	std::vector<std::string> UDPport2;

	}
}
