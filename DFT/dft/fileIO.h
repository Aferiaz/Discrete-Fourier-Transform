/*
  Andreas Josef C. Diaz
  Marc Jefferson B. Obeles
  Justin Gabriel M. Sy

  ENGG 151.01 - A
  Project 2: Discrete Fourier Transform
*/

#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

bool isValidLine(string s, double& signalValue,
                 bool firstLine = false);

void readFirstLine(ifstream& file, vector<double>& x,
                   bool& fileCheck);

void readLines(ifstream& file, vector<double>& x);

void generateOutputFile(string fileName, int n, double* frequency,
                        double* real, double* imaginary,
                        double* magnitude, double* phase);

#endif // FILEIO_H_INCLUDED
