

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int _maxi,_num;
int _res = 0;
vector<int> _myList;
vector<int> _kmList;

void ParseIn () {
  int curInt;

  ifstream inFile("road.in");

  inFile >> _maxi >> _num;

  for(int i = 0; i < _maxi - 1; i++) {
    inFile >> curInt;
    _myList.push_back(curInt);
  }

  for(int i = 0; i < _maxi; i++){
    inFile >> curInt;
    _kmList.push_back(curInt);
  }
  
  inFile.close();
}

void Core () {
  int nowMin = _kmList[0];
  long long cc = 0;
  long long curInt = 0;
  
  for(int i = 1; i < _maxi; i++) {
    curInt += _myList[i - 1];

    if(curInt > cc) {
      if((curInt - cc) % _num != 0) {
	_res += (curInt - cc) / _num * nowMin + nowMin;
	cc = cc + ((curInt - cc) / _num + 1) * _num;
      }

      else{
	_res += (curInt - cc) / _num * nowMin;
	cc = curInt;
      }
    }

    if(nowMin > _kmList[i]) {
      nowMin = _kmList[i];
    }
  }
}

void WriteOut () {
  ofstream outFile("road.out");

  outFile << _res << endl;
  
  outFile.close();
}

int main () {
  ParseIn();
  Core();
  WriteOut();

  return 0;
}
