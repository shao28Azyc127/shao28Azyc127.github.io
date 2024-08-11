

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Order {
  int _numOne;
  int _numTwo;
  char _type;
};

vector<Order> _myList;
vector<int> _resList;
int _numList[100009];
int _num = 0;
int _cc = 0;
int _res = 0;

void GenList() {
  for(int i = 0; i < 100009; i++) {
    _numList[i] = i;
  }

}

void Core() {
  GenList();
  int res = 0;
  
  for(int i = _myList.size() - 1; i > -1; i--) {
    if(_myList[i]._type == 'F') {
      _numList[_myList[i]._numOne] = -2;
    }
    if(_myList[i]._type == 'T') {
      _numList[_myList[i]._numOne] = -1;
    }
    if(_myList[i]._type == 'U' && _numList[_myList[i]._numOne] == _myList[i]._numOne) {
      res++;
      _numList[_myList[i]._numOne] = -3;
    }
  }
  _resList.push_back(res);
}

void ParseIn() {

  int maxi = 0;
  int num = 0;
  Order solo;
  
  ifstream inFile("tribool.in");

  inFile >> _num >> _num;

  for(int i = 0; i < _num; i++) {
    inFile >> _cc >> maxi;
    _myList.clear();

    for(int m = 0; m < maxi; m++) {
      
      inFile >> solo._type >> solo._numOne;
      
      if(solo._type == '+' || solo._type == '-') {
	inFile >> solo._numTwo;
      }
      _myList.push_back(solo);
      
    }
    Core();
    
  }
  
  inFile.close();
}

void CWriteOut() {
  for(int i = 0; i < _resList.size(); i++) {
    cout << _resList[i] << endl;
  }
}

void WriteOut() {

  ofstream outFile ("tribool.out");

  for(int i = 0; i < _resList.size(); i++) {
    outFile << _resList[i] << endl;
  }

  outFile.close();
}

int main() {
  
  ParseIn();
  WriteOut();

  return 0;
}
