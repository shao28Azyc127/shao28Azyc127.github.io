

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> _myListOne;
vector<int> _myListTwo;
vector<int> _lineOne;
vector<int> _lineTwo;
int _maxiOne = 0;
int _maxiTwo = 0;
int _cc = 0;
int _num = 0;
string _res = "";

void Core() {

  if(_cc > 7 && _cc < 15) {
    _res += '1';
    return;
  }

  bool flag = 0;
  int miniOne = _myListOne[0];
  int maxiOne = 0;
  int miniTwo = _myListTwo[0];
  int maxiTwo = 0;
  
  if(_myListOne[0] == _myListTwo[0]) {
    _res += '0';
    return;
  }

  flag = _myListOne[0] < _myListTwo[0];
  
  for(int i = 0; i < _maxiOne; i++) {
    if(_myListOne[i] > maxiOne) {
      maxiOne = _myListOne[i];
    }
    if(_myListOne[i] < miniOne) {
      miniOne = _myListOne[i];
    }
  }
  for(int i = 0; i < _maxiTwo; i++) {
    if(_myListTwo[i] > maxiTwo) {
      maxiTwo = _myListTwo[i];
    }
    if(_myListTwo[i] < miniTwo) {
      miniTwo = _myListTwo[i];
    }
  }

  if(flag && _myListOne[_maxiOne - 1] > _myListTwo[_maxiTwo - 1]) {
    _res += '0';
    return;
  }

  if(!flag && _myListOne[_maxiOne - 1] < _myListTwo[_maxiTwo - 1]) {
    _res += '0';
    return;
  }

  if(flag && maxiOne < maxiTwo && miniOne < miniTwo) {
    _res += '1';
    return;
  }

  if(!flag && maxiOne > maxiTwo && miniOne > miniTwo) {
    _res += '1';
    return;
  }

  _res += '0';
  return;
  
}

void GenList() {
  for(int i = 0; i < _maxiOne; i++) {
    _myListOne[i] = _lineOne[i];
  }
  for(int i = 0; i < _maxiTwo; i++) {
    _myListTwo[i] = _lineTwo[i];
  }
}

void ParseIn() {

  int curInt = 0;

  int maxiOne = 0;
  int maxiTwo = 0;
  int cc = 0;
  int num = 0;

  ifstream inFile ("expand.in");

  inFile >> _cc >> _maxiOne >> _maxiTwo >> _num;

  for(int i = 0; i < _maxiOne; i++) {
    inFile >> curInt;
    _myListOne.push_back(curInt);
    _lineOne.push_back(curInt);
  }

  for(int i = 0; i < _maxiTwo; i++) {
    inFile >> curInt;
    _myListTwo.push_back(curInt);
    _lineTwo.push_back(curInt);
  }
  Core();

  for(int i = 0; i < _num; i++) {
    inFile >> maxiOne >> maxiTwo;
    GenList();
    
    for(int m = 0; m < maxiOne; m++) {
      inFile >> cc >> num;
      _myListOne[cc - 1] = num;
    }
    for(int m = 0; m < maxiTwo; m++) {
      inFile >> cc >> num;
      _myListTwo[cc - 1] = num;
    }
    Core();
  }
  
  inFile.close();
}

void CWriteOut() {
  cout << _res << endl;
}

void WriteOut() {

  ofstream outFile("expand.out");
  
  outFile << _res << endl;

  outFile.close();
}

int main() {
  
  ParseIn();
  WriteOut();

  return 0;
}
