#pragma once
#include "dxflib\dl_creationadapter.h"

class MyParser : public DL_CreationAdapter
{
public:
	MyParser();

public: int hatchAmount;

	virtual void addHatchEdge(const DL_HatchEdgeData& data);
public: int amount();

};
