#ifndef AStar_H
#define AStar_H

#include <vector>
#include <set>
#include "../math/PointXY.h"
#include "ObstacleMap.h"

using namespace std;

namespace Astar {

    // Struct of a Node represent each square on the grid
    struct Node {
        PointXY point;
        PointXY parentPoint;
        double gScore, fScore, hScore;
    };

    // Class to generate a Pathfinding object
    class Pather {
        public:
            // Constructor for pathfinding object
            Pather();
            // Check to see if the current point is valid
            bool isValid(PointXY);
            // Check to see if the given point is destination
            bool isDestination(PointXY point, PointXY dest);
            // Find the shortest path to the destination and return list of the coordinates of that path
            vector<Node> AStarSearch(PointXY src, PointXY dest);
            // Update the obstacle map
            void updateMap(const std::vector<PointXY>& obstacles, float robotX, float robotY);
            // Calculate H score
            double calculateHScore(PointXY pt, PointXY dest);
            

        private:
            ObstacleMap obsMap;
            
    };
}


#endif  // endif AStar_H