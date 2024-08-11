

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Str {
  char _mini;
  char _maxi;
};

string _res = "";
int _num = 0;
int _cc = 0;
vector<Str> _myList;

void ParseIn() {

  char str = 'E';
  Str solo;
  solo._mini = 'z';
  solo._maxi = 'a';
  
  ifstream inFile ("dict.in");

  inFile >> _num >> _cc;

  for(int i = 0; i < _num; i++) {
    solo._mini = 'z';
    solo._maxi = 'a';
    
    for(int m = 0; m < _cc; m++) {
      inFile >> str;

      if(str > solo._maxi) {
	solo._maxi = str;
      }
      if(str < solo._mini) {
	solo._mini = str;
      }
    }

    _myList.push_back(solo);
  }
  
  inFile.close();
}

void Core() {

  bool flag = 1;
  
  for(int i = 0; i < _num; i++) {

    flag = 1;
    for(int m = 0; m < _num; m++) {
      if(i == m) {
	continue;
      }
      if(_myList[i]._mini < _myList[m]._maxi) {
	continue;
      }
      _res += '0';
      flag = 0;
      break;
    }

    if(flag) {
      _res += '1';
    }
  }
}

void CWriteOut() {
  cout << _res << endl;
}

void WriteOut() {

  ofstream outFile ("dict.out");
  
  outFile << _res << endl;

  outFile.close();
}

int main() {

  ParseIn();
  Core();
  WriteOut();

  return 0;
}
