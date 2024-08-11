#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
char s[maxn][maxn];
char c0[maxn], c1[maxn]/*, t0[maxn], t1[maxn]*/;
int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++)
    {
        c1[i] = 0, c0[i] = 127;
        //t1[i] = 0, t0[i] = 0;
        for(int j=0;j<m;j++){
            c1[i] = max(c1[i], s[i][j]);
            c0[i] = min(c0[i], s[i][j]);
        }
        //for(int j=0;j<m;j++){
        //    if(s[i][j] == c1[i]) t1[i]++;
        //    if(s[i][j] == c0[i]) t0[i]++;
        //}
    }
    for(int i=0;i<n;i++){
        bool flag = 1;
        for(int j=0;j<n;j++){
            if(i == j) continue;
            //cout<<i<<" "<<j<<" "<<c0[i]<<" "<<c1[j]<<endl;
            if(c0[i] >= c1[j]){
                flag = 0; break;
            }
        }
        cout<<flag;
    }
    cout<<endl;
    return 0;
}
