#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
const int N = 3005;
int n, m;
int wmax[N], wmin[N];
string w[N];

int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    memset(wmin, 0x3f, sizeof(wmin));
    for(int i=0;i<n;i++){
        cin >> w[i];
        for(int j=0;j<m;j++){
            wmax[i] = max(wmax[i], w[i][j]-'a');
            wmin[i] = min(wmin[i], w[i][j]-'a');
        }
    }
    for(int i=0;i<n;i++){
        bool flag = true;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            // printf("wi %d %d wj %d %d\n", wmin[i], wmax[i], wmin[j], wmax[j]);
            if(wmin[i]>wmax[j]) {flag = false; break;}
            if(wmin[i]==wmax[j]&&wmax[i]!=wmin[j]) {flag = false; break;}
        }
        cout << flag;
    }
}