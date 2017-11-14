// DynamicSimulatorSrc.cpp : Defines the entry point for the console application.
////Reads the Network Resources from NetworkResourceCreator Class for one session
//Fetch the current Traffic image from TrafficSelector Class
//Start the session and try to satisfy the traffic according to the traffic grooming algorithm
//Handle the network resources using NeworkResouceMaintainer Class
//Blocked requests are either sent to Traffic Producer Class for retry of the unsatisfied request if session is not expired or sent to blocked traffic list.

#include "stdafx.h"
#include "TrafficProducer.h"
#include "NetwResourceMaintainer.h"
#include "containerFile.h"
#include<iostream>
using namespace std;
int main()
{
	networkTopology = getKnowledgeGraph();
	//cjdcjdcj
	return 0;
}

