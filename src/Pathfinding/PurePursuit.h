#ifndef PURE_PURSUIT_H
#define PURE_PURSUIT_H

#include <vector>
#include <Eigen/LU>
#include "./Pather2.h"
#include "../simulator/utils.h"
#include "../Constants.h"

class PurePursuit {
    private:
        bool activated;
        pose_t curr_pose = {0,0,0};
        pose_t next_point = {0,0,0};
        pose_t last_point = {0,0,0};
        double last_dist = 0;
        // double curr_angle;
        double curr_vel = 0;
        double lookahead_dist = 0;
        pose_t getLookaheadPoint();
    public:
        PurePursuit(): last_dist(0) {}
        void updateCurrentPos(point_t currPos, double velocity);
        bool updateDistance(double dist, point_t point);
        double getTurnAngle();
        // double getDirection();
        bool isActivated();
};

#endif