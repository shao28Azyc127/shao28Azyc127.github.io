

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int _maxi;
string _myStr;
int _res = 0;
bool _flag = true;

void ParseIn () {
  ifstream inFile("game.in");

  inFile >> _maxi >> _myStr;
  
  inFile.close();
}

void Check(string solo) {
  string res = "";

  solo += '0';
  
  // cout << solo << " ";
  
  if(solo.length() == 1) {
    _flag = true;
    return;
  }
  
  for(int i = 0; i < solo.length() - 1; i++) {
    if(solo[i] == solo[i + 1]) {
      i++;
      continue;
    }

    res += solo[i];
  }

  if(res.length() == solo.length() - 1) {
    _flag = false;
    return;
  }

  Check(res);
}

void Core () {
  string solo = "";
  
  for(int i = 0; i < _myStr.size(); i++) {
    for(int m = i; m < _myStr.size() + 1; m++) {
      _flag = false;
      solo = "";
      
      if(i - m == 0 || (i - m) % 2 != 0) {
	continue;
      }

      for(int k = i; k < m; k++) {
	solo += _myStr[k];
      }

      Check(solo);
      //    cout << endl;
      if(_flag) {
	_res++;
      }
    }
  }
}

void WriteOut () {
  ofstream outFile("game.out");

  outFile << _res << endl;
  
  outFile.close();
}

int main () {
  ParseIn();
  Core();
  WriteOut();

  return 0;
}
