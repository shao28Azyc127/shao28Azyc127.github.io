

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

int _num;

void ParseIn () {
  ifstream inFile("expand.in");

  inFile >> _num >> _num >> _num >> _num;
  
  inFile.close();
}

void Core () {

}

void WriteOut () {
  ofstream outFile("expand.out");

  for(int i = 0; i < _num + 1; i++) {
    outFile << rand() % 2;
  }
  outFile << endl;
  outFile.close();
}

int main () {
  srand(time(0));
  
  ParseIn();
  Core();
  WriteOut();
  
  return 0;
}
