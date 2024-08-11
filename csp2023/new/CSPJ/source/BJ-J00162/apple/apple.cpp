

#include <iostream>
#include <fstream>

using namespace std;

int _num = 0;
int _res = 0;
int _myArray[1000009];

void ParseIn () {
  ifstream inFile("apple.in");

  inFile >> _num;
  
  inFile.close();
}

void Core () {
  //true->end, false->not end
  bool isEnd = false;
  int cc = _num;
  int number = 1;
  int solo = 0;
  
  while (!isEnd) {
    cc = _num;
    solo = 2;
    
    for (int i = 1; i < _num + 1; i++) {
      if (_myArray[i] != 0) {
	cc--;
	continue;
      }
      if (solo == 2) {
	_myArray[i] = number;

	//cout << number << "->" <<i << endl;
	solo = 0;
	continue;
      }
      solo++;
    }
    
    
    if (cc == 0) {
      isEnd = true;
      continue;
    }
    _res++;
    number++;
  }
}

void CWriteOut () {
  cout << _res << " " << _myArray[_num] << endl;
}

void WriteOut () {
  ofstream outFile("apple.out");

  outFile << _res << " " << _myArray[_num];
  
  outFile.close();
}

int main () {
  ParseIn();
  Core();
  //CWriteOut();
  WriteOut();
  
  return 0;  
}