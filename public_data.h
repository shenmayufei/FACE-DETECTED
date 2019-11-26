#ifndef PUBLIC_DATA_H
#define PUBLIC_DATA_H

#include "opencv2/opencv.hpp"

/*
 * version 2.0.1.2
 * used RetinaFace model
 */
#define GJSY_VERSION_EPOCH 2
#define GJSY_VERSION_MAJOR 0
#define GJSY_VERSION_MINOR 1
#define GJSY_VERSION_REVISION 2

//face feature array size
#define FSIZE 512

namespace IODATA {

/*
 * define face 5 landmarks
 * left_eye,right_eye,nose,left_mouth,right mouth
 */
typedef struct FacePts
{
	float x[5];
    float y[5];
} FacePts;

//define face numbers date type
typedef unsigned int FACE_NUMBERS;

//define unsigned date type
typedef unsigned char uchar;

/*
 * Scaling factor, Customization is not supported
 */
typedef enum ScalRatio
{
	//Face structure used
	FACTOR_8_16 = 0x01,
	FACTOR_4_3 = 0x02,
	FACTOR_16_9 = 0x04,
	FACTOR_16_10 = 0x08
} GetScalRatio;

/*
 * Specify to get the face data type
 */
typedef enum GetType
{
	//get face box and feature
	FACEALL = 0x3,
	//get only face box
	FACEBOX = 0x1,
	//get only face feature; unused
	FACEFEATURE = 0x2
} GetFaceType;

/*
 * input value
 * MTCNN关键参数:
 * nms_threshold: 示例nms_threshold[3] = { 0.5, 0.7, 0.7 };
 * threshold: 示例threshold[3] = {0.8, 0.8, 0.8};
 * minsize: 示例minsize = 40;
 * factor: 示例factor = 0.709;
 * featurelayername: 示例featurelayername = "fc1_output";
 */
typedef struct MtcnnPar
{
    int devid;
    int minSize;
    float factor;
    int featureshape[2];
    //RetinaFace used threshold[1]
    float threshold[3];
    //RetinaFace used nms_threshold[0]
    float nms_threshold[3];
    /*
     * MultiScale Dynamic Picture used
     */
    int LongSideSize;
    GetScalRatio scalRatio;
    char *featurelayername;
} MtcnnPar, *pMtcnnPar;

/*
 * output value
 */
typedef struct FaceRect
{
    int x1;
    int y1;
    int x2;
    int y2;
    float score;
    float feature[FSIZE];
    FacePts facepts;

	/*
	 * roll,pitch,yaw; unused
	 */
    double roll;
    double pitch;
    double yaw;
    float regression[4];
} FaceRect, *pFaceRect;

} //namespace IODATA

#endif // PUBLIC_DATA_H
