

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int _maxi;

void ParseIn () {
  int curInt;
  
  ifstream inFile("uqe.in");

  inFile >> _maxi >> curInt;

  for(int i = 0; i < _maxi; i++) {
    inFile >> curInt >> curInt >> curInt;
  }
  
  inFile.close();
}

void Core () {

}

void WriteOut () {
  ofstream outFile("uqe.out");

  for(int i = 0; i < _maxi; i++) {
    outFile << "NO" << endl;
  }
  
  outFile.close();
}

int main () {
  ParseIn();
  Core();
  WriteOut();

  return 0;
}
