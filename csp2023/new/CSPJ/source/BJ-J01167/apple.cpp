

#include <iostream>
#include <fstream>

using namespace std;

const int MAXI = 1e6 + 9;

long long _day = 1;
long long _theN = 0;
long long _pos = 0;

long long _apple[MAXI];

void ParseIn () {

  ifstream inFile ("apple.in");

  inFile >> _theN;

  for (int i = 1; i < _theN + 1; i++) {
    _apple[i] = 1;
  }

  inFile.close();
}

void Core () {

  bool flag = true;
  int cc = 0;
  
  while (flag) {
    flag = false;
    cc = 0;
    
    for (int i = 1; i < _theN + 1; i++) {

      if (_apple[i] == 0) {
	continue;
      }

      if (cc == 0) {
	//cout << i << ",";
	_apple[i] = 0;
	cc = 3;
	flag = true;

	if (i == _theN) {
	  _pos = _day;
	}
	
      }

      cc--;
      
    }

    cout << endl;

    _day++;
    
  }

  _day -= 2;

}

void CWriteOut () {

  cout << _day << " "<<  _pos << endl;
  
}

void WriteOut () {
  ofstream outFile ("apple.out");
  
  outFile << _day << " " << _pos << endl;

  outFile.close();

}

int main () {

  ParseIn();
  Core();
  //CWriteOut();
  WriteOut();

  return 0;
}
