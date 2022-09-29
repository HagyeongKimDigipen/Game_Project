/*
 *juhye.son
 *3.10.2020
 *juhye.son990902@gmail.com
 *HexagonElements.h
 *It has generate map's element for hexagon Edge
 */
#pragma once
#include "Mathematics/Vector2.hpp"
#include <vector>
#include "HexCoordinates.h"

class HexagonEdge {
public:
	HexagonEdge(int ID, int edgeID, bool hasNeighbor_);

	HexagonEdge();

	void SetMyEdge(Vector2<float>::Edge temp);
	void SetObjectID(int temp);
	void SetObjectEdgeID(bool temp);
	void SetHasNeigbor(bool temp);
	void WhoIsNeighbor(int puzzleNum, int EdgeNum);
	Vector2<int> GetWhoIsNeighbor();
	Vector2<float>::Edge GetMyEdge();
	//int GetObjectID();
	//int GetObjectEdgeID();
	bool GetHasNeighbor();
	bool isComeBack = false;
private:
	Vector2<float>::Edge myEdge;

	int objectID = 0;
	int objectEdgeID = 0;

	bool hasNeighbor = false;
	Vector2<int> neighborInfo;

};

class HexagonEdges
{
public:
	HexagonEdges()
	{
		Init();
	}
	void Init();
	void clear();

	HexagonEdge myEdge[6];

};

class HexagonCoordinates {
public:

	HexagonCoordinates(Vector2<float> ori);

	void SetEveryEdgeCoordinates();
	void SetEveryEdgeCenterCoordinates();

	Vector2<float>::Edge GetEdgeCoordinates(DirAngle i);
	Vector2<float> GetEdgeCenterCoordinates(DirAngle i);

private:
	std::vector<HexagonEdge> hexagonEdgeCoordinates;
	std::vector<Vector2<float>> hexagonEdgeCenterCoordinates;
	Vector2<float> origin;



};

struct SaveWay {
	bool ways[6];
};