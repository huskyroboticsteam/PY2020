#include <algorithm>
#include <cmath>
#include <iostream>
#include "AStar.h"

using namespace Astar;
using namespace std;

void Pather::updateMap(const vector<PointXY>& obstacles, float robotX, float robotY) {
    obsMap.update(obstacles, robotX, robotY);
}

bool Pather::isValid(PointXY pt) {
    if (pt.x >= obsMap.size || pt.y >= obsMap.size || pt.x < 0 || pt.y < 0) {
        return false;
    }

    return obsMap.obstacle_map[static_cast<int> (pt.x)][static_cast<int> (pt.y)];
}

bool Pather::isDestination(PointXY pt, PointXY dest) {
    return pt.x == dest.x && pt.y == dest.y;
}

double Pather::calculateHScore(PointXY pt, PointXY dest) {
    return (sqrt((pt.x - dest.x)*(pt.x - dest.x)
            + (pt.y - dest.y)*(pt.y - dest.y)));
}

vector<Node> Pather::AStarSearch(PointXY src, PointXY dest) {
    vector<Node> emptyList;
    if (!isValid(dest)) {
        cout << "Destination is invalid" << endl;
        return emptyList;
    }
    
    if (isDestination(src, dest)) {
        cout << "Robot is at destination" << endl;
        return emptyList;
    }
}