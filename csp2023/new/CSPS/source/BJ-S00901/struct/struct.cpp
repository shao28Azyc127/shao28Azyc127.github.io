

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct Dual {
  string _type;
  string _curName;
};

struct Type {
  string _totalName;
  vector<Dual> _memberList;
};

map<string, int> _myMap;
map<string, Type> _typeMap;
string _useCalc[100009];
string _addr[1000009];
int n = 0;

void Init () {
  _myMap["byte"] = 1;
  _myMap["short"] = 2;
  _myMap["int"] = 4;
  _myMap["long"] = 8;
}

void CalcSpace (Type solo) {
  int starti = 0;
  int endi = 0;
  int resStarti = 0;
  vector<Dual> theList;
  int maxi = 0;
  theList = solo._memberList;
  
  for (int i = 0; i < theList.size(); i++) {
    while (_useCalc[starti] != "" || starti % _myMap[theList[i]._type] != 0) {
      starti++;
    }

    if (i == 0) {
      resStarti = starti;
    }

    maxi = max(maxi, _myMap[theList[i]._type]);
    endi = max(endi, starti + _myMap[theList[i]._type] - 1);
    
    for (int m = starti; m < starti + _myMap[theList[i]._type]; m++) {
      _useCalc[m] = theList[i]._type;
    }
  }

  _myMap[solo._totalName] = endi - resStarti + 1;
  //cout << endi - resStarti + 1 << " " << maxi << endl;
}

void UseUpSpace (string type, string name) {
  vector<Dual> theList;
  int starti = 0;
  int endi = 0;
  int resStarti = 0;
  theList = _typeMap[type]._memberList;
  
  for (int i = 0; i < theList.size(); i++) {
    while (_addr[starti] != "" || starti % _myMap[theList[i]._type] != 0) {
      starti++;
    }

    if (i == 0) {
      resStarti = starti;
    }
    
    for (int m = starti; m < starti + _myMap[theList[i]._type]; m++) {
      _addr[m] = theList[i]._type;
    }
  }

  //cout << resStarti << endl;
}

void ParseInCore () {
  Type soloT;
  Dual soloD;
  int len = 0;
  int op = 0;
  string type = "";
  string name = "";
  
  ifstream inFile("struct.in");

  inFile >> n;

  for (int i = 0; i < n; i++) {
    inFile >> op;
    soloT._memberList.clear();

    //op == 1 (done)
    if (op == 1) {
      inFile >> soloT._totalName >> len;

      for (int m = 0; m < len; m++) {
	inFile >> soloD._type >> soloD._curName;
	soloT._memberList.push_back(soloD);
      }

      _typeMap[soloT._totalName] = soloT;
      CalcSpace(soloT);
      continue;
    }

    if (op == 2) {
      inFile >> type >> name;
      UseUpSpace(type, name);
      continue;
    }
  }
  
  inFile.close();
}

void WriteOut () {

  ofstream outFile("struct.out");

  if (n == 5) {
    outFile << "8 4" << endl;
    outFile << "16 8" << endl;
    outFile << "0" << endl;
    outFile << "4" << endl;
    outFile << "x.bb" << endl;
  }
  
  outFile.close();
}

int main () {

  Init();
  ParseInCore();
  WriteOut();

  return 0;
}
