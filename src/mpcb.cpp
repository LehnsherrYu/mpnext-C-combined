#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "stdio.h"
#include "mpcb.h"
#include "Segment.h"
#include "QoE.h"
#include "utils.h"

namespace mp {

mpcb::mpcb() {

	numPaths = 2;
	UDPport1 = 12345;
	UDPport2 = 22345;
	segment_size = SEGMENT_SIZE;
	dss_root = 0;
}

	// connection establishment
void mpcb::init(char* UDPIP1,char* UDPIP2) {

	std::vector<int>portNumber;
	for(int i=0;i<portNumber.size();i++)
	{
		int temp=12345;
		portNumber.push_back(temp);
		temp++;
		std::cout << "UDP Server"<< i << " initialized...\n";
		mpp->start();
		std::cout << "UDP Server" << i <<  "started...\n";
		udpCS = new UDPClientSuper(UDPIPs[i], UDPports[i]);
		mpp=new MPProducer(&sendQueue,udpCS,udpCS2);
		std::cout << "MPProducer"<< i<< "initialized...\n";
	}
	// checking whether their are content in the mp sending buffer


int mpcb::send_basic(const void* content1, int content_size)
{
		Segment s;
		s.pds = 0;
		s.size = content_size;
		memcpy(s.content, content1, 1000);
		if (sendQueue.size() > RoundRuby) {
			return -1;
		} else {
			s.dss = ++dss_root;
			sendQueue.push(s);
		}
		return 0;
}
