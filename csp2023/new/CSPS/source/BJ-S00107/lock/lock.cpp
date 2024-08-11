

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct MiMa {
  int _myArray[9];
};

vector<MiMa> _myList;
int _res = 0;

void ParseIn () {
  int maxi = 0;
  MiMa solo;
  int curInt = 0;
  
  ifstream inFile("lock.in");

  inFile >> maxi;

  for (int i = 0; i < maxi; i++) {
    for (int m = 0; m < 5 + 1; m++) {
      inFile >> curInt;

      solo._myArray[i] = curInt;

      }
    _myList.push_back(solo);
  }
  
  inFile.close();
}

void Core () {
  if (_myList.size() == 1) {
    _res = 81;
    return;
  }
}

void CWriteOut () {
  cout << _res << endl;
}

void WriteOut () {
  ofstream outFile("lock.out");

  outFile << _res;
  
  outFile.close();
}

int main () {
  ParseIn();
  Core();
  //CWriteOut();
  WriteOut();
  
  return 0;
}