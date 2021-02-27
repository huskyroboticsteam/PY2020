#include "../simulator/utils.h"
#include <unistd.h>

void world_interface_init() {
  // TODO implement this: maybe open a socket to the Unity simulator?
  // Maybe launch the Unity simulator?
  // It is guaranteed that we will call this method before calling
  // any of the other methods in this file.
}

bool setCmdVel(double /*dtheta*/, double /*dx*/) {
  // TODO implement this: send a message to the Unity simulator that
  // starts the robot moving with angular velocity dtheta (counterclockwise)
  // and linear velocity dx.
  return true;
}

points_t readLidarScan() {
  // TODO implement: List of lidar hits in the form (x,y,1) where the
  // x and y location are relative to the center of the lidar sensor.
  //
  // Our current lidar sensor has about 4000 beams in a 1D plane with
  // a field of view of about 240 degrees.
  // https://www.roscomponents.com/en/lidar-laser-scanner/83-urg-04lx-ug01.html
  //
  // Should implement noise.
  return {};
}

points_t readLandmarks() {
  // We should implement either this method (a list of locations of AR
  // tags relative to the camera on the rover) or a new method that
  // returns an image captured by the camera.
  //
  // For this method, the index of the point_t in the list corresponds to
  // the ID of that AR tag. If we can't see an AR tag (too far, or behind
  // an obstacle) we should return (0,0,0) at that index in the list.
  return {};
}

transform_t readGPS() {
  // TODO implement: Absolute location and heading of the robot (noisy)
  return toTransform({0,0,0});
}

transform_t readOdom() {
  // Don't worry about implementing this
  return toTransform({0,0,0});
}

URCLeg getLeg(int /*id*/) {
  // Don't worry about implementing this
  return URCLeg { -1, -1, {0.,0.,0.}};
}
