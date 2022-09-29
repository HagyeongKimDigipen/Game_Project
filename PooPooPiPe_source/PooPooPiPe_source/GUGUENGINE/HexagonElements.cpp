/*
 *juhye.son
 *3.10.2020
 *juhye.son990902@gmail.com
 *HexagonElements.cpp
 *It has generate map's element for hexagon Edge
 */
#include "HexagonElements.h"
#include "HexCoordinates.h"

HexagonEdge::HexagonEdge(int ID, int edgeID, bool hasNeighbor_) :
	objectID(ID), objectEdgeID(edgeID), hasNeighbor(hasNeighbor_) {
	myEdge.start = { 0.f, 0.f };
	myEdge.end = { 0.f, 0.f };
};
HexagonEdge::HexagonEdge() :
	objectID(0), objectEdgeID(0), hasNeighbor(0) {
	myEdge.start = { 0.f, 0.f };
	myEdge.end = { 0.f, 0.f };
};

void HexagonEdge::SetMyEdge(Vector2<float>::Edge temp)
{
	myEdge = temp;
}
void HexagonEdge::SetObjectID(int temp)
{
	objectID = temp;
}
void HexagonEdge::SetObjectEdgeID(bool temp)
{
	objectEdgeID = temp;
}
void HexagonEdge::SetHasNeigbor(bool temp)
{
	hasNeighbor = temp;
}

void HexagonEdge::WhoIsNeighbor(int puzzleNum, int EdgeNum)
{
	neighborInfo = { puzzleNum, EdgeNum };
}

Vector2<int> HexagonEdge::GetWhoIsNeighbor()
{
	Vector2<int> temp = neighborInfo;
	return temp;
}

Vector2<float>::Edge HexagonEdge::GetMyEdge()
{
	return myEdge;
}
//int GenerateMap::HexagonEdge::GetObjectID() {
//	return 
//}
//int GenerateMap::HexagonEdge::GetObjectEdgeID();
bool HexagonEdge::GetHasNeighbor()
{
	return hasNeighbor;
}
void HexagonEdges::Init() {
	for (int i = 0; i < 6; i++)
	{
		myEdge[i].SetHasNeigbor(false);
		myEdge[i].SetMyEdge({ { 0.f, 0.f }, { 0.f, 0.f } });
		myEdge[i].SetObjectEdgeID(0);
		myEdge[i].SetObjectID(i);
	}
}
void HexagonEdges::clear() {
	for (int i = 0; i < 6; i++)
	{
		myEdge[i].SetHasNeigbor(false);
		myEdge[i].SetMyEdge({ { 0.f, 0.f }, { 0.f, 0.f } });
		myEdge[i].SetObjectEdgeID(0);
		myEdge[i].SetObjectID(i);
	}
}
HexagonCoordinates::HexagonCoordinates(Vector2<float> ori):origin(ori){
	
	SetEveryEdgeCoordinates();
	SetEveryEdgeCenterCoordinates();
}
void HexagonCoordinates::SetEveryEdgeCoordinates()
{
	HexCoordinates getCoordinates;
	HexagonEdges myEdges;

	for (int i = 0; i < 6; i++)
	{
		myEdges.clear();
		int count = i % 6;
		int nextCount = (i+1) % 6;
		
		myEdges.myEdge[0].SetMyEdge({ getCoordinates.ReturnPuzzleCoor(origin, static_cast<DirAngle>(count), 80.f) , 
			getCoordinates.ReturnPuzzleCoor(origin, static_cast<DirAngle>(nextCount), 80.f) });
		hexagonEdgeCoordinates.push_back(myEdges.myEdge[0]);
	}
}
void HexagonCoordinates::SetEveryEdgeCenterCoordinates()
{
	for (int i = 0; i < 6; i++)
	{
		DirAngle myAngle = static_cast<DirAngle>(0);
		myAngle = static_cast<DirAngle>(i % 6);
		DirAngle myNextAngle = static_cast<DirAngle>(0);
		myNextAngle = static_cast<DirAngle>(i % 6);
		Vector2<float> myEdgeCenter = { (GetEdgeCoordinates(myAngle).start.x + GetEdgeCoordinates(myAngle).end.x) / 2.f,
		(GetEdgeCoordinates(myAngle).start.y + GetEdgeCoordinates(myAngle).end.y) / 2.f };
		hexagonEdgeCenterCoordinates.push_back(myEdgeCenter);
	}
}

Vector2<float>::Edge HexagonCoordinates::GetEdgeCoordinates(DirAngle i)
{
	int count = static_cast<int>(i);
	return { hexagonEdgeCoordinates[count].GetMyEdge().start, hexagonEdgeCoordinates[count].GetMyEdge().start };
}
Vector2<float> HexagonCoordinates::GetEdgeCenterCoordinates(DirAngle i)
{
	int count = static_cast<int>(i);
	return hexagonEdgeCenterCoordinates[count];
}