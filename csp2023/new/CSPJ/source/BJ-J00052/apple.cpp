

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _hash[1000009] = {0};
int _resOne = 0;
int _resTwo = 0;
int _num = 0;

void ParseIn() {
  
  ifstream inFile("apple.in");

  inFile >> _num;
  
  inFile.close();
}

void Core() {

  int cc = 1;
  int num = _num;
  int res = 0;

  while(num > 0) {
    num *= 2;
    num /= 3;
    _resOne++;
  }

  if(_num % 3 == 1) {
    _resTwo = 1;
    return;
  }
  
  for(int i = 1; i < _num + 1; i++) {
    if(_hash[i] == 0) {
      
      cc = 0;
      res++;
      
      for(int m = i; m < _num + 1; m++) {
	
	if(_hash[m] == 0) {
	  cc++;
	}
	 
	if(cc % 3 == 1 && _hash[m] == 0) {
	  _hash[m] = res;
	  if(m == _num) {
	    _resTwo = res;
	    return;
	  }
	}
	
      }
            
    }
  }
}

void WriteOut() {

  ofstream outFile("apple.out");

  outFile << _resOne << ' ' << _resTwo << endl;
  
  outFile.close();

}

int main() {

  ParseIn();
  Core();
  WriteOut();

  return 0;
}
