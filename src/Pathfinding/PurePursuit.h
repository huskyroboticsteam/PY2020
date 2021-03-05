#pragma once

#include "../simulator/utils.h"
#include "../Constants.h"
#include <vector>
#include <Eigen/LU>

class PurePursuit {
    private:
        bool activated;
        pose_t curr_pose = {0,0,0};
        pose_t next_point = {0,0,0};
        pose_t last_point = {0,0,0};
        double last_dist = 0;
        double curr_vel = 0;
        double lookahead_dist = 0;
        pose_t getLookaheadPoint();
    public:
        PurePursuit(): last_dist(0.0) {}
        void updateCurrentPos(pose_t currPos, double velocity);
        void updateDistance(double dist, pose_t point);
        double getTurnAngle();
        bool isActivated();
};