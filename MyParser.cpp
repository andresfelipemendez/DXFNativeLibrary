#include "MyParser.h"

MyParser::MyParser(){}
int hatchAmount;

void MyParser::addHatchEdge(const DL_HatchEdgeData& data)
{
	hatchAmount = data.vertices.size();
}

int MyParser::amount()
{
	return hatchAmount;
}

