

#include <iostream>
#include <fstream>

using namespace std;

int _maxi = 0;

void ParseIn () {
  ifstream inFile("uqe.in");

  inFile >> _maxi;
  
  inFile.close();
}

void Core () {

}

void WriteOut () {
  ofstream outFile("uqe.out");
  
  for (int i = 0; i < _maxi; i++) {
    outFile << "0";
  }

  outFile.close();
}

int main () {
  ParseIn();
  Core();
  WriteOut();

  return 0;
}
