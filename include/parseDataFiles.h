#ifndef  PARSE_DATA_FILES_H
#define PARSE_DATA_FILES_H

#include <vector>
#include <Core.h>
#include <Geometry.h>
//#include <ros/ros.h>
#include <lTime.h>
#include <iostream>
#include <fstream>

using namespace Eigen;
using namespace std;

enum dataType{
    isImuData = 0,
    isMocapData = 1
};

struct imuData{
    Vector3f accel;
    Vector3f gyro;
    lTime stamp;
};

struct mocapData{
    Vector3f pos;
    Quaternionf quat;
    lTime stamp;
    lTime receivedTime;
};

class DataFiles{

public:

    ifstream readerMixed;
    ifstream  readerIMU;
    ifstream  readerMocap;


    DataFiles(std::string path);

    int getNext(ifstream &file, mocapData &mocap, imuData &imu, int &type);
    int getNextTimeCorrected(ifstream &mocapFile, ifstream &imuFile, mocapData &mocap, imuData &imu, int &type);
    int getNextNotCorrected(ifstream &mixedFile,mocapData &mocap,imuData &imu,int &type);
    int getNextTimeReceived(ifstream &mocapFile,ifstream &imuFile,mocapData &mocap,imuData &imu,int &type);

};

#endif
