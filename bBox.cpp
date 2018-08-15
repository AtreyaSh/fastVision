#include <opencv2/opencv.hpp>
// selectROI is part of tracking API
#include <opencv2/tracking.hpp>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;
using namespace cv;

int main (int argc, char **arv)
{
    // Read image
    Mat im = imread("./data/test.png");
    string input = "yes";
    vector<Rect2d> rects;
    vector<int> myV;
    int j = 0;

    while(input == "yes"){
      // figure out how to clear memory on each iteration
      // issue with new window always being behind others

      if(j > 0){
        rectangle(im, rects[j-1], Scalar(255,0,0), 1.5, 8, 0);
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

    for(int i = 0; i < rects.size(); i++){
      myV.push_back(rects[i].x);
      myV.push_back(rects[i].y);
      myV.push_back(rects[i].height);
      myV.push_back(rects[i].width);
    }

    ofstream myfile("./results/results.csv");
    int vsize = myV.size();

    myfile << "x" << ",";
    myfile << "y" << ",";
    myfile << "height" << ",";
    myfile << "width" << "\r";

    for(int n = 0; n < vsize; n++){
      if((n+1)%4 != 0)
      {
          myfile << myV[n] << ',';
      }
      else
      {
        myfile << myV[n] << '\r';
      }
    }

    // this could then later be imported for use with tesseract
    // clear memory of myV at the end and delete all data
    im.release();
    waitKey(0);
    return 0;
}
