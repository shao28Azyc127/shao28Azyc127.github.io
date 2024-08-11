

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAXI = 2147483647;

int n = 0;
int k = 0;
int m = 0;
vector<int> edges[20009];
int res = 2147483647;
int a[20009];
bool vis[20009];
bool flag = false;

void ParseIn () {
  int u;
  int v;
  
  ifstream inFile("bus.in");

  inFile >> n >> m >> k;

  for (int i = 1; i < m + 1; i++) {
    inFile >> u >> v >> a[i];

    if (a[i] != 0) {
      flag = true;
    }

    edges[u].push_back(v);
  }
  
  inFile.close();
}

void Dfs (int now, int cc) {

  vis[now] = true;
  
  if (now == n) {
    if (cc % k == 0) {
      res = min(res, cc);
    }
    return;
  }

  for (int i = 0; i < edges[now].size(); i++) {
    Dfs(edges[now][i], cc + 1);
  }
}

void Core () {

  if (flag) {
    return;
  }
  Dfs(1, 0);
}

void WriteOut () {

  ofstream outFile("bus.out");
  
  if (flag) {
    outFile << "-1" << endl;
  }
  else {
    if (!flag && res != MAXI) {
      outFile << res << endl;
    }
    else {
      outFile << "-1" << endl;
    }
  }

  outFile.close();
}

int main () {

  ParseIn();
  Core();
  WriteOut();

  return 0;
}
