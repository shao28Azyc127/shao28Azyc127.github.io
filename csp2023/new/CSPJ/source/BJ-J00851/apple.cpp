

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int _maxi = 0;
int _res = 0;
int _day = 0;

void ParseIn () {
  ifstream inFile("apple.in");

  inFile >> _maxi;
  
  inFile.close();
}

void Core () {
  int cc = 0;
  int curInt = 0;
  bool flag = true;
  
  while(_maxi != 0) {
    _day++;

    if(_maxi % 3 == 1 && flag) {
      _res = _day;
      flag = false;
    }
    
    if(_maxi % 3 != 0) {
      _maxi = _maxi - (_maxi / 3) - 1;
    }

    else{
      _maxi = _maxi - (_maxi / 3);
    }
  }
}

void WriteOut () {
  ofstream outFile("apple.out");

  outFile << _day << " " << _res << endl;
  
  outFile.close();
}

int main () {
  ParseIn();
  Core();
  WriteOut();

  return 0;
}
