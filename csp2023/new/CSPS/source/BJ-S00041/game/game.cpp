

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool _dp[8009][8009];
string _str = "Error";
int _num = 0;
int _res = 0;

void ParseIn() {
  
  ifstream inFile("game.in");

  inFile >> _num >> _str;
  
  inFile.close();
}

void Core() {
  for(int i = 1; i < _num; i += 2) {
    
    for(int m = 0; m + i < _num; m++) {
      
      if(i == 1) {
	if(_str[m] == _str[m + 1]) {
	  _dp[m][m + i] = 1;
	  _res++;
	}
	continue;
      }

      if(_dp[m + 1][m + i - 1] && _str[m] == _str[m + i]) {
	_dp[m][m + i] = 1;
	_res++;
	continue;
      }

      for(int k = m + 1; k < m + i; k++) {
	if(_dp[m][k] && _dp[k + 1][m + i]) {
	  _dp[m][m + i] = 1;
	  _res++;
	  break;
	}
      }
    }
  }
}

void CWriteOut() {
  cout << _res << endl;
}

void WriteOut() {

  ofstream outFile ("game.out");
  outFile << _res << endl;

  outFile.close();
  
}

int main() {
  
  ParseIn();
  Core();
  WriteOut();

  return 0;
}
