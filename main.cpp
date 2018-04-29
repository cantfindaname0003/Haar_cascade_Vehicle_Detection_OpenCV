#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace std;
using namespace cv;
CascadeClassifier car_cascade("C:/Users/GrimReaper/Desktop/cars.xml");
// loading trained data set
int main() {
	VideoCapture cap("e:/highway.mp4");
	if (!cap.isOpened())  // check if we succeeded
	{	
		cout << "File Coudn't Be Loaded!\nProgram Will Exit Now." << endl;
		return -1;
	}
	while (1) {
		Mat frame,copy_frame;
		for (int i = 0;i < 5;i++)
			cap >> frame;			//only process every fifth frame
		copy_frame = frame.clone();
		if (frame.empty())cout<<"DSAF	break";
		cvtColor(frame, frame, CV_BGR2GRAY);
		equalizeHist(frame,frame);
		vector<Rect> car;
		car_cascade.detectMultiScale(frame,car ,1.1, 5, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
		//C++: void CascadeClassifier::detectMultiScale(const Mat& image, vector<Rect>& objects, double scaleFactor=1.1, 
		//int minNeighbors=3, int flags=0, Size minSize=Size(), Size maxSize=Size())
		for (auto i : car)
			rectangle(copy_frame,i,Scalar(rand() % 255, rand() % 255, rand() % 255,2));
		imshow("test", copy_frame);
		waitKey(10);
	}
	return 0;
}