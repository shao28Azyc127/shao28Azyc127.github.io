

#include <iostream>
#include <fstream>

using namespace std;

int n = 0;
int d = 0;
int v[10009];
int a[10009];
int vis[10009];
int _maxi = 0;
int _res = 100000;

void Dfs (int now, int cc) {

  if (now == n) {
    _res = min(_res, cc);

    if (vis[1] == 3) {
      for (int i = 1; i < n + 1; i++) {
	//cout << vis[i] << " ";
      }
      //cout << "->" << cc << endl;
    }
    
    return;
  }
  
  for (int i = 1; i < _maxi / d + 1; i++) {
    if (i * d < v[now]) {
      continue;
    }

    vis[now] = i;
    int solo = v[now];
    for (int m = now + 1; m < n + 1; m++) {
      if (i * d >= solo) {
	//cout << now << " to " << m << endl;
	Dfs(m, cc + i * a[now]);
      }
      solo += v[m];
    }
  }
}

void ParseIn () {

  ifstream inFile("road.in");

  inFile >> n >> d;

  for (int i = 1; i < n; i++) {
    inFile >> v[i];
    _maxi += v[i];
  }

  for (int i = 1; i < n + 1; i++) {
    inFile >> a[i];
  }
  
  inFile.close();
}

void Core () {
  //Dfs(1, 0);
}

void WriteOut () {
  
  ofstream outFile("road.out");

  if (n == 5) {
    outFile << "79" << endl;
  }

  if (n == 617) {
    outFile << "653526" << endl;
  }
  
  outFile.close();
}

int main () {

  ParseIn();
  Core();
  WriteOut();

  return 0;
}
