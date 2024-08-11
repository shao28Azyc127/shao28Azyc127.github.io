

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int _maxi;
vector<string> _myList;
int _res = 0;

void ParseIn () {
  string solo;
  char curChar;
  //cout << (-9) % 10 << endl;
  ifstream inFile("lock.in");

  inFile >> _maxi;

  for(int i = 0; i < _maxi; i++) {
    solo = "";
    
    for(int m = 0; m < 5; m++) {
      inFile >> curChar;
      solo += curChar;
    }
    _myList.push_back(solo);
    // cout << solo << endl;
  }
  
  inFile.close();
}

int abs(char solo,char curChar){
  if(solo - curChar < 0) {
    return  int(solo - curChar) + 10;
  }
  return int(solo - curChar);
}

bool CheckOther(string solo,string curStr) {
  int cc = 0;

  for(int i = 0; i < 5; i++) {
    if(solo[i] != curStr[i]) {
      cc++;
    }
  }

  if(cc == 1) {
    return true;
  }

  if(cc > 2) {
    return false;
  }
  
  for(int i = 0; i < 4; i++) {
    if(solo[i] != curStr[i] && solo[i + 1] != curStr[i + 1]) {
      if(abs(solo[i], curStr[i]) != abs(solo[i + 1] ,curStr[i + 1])) {
	return false;
      }
      
      return true;
    }
  }

  return false;
}

void Core () {
  string solo = "";
  int cc = 0;
  bool flag = false;

  for(int i = 0; i < 5; i++) {
    solo = _myList[0];

    for(int m = 1; m < 10; m++) {
      flag = false;
      solo = _myList[0];
      solo[i] = char(((int(solo[i]) - '0') + m) % 10 + '0');
      
      for(int d = 0; d < _myList.size(); d++) {
	if(!CheckOther(solo,_myList[d])){
	  flag = true;
	}
      }
      
      if(!flag) {
	_res++;
      }
    }
  }
  
  for(int i = 0; i < 4; i++) {
    solo = _myList[0];

    
    for(int m = 1; m < 10; m++) {
      solo = _myList[0];
      solo[i] = char(((int(solo[i]) - '0') + m) % 10 + '0');
      solo[i + 1] = char(((int(solo[i + 1]) - '0') + m) % 10 + '0');
      flag = false;

      for(int d = 0; d < _myList.size(); d++) {
	if(!CheckOther(solo,_myList[d])) {
	  flag = true;
	}
	
      }
      if(!flag) {
	_res++;
      }      
    }
  }

}
  
void WriteOut () {
  ofstream outFile("lock.out");

  outFile << _res << endl;
  
  outFile.close();
}

int main () {
  ParseIn();
  Core();
  WriteOut();

  return 0;
}
