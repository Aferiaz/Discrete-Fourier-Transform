/*
  Andreas Josef C. Diaz
  Marc Jefferson B. Obeles
  Justin Gabriel M. Sy

  ENGG 151.01 - A
  Project 2: Discrete Fourier Transform
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

#include "fileIO.h"
#include "fourierTransform.h"
#include "DEBUG.h"

using namespace std;

int main(int argc, char** argv)
{
  if(argc < 6 || argc > 7)
  {
    cout << "Syntax Error: [signal-file] [sampling-rate] " <<
            "[start-freq] [end-freq] [nSteps] (logfile)" << endl;
    return 0;
  }

  ifstream file;
  bool fileCheck;
  vector<double> x;
  double samplingRate, startFreq, endFreq;
  int nSteps;

  file.open(argv[1]);
  if(!file.is_open())
  {
    cout << "Error: Unable to open file" << endl;
    return 0;
  }

  readFirstLine(file, x, fileCheck);
  if(!fileCheck)
  {
    cout << "Error: Invalid signal file" << endl;
    return 0;
  }

  switch(checkArguments(argv))
  {
    case 1:
      cout << "Error: [sampling-rate] [start-freq] [end-freq] " <<
              "should be positive double" << endl;
      return 0;

    case 2:
      cout << "Error: [nSteps] should be a positive integer" << endl;
      return 0;
  }

  readArguments(argv, samplingRate, startFreq, endFreq, nSteps);
  readLines(file, x);

  double * frequency = new double[nSteps + 1];
  double * real = new double[nSteps + 1];
  double * imaginary = new double[nSteps + 1];
  double * magnitude = new double[nSteps + 1];
  double * phase = new double[nSteps + 1];

  fourierTransform(x, samplingRate, startFreq, endFreq, nSteps,
                   frequency, real, imaginary, magnitude, phase);

  generateOutputFile((argc == 7) ? argv[6] : "dftlog.txt", nSteps + 1,
                     frequency, real, imaginary, magnitude, phase);
  return 0;
}
