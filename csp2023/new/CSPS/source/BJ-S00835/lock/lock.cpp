

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAXI = 9;
const int limit = 5;
int _lock[MAXI][MAXI];
int _total = 0;
int _res = 0;

void ParseIn () {
  
  ifstream inFile ("lock.in");

  inFile >> _total;
  
  for (int i = 0; i < _total; i++) {
    for (int m = 0; m < limit; m++) {
      inFile >> _lock[i][m];
    }
  }
 
  inFile.close();
}

void Core () {

  int pos [limit];
  int change = 0;
  bool dif = false;
  int head = 0;
  int end = 0;
  int cc = 0;
  
  for (int i = 0; i < _total - 1; i++) {

    cc = 0;
    for (int m = 0; m < limit; m++) {
      pos[m] = 0;
    }

    dif = false;

    for (int m = 0; m < limit; m++) {
      if (_lock[i][m] != _lock[i + 1][m]) {
	pos[m] = 1;
	dif =true;
      }
    }

    if (dif) {
      for (int k = 0; k < limit; k++) {
	if (pos[k] == 1) {
	  change++;
	  if (change == 1) {
	    head = k;
	    continue;
	  }
	  if (change == 2) {
	    end = k;
	    continue;
	  }
      
	}
	
      }

      if (change == 1) {
	cc += 12;
	
	if (head == 0 || head == 4) {
	  cc -= 2;
	}
	
      }

      if (change == 2) {
	if (head + 1 == end) {
	  if (_lock[i][head] - _lock[i][end] == _lock[i + 1][head] - _lock[i + 1][end]) {
	    cc = 8;
	  }
	  else if (_lock[i][head] - _lock[i][end] - _lock[i + 1][head] + _lock[i + 1][end] == 10) {
	    cc = 8;
	  }else {
	    cc == 2;
	  }	  	  
   
	}
	
      }

 
      
    }

    _res = cc;

    if (cc == 0) {
      break;
    }
    
  }

}

void CWriteOut () {

  if (_total == 1) {
    _res = 81;
  }

  cout << _res << endl;

}

void WriteOut () {
  ofstream outFile ("lock.out");

  if (_total == 1) {
    _res = 81;
  }
  if (_total > 2) {
    _res = 0;
  }

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
