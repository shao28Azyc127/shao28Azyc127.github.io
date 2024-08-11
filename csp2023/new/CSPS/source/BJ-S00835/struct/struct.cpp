

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _n = 0;

void ParseIn () {

  ifstream inFile ("tree.in");

  inFile >> _n;

  inFile.close();
  
}

void WriteOut () {

  ofstream outFile ("tree.out");

for (int i = 0; i < _n; i++) {
cout << "ERR" << endl;
{

  outFile.close();

}

int main () {

  ParseIn();
  WriteOut();
  
  return 0;
}
