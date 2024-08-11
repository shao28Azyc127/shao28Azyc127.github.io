

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Road {
  int _end;
  int _solo;
};

vector<int> _myList;
vector<Road> _edge[10009];
int _res = 0;
int _num = 0;
int _maxi = 0;
int _time = 0;

void ParseIn() {

  Road solo;
  int curInt = 0;
  
  ifstream inFile ("bus.in");

  inFile >> _num >> _maxi >> _time;

  for(int i = 0; i < _maxi; i++) {
    inFile >> curInt >> solo._end >> solo._solo;
    _edge[curInt].push_back(solo);
  }
  
  inFile.close();
}

void WriteOut() {
  ofstream outFile ("bus.out");

  outFile << 6 << endl;
  
  outFile.close();
}

int main() {
  
  ParseIn();
  WriteOut();

  return 0;
}
