/*
  Andreas Josef C. Diaz
  Marc Jefferson B. Obeles
  Justin Gabriel M. Sy

  ENGG 151.01 - A
  Project 2: Discrete Fourier Transform
*/

#ifndef FOURIERTRANSFORM_H_INCLUDED
#define FOURIERTRANSFORM_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

int checkArguments(char** argv);

void readArguments(char** argv, double& samplingRate,
                   double& startFreq, double& endFreq, int& nSteps);

void fourierTransform(vector<double> x, double samplingRate,
                      double startFreq, double endFreq, int nSteps,
                      double* frequency, double* real,
                      double* imaginary, double* magnitude,
                      double* phase);

#endif // FOURIERTRANSFORM_H_INCLUDED
