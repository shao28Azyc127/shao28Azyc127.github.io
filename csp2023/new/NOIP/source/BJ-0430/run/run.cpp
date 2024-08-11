

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pur {
  int _day;
  int _need;
  int _value;
};

vector<Pur> _myList;
vector<long long> _resList;
long long _dp[1009][100009];
bool runList[100009];
int _num = 0;
int _pur = 0;
int _maxi = 0;
int _use = 0;
int _cc = 0;

bool cmp(Pur soloOne, Pur soloTwo) {
  return soloOne._day < soloTwo._day;
}

void Core() {

  sort(_myList.begin(), _myList.end(), cmp);

  long long cc = 0;
  long long res = 0;

  for(int i = 0; i < 1009; i++) {
    _dp[i][0] = 0;
  }

  for(int i = 0; i < 100009; i++) {
    _dp[0][i] = 0;
  }

  for(int i = 1; i < _myList.size() + 1; i++) {
    for(int m = 1; m < _num + 1; m++) {
      _dp[i][m] = _dp[i - 1][m];

      if(m == _myList[i]._day) {
	cc = _myList[i - 1]._value + _dp[i - 1][m - _myList[i - 1]._need] - _use * _myList[i - 1]._need;
	_dp[i][m] = max(_dp[i][m], cc);
      }
    }
  }
  
  res = _dp[_pur][_num];
  _resList.push_back(res);
}

void ParseIn() {

  Pur solo;
  
  ifstream inFile ("run.in");

  inFile >> _cc >> _cc;

  for(int i = 0; i < _cc; i++) {
    inFile >> _num >> _pur >> _maxi >> _use;

    _myList.clear();
    for(int m = 0; m < _pur; m++) {
      inFile >> solo._day >> solo._need >> solo._value;
      _myList.push_back(solo);
    }
    Core();
  }

  inFile.close();
}

void CWriteOut() {
  for(int i = 0; i < _resList.size(); i++) {
    cout << _resList[i] << endl;
  }
}

void WriteOut() {

  ofstream outFile ("run.out");
  for(int i = 0; i < _resList.size(); i++) {
    outFile << _resList[i] << endl;
  }
  outFile.close();
}

int main() {
  
  ParseIn();
  WriteOut();

  return 0;
}
