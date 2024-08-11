

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _num = 0;
int _res = 0;
int _myMap[10][5];

void Display(int line[5]) {
  for(int i = 0; i < 5; i++) {
    cout << line[i];
  }
  cout << endl;
}

bool GetRes(int solo) {

  int line[5] = {0};
  int num = solo;
  bool flag = 0;
  int cc = 0;

  for(int i = 0; i < 5; i++) {
    line[4 - i] = num % 10;
    num /= 10;
    
  }
  
  
  for(int i = 0; i < _num; i++) {
    flag = 0;
    
    for(int m = 0; m < 5; m++) {
      
      if(line[m] != _myMap[i][m]) {
	
	if(!flag) {
	  flag = 1;
	  cc = line[m] - _myMap[i][m];
	  if(line[m + 1] - _myMap[i][m + 1] == cc - 10 || line[m + 1] - _myMap[i][m + 1] == cc + 10 || line[m + 1] - _myMap[i][m + 1] == cc && m < 4) {
	    m++;
	    
	  }
	  
	  continue;
	}
	
	return false;
	
      }
    }
    if(!flag) {
      return false;
    }
    
  }
  
  //Display(line);
  return true;
}

void ParseIn() {

  ifstream inFile("lock.in");

  inFile >> _num;

  for(int i = 0; i < _num; i++) {
    for(int m = 0; m < 5; m++) {
      inFile >> _myMap[i][m];
    }
  }
  
  inFile.close();
}

void Core() {
  
  for(int i = 0; i < 100000; i++) {
    if(GetRes(i)) {
      _res++;
    }
    
  }
}

void CWriteOut() {
  cout << _res << endl;
}

void WriteOut() {

  ofstream outFile ("lock.out");

  outFile << _res << endl;
  
  outFile.close();
  
}

int main() {

  ParseIn();
  Core();
  WriteOut();

  return 0;
}