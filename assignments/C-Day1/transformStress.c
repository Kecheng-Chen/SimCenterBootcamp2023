// program to transform stress:
//
// sigmaX' = sigmaX * cos^2(theta) + sigmaY * sin^2(theta) + 2 * tauXY Sin(theta)Cos(theta)
// sigmaY' = sigmaX * sin^2(theta) + sigmaY * cos^2(theta) - 2 * tauXY Sin(theta)Cos(theta)
// tauXY' = (sigmaY-sigmaX) * sin(theta)cos(theta) + tauXY(cos^2(theta) - sin^2(theta))
//
// write a program to take:
// 1: 4 inputs: sigmaX, sigmaY, tauXY, theta and output transformed stresses: sigmaX', sigmaY', tauXY'
// 2: 3  inputs: sigmaX, sigmaY, tauXY and output transformed stresses: sigmaX', sigmaY', tauXY' for every 10 degrees
//
// NOTE: perform the transformation inside a function that cannot be named main
//
// Extend to possibly include all outputs for a Mohr circle, were the theta now provided is a deltaTheta

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void transformStress(float *stressIN, float theta, float *stressTransformed);

int main(int argc, char **argv) {
  
  double sigmaX=0, sigmaY=0, tauXY=0, theta=0;
  sigmaX=atof(argv[1]);
  sigmaY=atof(argv[2]);
  tauXY=atof(argv[3]);
  float stressIN[3] = {sigmaX,sigmaY,tauXY};
  float stressOut[3] = {0,0,0};

  if (argc==5) {
    theta=atof(argv[4]);
    transformStress(stressIN,theta,stressOut);
    sigmaX=stressOut[0];
    sigmaY=stressOut[1];
    tauXY=stressOut[2];
    printf("%.4f, %.4f, %.4f\n", sigmaX, sigmaY, tauXY);
  } else if (argc==4) {
    for (int i=0;i<360;i=i+10) {
      transformStress(stressIN,i,stressOut);
      sigmaX=stressOut[0];
      sigmaY=stressOut[1];
      tauXY=stressOut[2];
      printf("%.4f, %.4f, %.4f\n", sigmaX, sigmaY, tauXY);
    }
  }
  return 0;
}

void transformStress(float *stressIN, float theta, float *stressTransformed) {
  stressTransformed[0]=stressIN[0]*(cos(theta/180*3.14159265358979323846)*cos(theta/180*3.14159265358979323846))+stressIN[1]*(sin(theta/180*3.14159265358979323846)*sin(theta/180*3.14159265358979323846))+2*stressIN[2]*(sin(theta/180*3.14159265358979323846)*cos(theta/180*3.14159265358979323846));
  stressTransformed[1]=stressIN[0]*(sin(theta/180*3.14159265358979323846)*sin(theta/180*3.14159265358979323846))+stressIN[1]*(cos(theta/180*3.14159265358979323846)*cos(theta/180*3.14159265358979323846))-2*stressIN[2]*(sin(theta/180*3.14159265358979323846)*cos(theta/180*3.14159265358979323846));
  stressTransformed[2]=(stressIN[1]-stressIN[0])*(sin(theta/180*3.14159265358979323846)*cos(theta/180*3.14159265358979323846))+stressIN[2]*(cos(theta/180*3.14159265358979323846)*cos(theta/180*3.14159265358979323846)-sin(theta/180*3.14159265358979323846)*sin(theta/180*3.14159265358979323846));
}
