

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dict{
  string _myStr;
  int _num;
};

int _maxi,_num;
vector<Dict> _myList;
string _res = "";

bool CompareChar(char one,char two) {
  return one > two;
}

bool CompareCharTwo(char one,char two) {
  return one < two;
}

void ParseIn () {
  Dict solo;
  vector<char> curVec;
  char curChar;
  string curStr;
  
  ifstream inFile("dict.in");

  inFile >> _maxi >> _num;

  for(int i = 0; i < _maxi; i++) {
    _res += '0';
    
    for(int m = 0; m < _num; m++) {
      inFile >> curChar;
      curVec.push_back(curChar);
    }

    sort(curVec.begin(),curVec.end(),CompareChar);

    for(int m = 0; m < _num; m++) {
      curStr += curVec[m];
    }

    //   cout << curStr << endl; right
    
    solo._myStr = curStr;
    solo._num = i;

    curVec.clear();
    curStr = "";
    
    _myList.push_back(solo);
  }
  
  inFile.close();
}

bool CompareString(Dict one,Dict two) {

  return one._myStr < two._myStr;
}

void Core () {
  vector<Dict> curVec;
  string curStr = "";
  vector<char> curCharVec;
  
  for(int i = 0; i < _maxi; i++) {
    curVec.clear();
    curVec = _myList;
    curStr = _myList[i]._myStr;

    for(int m = 0; m < curStr.length(); m++) {
      curCharVec.push_back(curStr[m]);
    }

    sort(curCharVec.begin(),curCharVec.end(),CompareCharTwo);   

    curStr = "";
    for(int m = 0; m < _num; m++) {
      curStr += curCharVec[m];
    }

    
    
    curCharVec.clear();
    
    curVec[i]._myStr = curStr;

    sort(curVec.begin(),curVec.end(),CompareString);

    if(curVec[0]._num == i) {
      _res[i] = '1';
    }
  }
}

void WriteOut () {
  ofstream outFile("dict.out");

  outFile << _res << endl;
  
  outFile.close();
}

int main () {
  ParseIn();
  Core();
  WriteOut();
  
  return 0;
}
