

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

int _num;

void ParseIn () {
  ifstream inFile("run.in");

  inFile >> _num ;
  
  inFile.close();
}

void Core () {

}

void WriteOut () {
  ofstream outFile("run.out");

  outFile << 2 << endl;
  
  outFile.close();
}

int main () {
  srand(time(0));
  
  ParseIn();
  Core();
  WriteOut();
  
  return 0;
}
