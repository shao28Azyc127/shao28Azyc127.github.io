

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _num = 0;

void ParseIn() {
  ifstream inFile ("tree.in");

  inFile >> _num;

  inFile.close();
}

void WriteOut() {
  ofstream outFile ("tree.out");

  outFile << _num + 1 << endl;
  
  outFile.close();
}

int main() {

  ParseIn();
  //Core();
  WriteOut();

  return 0;
}
