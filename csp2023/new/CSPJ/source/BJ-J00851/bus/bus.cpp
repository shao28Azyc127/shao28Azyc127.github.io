

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Map{
  bool _flag;
  int _time;
};

int _road,_maxi,_num;
int _res = 174400;
Map _map[10009][10009];

void ParseIn () {
  int starti,endi,letGo;

  ifstream inFile("bus.in");

  inFile >> _road >> _maxi >> _num;

  for(int i = 0; i < _maxi; i++) {
    inFile >> starti >> endi >> letGo;
    _map[starti][endi]._time = letGo;
    _map[starti][endi]._flag = true;
  }
  
  inFile.close();
}

void dfs(int now,int cc) {
  //cout << now << " " << cc << endl;
  
  if(now == _road && cc % _num == 0) {
    //   cout << -100 << endl;
    if(_res > cc || _res == 174400) {
      _res = cc;
    }

    return;
  }


  if(cc > _res) {
    return;
  }

  for(int i = 1; i < _road + 1; i++) {
    if(_map[now][i]._flag && _map[now][i]._time < cc + 1) {
      dfs(i,cc + 1);
    }
  }
}

void Core () {
  dfs(1,_num);
}

void WriteOut () {
  ofstream outFile("bus.out");

  if(_res == 174400) {
    outFile << -1 << endl;
    return;
  }
  
  outFile << _res << endl;
  
  outFile.close();
}

int main () {
  ParseIn();
  Core();
  WriteOut();

  return 0;
}
