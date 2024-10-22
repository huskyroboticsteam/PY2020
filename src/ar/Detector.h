#pragma once

#include "MarkerSet.h"
#include "Tag.h"

#include <memory>
#include <vector>

#include <opencv2/aruco.hpp>
#include <opencv2/core.hpp>

namespace AR {

/**
   @addtogroup ar
   @{
 */
class Detector {
private:
	std::shared_ptr<MarkerSet> marker_set_;
	cv::Ptr<cv::aruco::DetectorParameters> detector_params_;
	cv::Mat map1_, map2_;
	std::vector<Tag> _detectTagsImpl(const cv::Mat& input,
									 std::vector<std::vector<cv::Point2f>>* rejected,
									 bool undistort);

public:
	Detector();
	Detector(std::shared_ptr<MarkerSet> marker_set,
			 cv::Ptr<cv::aruco::DetectorParameters> detector_params =
				 cv::aruco::DetectorParameters::create());
	std::vector<Tag> detectTags(const cv::Mat& input,
								std::vector<std::vector<cv::Point2f>>& rejected_points,
								bool undistort = true);
	std::vector<Tag> detectTags(const cv::Mat& input, bool undistort = true);
	cv::aruco::DetectorParameters getDetectorParams();
	void setDetectorParams(cv::aruco::DetectorParameters params);
	bool empty() const;
};
/** @} */

} // namespace AR
