

#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

int _res;
int _num;
int _k;
int a[100009];
int v[100009];
double _oil;

int func (int num) {
  if (num == 1) {
    return 0;
  }
  int mini = 1000000;
  int pos = -1;
  int sum = 0;
  for (int i = 1; i < num; i++) {
    if (mini > a[i]) {
      mini = a[i];
      pos = i;
    }
  }
  for (int i = pos; i < num; i++) {
    sum += v[i];
  }
  int cur = ceil(ceil(1.0*sum/_k))*mini;
  _oil += ceil(1.0*sum/_k)-1.0*sum/_k;
  cur -= int(_oil)*mini;
  _oil -= int(_oil);
  return cur+func(pos);
}

int main () {

  ifstream inFile("road.in");
  ofstream outFile("road.out");
  
  inFile >> _num >> _k;
  for (int i = 1; i < _num; i++) {
    inFile >> v[i];
  }
  for (int i = 1; i < _num+1; i++) {
    inFile >> a[i];
  }
  
  if (_num > 1000) {
    for (int i = 1; i < _num; i++) {
      _res += v[i];
    }
    _res = ceil(1.0*_res/_k)*a[1];
  }
  else{
    _res = func(_num);
  }
  outFile  << _res << endl;

  inFile.close();
  outFile.close();
  
  return 0;
}
