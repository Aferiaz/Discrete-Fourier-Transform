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

#include "DEBUG.h"

using namespace std;

bool isValidLine(string s, double& signalValue,
                 bool firstLine = false)
{
  stringstream ss(s);

  string arg1, arg2;
  ss >> arg1;
  ss >> arg2;

  int start = 0;
  string extraTest;
  stringstream ss1(arg1), ss2(arg2);

  if(ss1 >> signalValue && !(ss1 >> extraTest))
  {
    if(firstLine)
    {
      ss1.clear();
      ss1.str("");
      ss1 << arg1;

      if(ss1 >> start && !(ss1 >> extraTest) && ss2 >> signalValue &&
         !(ss2 >> extraTest)) return true;

      ss1.clear();
      ss1.str("");
      ss1 << arg1;

      ss1 >> signalValue;
    }
    return true;
  }
  return false;
}

void readFirstLine(ifstream& file, vector<double>& x, bool& fileCheck)
{
  string line;
  double signalValue;

  getline(file, line);
  fileCheck = isValidLine(line, signalValue, true);
  x.push_back(signalValue);
}


void readLines(ifstream& file, vector<double>& x)
{
  string line;
  double signalValue;

  while(getline(file, line))
  {
    if(!isValidLine(line, signalValue)) break;

    x.push_back(signalValue);
  }

  file.close();

  #ifdef DEBUG
    cout << endl << "signals (" << x.size() << ")" << endl;

    for(int i = 0; i < x.size(); i++)
      cout << x[i] << endl;
  #endif
}

void generateOutputFile(string fileName, int n, double* frequency,
                        double* real, double* imaginary,
                        double* magnitude, double* phase)
{
  ofstream oFile;
  oFile.open(fileName, ios_base::app);

  oFile << "frequency \t real part \t imaginary part \n";
  for(int i = 0; i < n; i++)
    oFile << frequency[i] << " \t " << real[i] << " \t "
          << imaginary[i] << " \n";

  oFile << "frequency \t magnitude \t phase \n";
  for(int i = 0; i < n; i++)
    oFile << frequency[i] << " \t " << magnitude[i] << " \t "
          << phase[i] << " \n";

  oFile.close();

  #ifdef DEBUG
    cout << endl << "Discrete fourier transform file " << fileName
         << " appended" << endl;
  #endif
}
