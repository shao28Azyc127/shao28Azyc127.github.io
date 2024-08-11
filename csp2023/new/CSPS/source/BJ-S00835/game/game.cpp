

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string _myStr = "ERROR";
int _len = 0;
int _res = 0;

void ParseIn () {

  ifstream inFile ("game.in");

  inFile >> _len >> _myStr;
  // cout << _len << "," << _myStr << endl;
  inFile.close();
  
}

void Core () {

  int left = 0;
  int right = 0;
  int min = 0;
  int max = 0;
  int size = 0;
  int cc = 0;
  int tog = 0;
  string ans = "ERROR";
  
  for (int i = 0; i < _len - 1; i++) {
    if (_myStr[i] - '0' == _myStr[i + 1] - '0') {
      left = i;
      right = i + 1;
      cc++;
      
      if (left > _len / 2 - 1) {
	size = _len - right - 1;
      }else{
	size = left;
      }

      for (int k = 1; k < size + 1; k++) {
	if (_myStr[left - 1] - '0' == _myStr[right + 1]- '0') {
	  cc++;
	  left = left - 1;
	  right = right + 1;
	}
      }

      if (max != 0) {
	if (left - 1 == max) {
	  max = right;
	  cc += tog;
	  tog++;
	}
      }

      if (max == 0) {
	min = left;
	max = right;
	tog++;
	  
      }
      
    }
  }

  _res = cc;

}

void CWriteOut () {

  cout << _res << endl;
  
}

void WriteOut () {

  ofstream outFile ("game.out");

  outFile << _res << endl;

  outFile.close();

}

int main () {

  ParseIn();
  Core();
  //CWriteOut();
  WriteOut();
  
  return 0;
}
