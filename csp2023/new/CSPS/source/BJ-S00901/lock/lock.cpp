

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int res = 0;
int num = 0;
int vis[19];
int a[19];
int _indica = 1;
int _myMap[19][19];

void ParseIn () {

  ifstream inFile("lock.in");

  inFile >> num;

  for (int i = 1; i < num + 1; i++) {
    for (int m = 1; m < 6; m++) {
      inFile >> _myMap[i][m];
    }
  }
  
  inFile.close();
}

bool Check () {
  int cnt = 0;
  int index[4];
  int top = 0;

  for (int m = 1; m < num + 1; m++) {
    cnt = 0;
    memset(index, 0, sizeof(index));
    top = 0;
    for (int k = 1; k < _indica; k++) {
      if (a[k] != _myMap[m][k]) {
	cnt++;
	index[top] = k;
	top++;
      }
    }

    if (cnt == 0) {
      return false;
    }
    
    if (cnt > 2) {
      //cout << "no" << endl;
      return false;
    }
      
    if (cnt == 1) {
      continue;
    }

    if (cnt == 2 && index[1] - index[0] != 1) {
      return false;
    }
      
    if (cnt == 2) {
      int one = a[index[0]];
      int two = a[index[1]];
      int cc = 0;
      bool flag = false;
      while (cc != 10) {
	one = (one + 1) % 10;
	two = (two + 1) % 10;
	cc++;
	if (one == _myMap[m][index[0]] && two == _myMap[m][index[1]]) {
	  flag = true;
	}
      }
      if (!flag) {
	return false;
      }
    }
  }

  return true;
}

void Dfs (int cc) {

  if (_indica == 6) {
    if (Check()) {
      res++;
    }
    return;
  }

  for (int i = 0; i < 10; i++) {
    a[_indica] = i;
    _indica++;
    Dfs(cc + 1);
    _indica--;
  }
}

void Core () {

  if (num == 1) {
    res = 81;
    return;
  }
  Dfs(0);
}

void WriteOut () {

  ofstream outFile("lock.out");

  outFile << res << endl;

  outFile.close();
}

int main () {

  ParseIn();
  Core();
  WriteOut();
  
  return 0;
}
