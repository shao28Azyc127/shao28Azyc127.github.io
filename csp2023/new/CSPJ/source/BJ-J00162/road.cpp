

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> _payList;
vector<int> _distance;
int _num = 0;
int _res = 0;

void ParseIn () {
  int maxi = 0;
  int curInt = 0;
  
  ifstream inFile("road.in");

  inFile >> maxi >> _num;

  for (int i = 0; i < maxi - 1; i++) {
    inFile >> curInt;

    _distance.push_back(curInt);
  }
  for (int i = 0; i < maxi; i++) {
    inFile >> curInt;

    _payList.push_back(curInt);
  }
  
  inFile.close();
}

void Core () {
  int oil = 0;
  int nowNum = 0;
  int goNum = 0;
  int curDis = 0;
  int solo = 0;
  
  while (nowNum != _payList.size() - 1) {
    goNum = nowNum + 1;
    curDis = _distance[goNum - 1];
    
    while (_payList[nowNum] < _payList[goNum] && goNum < _payList.size() - 1) {
      goNum++;
      curDis += _distance[goNum - 1];
      //cout << curDis << endl;
    }
    
    solo = curDis / _num;
    if (curDis % _num != 0) {
      solo++;
    }
    if ((oil + (solo - 1) * _num) > curDis - 1) {
      solo--;
    }
    oil = oil + solo * _num;
    _res += solo * _payList[nowNum];

    //cout << "NOW->" << nowNum << ":GO->" << curDis << ";" << oil << "," << _res << "->";
    //cout << solo * _payList[nowNum] << endl;
    
    oil -= curDis;
    nowNum = goNum;
  }
}

void CWriteOut () {
  cout << _res << endl;
}

void WriteOut () {
  ofstream outFile("road.out");

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
