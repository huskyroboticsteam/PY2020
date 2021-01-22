#ifndef PURE_PURSUIT_H
#define PURE_PURSUIT_H

#include <vector>
#include <Eigen/LU>
#include "./Pather2.h"
#include "../simulator/utils.h"
#include "../Constants.h"

class PurePursuit {
    private:
        point_t curr_pos;
        point_t next_point;
        point_t last_point;
        double last_dist;
        double curr_angle;
        double curr_vel;
        double lookahead_dist;
        point_t getLookaheadPoint();
    public:
        PurePursuit(): last_dist(0) {}
        void updateCurrentPos(point_t currPos, double current_angle, double velocity);
        bool updateDistance(double dist, point_t point);
        double getTurnAngle();
        double getDirection();
};

#endif