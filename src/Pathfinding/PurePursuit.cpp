#include "./PurePursuit.h"
#include <cmath>

void PurePursuit::updateCurrentPos(point_t pos, double angle, double velocity) {
    curr_pos = pos;
    curr_angle = angle;
    curr_vel = velocity;
    last_dist = 0;
}

bool PurePursuit::updateDistance(double dist, point_t point) {
    if (last_dist <= Constants::LOOKAHEAD_DISTANCE &&
        dist >= Constants::LOOKAHEAD_DISTANCE) {
        next_point = point;
    }
    last_dist = dist;
}

double PurePursuit::getDirection() {
    double alpha = atan2(next_point[1] - curr_pos[1], next_point[0] - curr_pos[0]) - curr_angle;
    double y = 2 * Constants::ROBOT_LENGTH * sin(alpha);
    double x = Constants::LOOKAHEAD_DISTANCE * curr_vel;
    return atan2(y, x);
}