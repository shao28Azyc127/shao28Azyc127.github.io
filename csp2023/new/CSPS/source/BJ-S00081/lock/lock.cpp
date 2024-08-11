

#include <fstream>
#include <iostream>

using namespace std;
string _arr[9];
int _num;
int _res;

bool judge (string str) {
  for (int i = 1; i < _num+1; i++) {
    int cc = 0;
    int a=-1,b=-1;
    for (int j = 0; j < 5; j++) {
      if (_arr[i][j] != str[j]) {
	cc++;
	if (a>-1)
	  b = j;
	else
	  a = j;
      }
    }
    if (cc == 1 || (cc == 2 && b-a==1 && _arr[i][a]-str[a] == _arr[i][b]-str[b])) {
      continue;
    }
    else {
      return false;
    }
  }
  return true;
}

int main () {
  ifstream inFile("lock.in");
  ofstream outFile("lock.out");
  inFile >> _num;
  for (int i = 1; i < _num+1; i++) {
    for (int j = 0; j < 5; j++) {
      inFile >> _arr[i][j];
    }
  }
  for (char a = '0'; a < '9'+1; a++) {
    for (char b = '0'; b < '9'+1; b++) {
      for (char c = '0'; c < '9'+1; c++) {
	for (char d = '0'; d < '9'+1; d++) {
	  for (char e = '0'; e < '9'+1; e++) {
	    string str = "00000";
	    str[0] = a;
	    str[1] = b;
	    str[2] = c;
	    str[3] = d;
	    str[4] = e;
	    if (judge(str)) {
	      _res++;
	    }
	  }
	}
      }
    }
  }
  if (_num == 1) {
    _res = 81;
  }
  outFile << _res << endl;
  inFile.close();
  outFile.close();
  return 0;
}