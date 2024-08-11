

#include <iostream>
#include <fstream>

using namespace std;

string _myStr = "Error";
int _res = 0;
char _myStack[2000009];
int _indica = 0;

void ParseIn () {
  int maxi = 0;
  
  ifstream inFile("game.in");

  inFile >> maxi >> _myStr;
  
  inFile.close();
}

void Push (char solo) {
  _myStack[_indica] = solo;
  _indica++;
}

void Pop () {
  //_myStack[_indica]
  _indica--;
}

bool CheckStr (string solo) {
  _indica = 0;
  
  for (int i = 0; i < solo.length(); i++) {
    Push(solo[i]);

    while (_myStack[_indica - 1] == _myStack[_indica - 2] && _indica != 0) {
      Pop();
      Pop();
    }
  }

  if (_indica == 0) {
    return true;
  }

  return false;
}

void Core () {
  string solo = "";
  
  for (int i = 0; i < _myStr.length(); i++) {
    solo  = _myStr[i];
    //cout << "NOW->" << i << endl;
    
    for (int m = i + 1; m < _myStr.length(); m++) {
      if ((m - i) % 2 == 0) {
	solo += _myStr[m];
	continue;
      }
      solo += _myStr[m];

      //cout << solo << endl;
      
      if (CheckStr(solo)) {
	_res++;
      }
    }
  }
}

void CWriteOut () {
  cout << _res << endl;
}

void WriteOut () {
  ofstream outFile("game.out");

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