/*
  Andreas Josef C. Diaz
  Marc Jefferson B. Obeles
  Justin Gabriel M. Sy

  ENGG 151.01 - A
  Project 2: Discrete Fourier Transform
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#include "DEBUG.h"

using namespace std;

const double pi = atan(1) * 4;

int checkArguments(char** argv)
{
  string tmp;
  stringstream ss;

  for(int i = 2; i <= 4; i++)
  {
    ss.clear();
    ss.str("");
    ss << argv[i];

    double tmp2;

    if(!(ss >> tmp2)) return 1;
    if(ss >> tmp) return 1;
    if(tmp2 <= 0) return 1;
  }

  ss.clear();
  ss.str("");
  ss << argv[5];

  int tmp2;

  if(!(ss >> tmp2)) return 2;
  if(ss >> tmp) return 2;
  if(tmp2 <= 0) return 2;
  return 0;
}

void readArguments(char** argv, double& samplingRate,
                   double& startFreq, double& endFreq, int& nSteps)
{
  samplingRate = stod(argv[2]);
  startFreq = stod(argv[3]);
  endFreq = stod(argv[4]);
  nSteps = stoi(argv[5]);

  #ifdef DEBUG
    cout << endl << "sampling rate: " << samplingRate << endl;
    cout << "start frequency: " << startFreq << endl;
    cout << "end frequency: " << endFreq << endl;
    cout << "nsteps: " << nSteps << endl;
  #endif
}

void fourierTransform(vector<double> x, double samplingRate,
                      double startFreq, double endFreq, int nSteps,
                      double* frequency, double* real,
                      double* imaginary, double* magnitude,
                      double* phase)
{
  int n;
  double analogFreq;
  double digitalFreq;
  double stepSize = (endFreq - startFreq) / nSteps;

  #ifdef DEBUG
    cout << endl << "list of frequencies (" << nSteps + 1 << ")"
         << endl;
    cout << "n \t analog frequency \t digital frequency" << endl;
  #endif

  for(n = 0, analogFreq = startFreq; analogFreq <= endFreq;
      n++, analogFreq += stepSize)
  {
    real[n] = 0;
    imaginary[n] = 0;

    digitalFreq = 2 * pi * analogFreq / samplingRate;

    #ifdef DEBUG
      cout << n << " \t " << setiosflags(ios::fixed)
           << setprecision(5) << analogFreq << " \t\t " << digitalFreq
           << endl;
    #endif

    for(int i = 0; i < x.size(); i++)
    {
      real[n] += x[i] * cos(digitalFreq * i);
      imaginary[n] -= x[i] * sin(digitalFreq * i);
    }

    frequency[n] = analogFreq;
    magnitude[n] = sqrt(pow(real[n], 2) + pow(imaginary[n], 2));
    phase[n] = atan2(imaginary[n], real[n]) * 180 / pi;
  }

  #ifdef DEBUG
    cout << endl << "fourier transform" << endl;
    cout << "frequency \t real \t\t imaginary \t magnitude "
         << "\t phase" << endl;

    for(int i = 0; i <= nSteps; i++)
    {
      cout << setiosflags(ios::fixed) << setprecision(5)
           << frequency[i] << " \t " << real[i] << " \t "
           << imaginary[i] << " \t " << magnitude[i] << " \t "
           << phase[i] << endl;
    }
  #endif
}
