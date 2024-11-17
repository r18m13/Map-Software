#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <filesystem>
#include <string>

int main() {
    // Path to the video file
    std::string videoPath = "M:/Temp/PXL_20241029_172023595.mp4";

    // Open the video
    cv::VideoCapture cam(videoPath);
    if (!cam.isOpened()) {
        std::cerr << "Error: Unable to open video file!" << std::endl;
        return -1;
    }

    // Get the frames per second (fps) of the video
    double fps = cam.get(cv::CAP_PROP_FPS);

    // Calculate the interval in frames (for 0.5 seconds)
    int frame_interval = static_cast<int>(fps * 0.5); // 0.5 seconds

    // Create a folder named "data" if it doesn't exist
    std::string folderName = "data";
    if (!std::filesystem::exists(folderName)) {
        if (!std::filesystem::create_directory(folderName)) {
            std::cerr << "Error: Unable to create directory 'data'!" << std::endl;
            return -1;
        }
    }

    // Frame counter
    int currentframe = 0;

    while (true) {
        // Set the position of the next frame to capture
        cam.set(cv::CAP_PROP_POS_FRAMES, currentframe);

        // Read a frame
        cv::Mat frame;
        bool ret = cam.read(frame);

        if (ret) {
            // If the video is still left, continue creating images
            std::string filename = folderName + "/frame" + std::to_string(currentframe) + ".jpg";
            std::cout << "Creating..." << filename << std::endl;

            // Testing: Detect and draw ORB keypoints
            cv::Ptr<cv::ORB> orb = cv::ORB::create(5000);
            std::vector<cv::KeyPoint> keypoints;
            cv::Mat descriptors;
            orb->detectAndCompute(frame, cv::noArray(), keypoints, descriptors);

            // Draw keypoints on the image
            cv::Mat outputImage;
            cv::drawKeypoints(frame, keypoints, outputImage, cv::Scalar(0, 255, 0), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

            // Save the output image with keypoints
            cv::imwrite(filename, outputImage);

            // Move to the next frame based on the interval
            currentframe += frame_interval;
        } else {
            break;
        }
    }

    // Release resources
    cam.release();
    cv::destroyAllWindows();

    return 0;
}
