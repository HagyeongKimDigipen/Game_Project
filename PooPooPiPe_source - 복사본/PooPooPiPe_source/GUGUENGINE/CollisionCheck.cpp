#include "Mathematics/Vector2.hpp"
#include "CollisionCheck.h"
#include "Mesh.h"




bool CollisionCheck::Box2BoxCollision(Mesh* boxA, Mesh* boxB)
{
	if (GetMax(boxA).x < GetMin(boxB).x ||
		GetMax(boxB).x < GetMin(boxA).x ||
		GetMax(boxA).y < GetMin(boxB).y ||
		GetMax(boxB).y < GetMin(boxA).y)
	{
		return false;
	}
	return true;

}

bool CollisionCheck::Point2BoxCollision(Vector2<float> point, Mesh* box)
{
	Vector2<float> max = GetMax(box);//maxX, maxY
	Vector2<float>  min = GetMin(box);//minX, minY

	if (point.x >= min.x && point.x <= max.x)
	{
		if (point.y >= min.y && point.y <= max.y)
		{
			return true;
		}
	}
	return false;
}

bool CollisionCheck::Point2HexagonCollision(Vector2<float> point, Mesh* hexagon)
{
	float N = GetDeterminant({ hexagon->GetVertex(1), hexagon->GetVertex(2) }, point);
	float NE = GetDeterminant({ hexagon->GetVertex(2), hexagon->GetVertex(3) }, point);
	float NW = GetDeterminant({ hexagon->GetVertex(3), hexagon->GetVertex(4) }, point);
	float S = GetDeterminant({ hexagon->GetVertex(4), hexagon->GetVertex(5) }, point);
	float SE = GetDeterminant({ hexagon->GetVertex(5), hexagon->GetVertex(6) }, point);
	float SW = GetDeterminant({ hexagon->GetVertex(6), hexagon->GetVertex(1) }, point);

	if (	N > 0
		&& NW > 0
		&& NE > 0
		&& S > 0
		&& SW > 0
		&& SE > 0)
	{
		return true;
	}
	
	return false;
}


Vector2<float> CollisionCheck::GetMin(Mesh* mBox) {
	return mBox->GetVertex(0);
	//return Point(top_left.x, bottom_right.y);
} // bottom-left


Vector2<float> CollisionCheck::GetMax(Mesh* mBox) {
	return mBox->GetVertex(2);
} // top-right

float CollisionCheck::ShortestDistanceSqr(Vector2<float>& p, Vector2<float>::Edge& edge)
{
	Vector2<float> mDot;
	Vector2<float> rToP = { p.x - edge.start.x, p.y - edge.start.y };
	Vector2<float> qToP = { edge.end.x - edge.start.x, edge.end.y - edge.start.y };
	Vector2<float> rToQ = { p.x - edge.end.x,p.y - edge.end.y };
	float lengthQToP = static_cast<float>((qToP.x * qToP.x + qToP.y * qToP.y));

	if (mDot.dot(rToP, qToP) < 0)
	{
		return mDot.dot(rToP, rToP);
	}
	else if (mDot.dot(rToP, qToP) > mDot.dot(qToP, qToP))
	{
		return mDot.dot(rToQ, rToQ);
	}
	else
	{
		return mDot.dot(rToP, rToP) - ((mDot.dot(rToP, qToP) * mDot.dot(rToP, qToP)) / lengthQToP);
	}

}

float CollisionCheck::GetDeterminant(Vector2<float>::Edge edge, Vector2<float> point)
{
	return ((edge.end.x - edge.start.x) * (point.y - edge.start.y)) - ((edge.end.y - edge.start.y) * (point.x - edge.start.x));
}