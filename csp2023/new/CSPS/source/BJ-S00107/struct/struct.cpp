

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct CaoZuo {
  int _num;
  string _type;
  string _name;
  string _look;
  int _lookNum;
};

const int BYTE = 1;
const int SHORT = 2;
const int INT = 4;
const int LONG = 8;
const int MAXI = 100000;

int _cc = 0;
string _diZhi[MAXI];
vector<CaoZuo> _myList;
vector<string> _resList;

void ParseIn () {
  int maxi = 0;
  string noUse = "";
  int curInt = 0;
  CaoZuo solo;

  ifstream inFile("struct.in");

  inFile >> maxi;

  for (int i = 0; i < maxi; i++) {
    inFile >> curInt;

     solo._num = curInt;
    
    if (curInt == 1) {
      _cc++;
      inFile >> noUse >> curInt;
      
	for (int i = 0; i < curInt; i++) {
	  inFile >> noUse;
	}
    }
    if (curInt == 2) {
      inFile >> solo._type >> solo._name;
    }

    if (curInt == 3) {
      inFile >> solo._look;
    }

    if (curInt == 4) {
      inFile >> solo._lookNum;
    }

    _myList.push_back(solo);
  }
  
  inFile.close();

  //cout << _cc << endl;
}

void Core () {
  CaoZuo solo;
  int cc = 0;
  string curStr = "";
  
  if (_cc != 0) {
    return;
  }

  for (int i = 0; i < MAXI; i++) {
    _diZhi[i] = "ERR";
  }

  for (int i = 0; i < _myList.size(); i++) {
    solo = _myList[i];
    curStr = "";

    //cout << i << endl;
    if (solo._num == 2) {
      if (solo._type == "byte") {
	for (int m = 0; m < BYTE; m++) {
	  _diZhi[cc] = solo._name;
	  cc++;
	}
      }
      if (solo._type == "short") {
	for (int m = 0; m < SHORT; m++) {
	  _diZhi[cc] = solo._name;
	  cc++;
	}
      }
      if (solo._type == "int") {
	for (int m = 0; m < INT; m++) {
	  _diZhi[cc] = solo._name;
	  cc++;
	}
      }
      if (solo._type == "long") {
	for (int m = 0; m < LONG; m++) {
	  _diZhi[cc] = solo._name;
	  cc++;
	}
      }
    }
    if (solo._num == 3) {
      for (int m = 0; m < MAXI; m++) {
	if (_diZhi[m] == solo._look) {
	  curStr += m + '0';
	  
	  _resList.push_back(curStr);
	  break;
	}
      }
    }
    if (solo._num == 4) {
      _resList.push_back(_diZhi[solo._lookNum]);
    }
  }
}

void CWriteOut () {
  for (int i = 0; i < _resList.size(); i++) {
    cout << _resList[i] << endl;
  }
}

void WriteOut () {
  ofstream outFile("struct.out");
  
  for (int i = 0; i < _resList.size(); i++) {
    outFile << _resList[i];
    outFile << endl;
  }

  outFile.close();
}

int main () {
  ParseIn();
  Core();
  WriteOut();
  //CWriteOut();
  
  return 0;
}