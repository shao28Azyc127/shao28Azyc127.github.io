

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> _myList;
vector<int> _price;
int _num = 0;
int _cc = 0;
long long _res = 0;

void ParseIn() {

  int curInt = 0;
  
  ifstream inFile ("road.in");

  inFile >> _num >> _cc;

  for(int i = 1; i < _num; i++) {
    inFile >> curInt;
    _myList.push_back(curInt);
  }

  for(int m = 0; m < _num; m++) {
    inFile >> curInt;
    _price.push_back(curInt);
  }
  
  inFile.close();
}

void Core() {

  long long price = _price[0];
  long long distance = 0;
  long long res = 0;

  for(int i = 1; i < _num; i++) {

    distance += _myList[i - 1];
  
    if(i == _num - 1) {
      res = distance / _cc;
      
      if(distance % _cc > 0) {
	res ++;
      }
      _res += res * price;
      return;
    }
    
    if(_price[i] < price) {
      res = distance / _cc;
      
      if(distance % _cc > 0) {
	res++;
      }

      _res += res * price;
      price = _price[i];
      distance -= res * _cc;
      
    }
  }
}

void CWriteOut() {
  cout << _res << endl;
}


void WriteOut() {

  ofstream outFile("road.out");
  
  outFile << _res << endl;

  outFile.close();
}

int main() {
  
  ParseIn();
  Core();
  WriteOut();

  return 0;
}
