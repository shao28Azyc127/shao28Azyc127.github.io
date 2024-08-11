

#include <fstream>
#include <iostream>

using namespace std;
string _myStr;
int _res;
int _num;

string eras (string str, int a, int b) {
  string res = "";
  for (int i = 0; i < a; i++) {
    res += str[i];
  }
  for (int i = b+1; i < str.length(); i++) {
    res += str[i];
  }
  return res;
}

bool judge (string str) {
  while (str != "") {
    string tmp = str;
    for (int i = 1; i < str.length(); i++) {
      if (str[i] == str[i-1]) {
	str = eras(str, i-1, i);
      }
    }
    if (tmp == str)
      return false;
  }
  return true;
}

int main () {
  ifstream inFile("game.in");
  ofstream outFile("game.out");
  inFile >> _num;
  inFile >> _myStr;
  for (int i = 0; i < _myStr.length(); i++) {
    for (int j = i; j < _myStr.length(); j++) {
      string str = "";
      for (int k = i; k < j+1; k++) {
	str += _myStr[k];
      }
      if (judge(str)) {
	_res++;
      }
    }
  }
  outFile << _res << endl;
  inFile.close();
  outFile.close();
  return 0;
}
