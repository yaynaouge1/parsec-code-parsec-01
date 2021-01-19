#include "lib.h"

Mat seuillage(Mat frame)
{
using namespace cv;
float nr = 0;

	while(1){
	    Mat frame_out;
		for (int i=0;i<frame.rows;i++)
		{
           	 for (int j=0;j<frame.cols;j++)
		{
		        uchar r,v,b;
		        b=frame.at<Vec3b>(i,j)[0];
		        v=frame.at<Vec3b>(i,j)[1];
		        r=frame.at<Vec3b>(i,j)[2];
		        nr=r/sqrt((r*r)+(b*b)+(v*v));
		if(nr>0.7)
		    {
		        frame_out.at<Vec3b>(i,j)[0]=0;
		        frame_out.at<Vec3b>(i,j)[1]=r;
		        frame_out.at<Vec3b>(i,j)[2]=r;
		    }
	     else{
		    frame_out.at<Vec3b>(i,j)[0]=b;
		    frame_out.at<Vec3b>(i,j)[1]=v;
		    frame_out.at<Vec3b>(i,j)[2]=r;
		}
		
	}
	}
}
return (frame_out);
}
