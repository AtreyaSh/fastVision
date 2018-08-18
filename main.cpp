#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include "./aux/writeCsv.h"

using namespace std;
using namespace cv;

int main (int argc, char **arv)
{
    // define variables
    Mat im = imread("./dataC/test.png");
    string input = "yes";
    vector<Rect2d> rects;
    vector<double> myV;
    vector<string> header = {"x", "y", "width", "height"};
    string path;
    int j = 0;
    int oX = im.cols;
    int oY = im.rows;

    // iterative while loop
    while(input == "yes"){

      if(j > 0){
        // redefine image and remove window problem
        rectangle(im, rects[j-1], Scalar(255,0,0), 1.5, 8, 0);
        namedWindow("GetFocus", CV_WINDOW_NORMAL);
        Mat img = cv::Mat::zeros(100, 100, CV_8UC3);
        imshow("GetFocus", img);
        setWindowProperty("GetFocus", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
        waitKey(1);
        setWindowProperty("GetFocus", CV_WND_PROP_FULLSCREEN, CV_WINDOW_NORMAL);
        destroyWindow("GetFocus");
      }

      bool fromCenter = false;
      Rect2d r = selectROI("Image", im, fromCenter);

      if(r.x != 0 & r.y != 0 & r.height != 0 & r.width != 0){
        rects.push_back(r);
      }

      cvDestroyWindow("Image");

      input = "init";

      while(input != "yes" & input != "no"){
        cout << "Do you want to select another ROI? (yes|no): ";
        cin >> input;
      }

      j++;
    }

    // collate results and divide for aspect-ratio invariance
    for(int i = 0; i < rects.size(); i++){
      myV.push_back(rects[i].x/oX);
      myV.push_back(rects[i].y/oY);
      myV.push_back(rects[i].width/oX);
      myV.push_back(rects[i].height/oY);
    }

    // write myV results
    writeCsv_h::writeCsv(path = "./results/results.csv", myV, header);

    im.release();
    waitKey(0);
    return 0;
}
