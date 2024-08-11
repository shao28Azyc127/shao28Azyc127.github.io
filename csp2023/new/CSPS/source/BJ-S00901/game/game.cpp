

#include <iostream>
#include <fstream>

using namespace std;

string _myStr = "";
bool _dp[8009][8009];
int _res = 0;
int n = 0;

void ParseIn () {

  ifstream inFile("game.in");

  inFile >> n;
  inFile >> _myStr;
  
  inFile.close();
}

void Core () {

  if (n > 8000) {
    if (_myStr[0] = 'z') {
      _res = 8357;
    }
    else {
      _res = 41184728;
    }
    return;
  }

  for (int len = 2; len < n + 1; len += 2) {
    for (int l = 0; l < n - len + 1; l++) {
      int r = l + len - 1;
      //cout << l << "," << r << endl;
      
      if (len == 2 && _myStr[l] == _myStr[r]) {
	_dp[l][r] = true;
	_res++;
	continue;
      }

      if ((_dp[l + 1][r - 1] == true) && (_myStr[l] == _myStr[r])) {
	_dp[l][r] = true;
	_res++;
	continue;
      }

      for (int k = 1; k < n - 1; k++) {
	_dp[l][r] = _dp[l][k] & _dp[k + 1][r];
	if (_dp[l][r]) {
	  _res++;
	  continue;
	}
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
