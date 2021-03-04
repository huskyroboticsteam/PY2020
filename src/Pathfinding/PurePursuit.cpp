#include "./PurePursuit.h"
#include <cmath>

bool PurePursuit::isActivated() {
    return activated;
} 

void PurePursuit::updateCurrentPos(pose_t pos, double velocity) {
    curr_pose = pos;
    curr_vel = velocity;
    last_dist = 0;
    lookahead_dist = Constants::LOOKAHEAD_COEFF * velocity;
    next_point = pos;
    activated = false;
}

void PurePursuit::updateDistance(double dist, point_t point) {
    if (last_dist <= lookahead_dist &&
        dist >= lookahead_dist) {
        last_point = next_point;
        next_point = point;
        activated = true;
    }
    last_dist = dist;
}

double PurePursuit::getTurnAngle() {
    point_t lookahead_point = getLookaheadPoint();
    double dy = lookahead_point[1] - curr_pose[1];
    double dx = lookahead_point[0] - curr_pose[0];
    double alpha = atan2(dy, dx) - curr_pose[2];
    double y = 2 * Constants::ROBOT_LENGTH * sin(alpha);
    double x = lookahead_dist; // K_{dd}v_f 
    return atan2(y, x);
}

// double PurePursuit::getTurnAngle() {
//     return getDirection() - curr_pose[2];
// }

/*
 * Calculates the point between points A and B where
 * the distance to the robot is the lookahead distance.
 * First, it finds the point closest to the robot on the
 * line and then it looks toward B for a point the
 * lookahead distance away from the robot.
 * 
 * Uses y=mx+b and Pythagorean theorem
 */
point_t PurePursuit::getLookaheadPoint() {
    point_t A = last_point;
    point_t B = next_point;
    point_t robot = curr_pose;

    // Line AB
    double m_AB = (B[1] - A[1])/(B[0] - A[0]); // BEWARE denominator 0!!
    double b_AB = A[1] - m_AB * A[0];

    // Get perpendicular line to AB and the correct b value
    double m_inv = -1/m_AB;
    double b_inv = robot[1] - m_inv * robot[0];

    // Find intersction point between two lines
    double x_perp = m_AB - m_inv == 0 ? A[0] : (b_inv - b_AB)/(m_AB - m_inv);
    double y_perp = m_AB * x_perp + b_AB;

    // Calculate distances
    double dx = x_perp - robot[0];
    double dy = y_perp - robot[1];
    double perp_dist_sqr = dx * dx + dy * dy;
    double dist_left = sqrt(lookahead_dist * lookahead_dist - perp_dist_sqr);

    // Get unit vector AB
    dy = B[1] - A[1];
    dx = B[0] - A[0];
    double mag = sqrt(dy * dy + dx * dx);
    point_t unit = {dx / mag, dy / mag};

    // return the point a lookahead distance away from robot
    return {x_perp + dist_left * unit[0], y_perp + dist_left * unit[1]};
}