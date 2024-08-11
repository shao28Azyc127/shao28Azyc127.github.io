

#include <iostream>
#include <fstream>

using namespace std;

void ParseIn () {
  int curInt = 0;

  ifstream inFile("bus.in");

  while (inFile >> curInt) {
    curInt = 0;
  }
  
  inFile.close();
}

void Core () {
  //nothing
}

void WriteOut () {
  ofstream outFile("bus.out");
  
  outFile << -1;

  outFile.close();
}

int main () {
  ParseIn();
  Core();
  WriteOut();

  return 0;
}