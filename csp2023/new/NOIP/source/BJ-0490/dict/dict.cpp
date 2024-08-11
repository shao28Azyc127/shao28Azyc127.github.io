#include<bits/stdc++.h>
using namespace std;
int n,m,l[3010][30];
string q[3010][2];
int main () {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >>n>>m;
    for (int a=1;a<=n;a++) {
        for (int b=1;b<=m;b++) {
            char f;
            cin >>f;
            l[a][int(f-'a')]++;
        }
        for (int b=0;b<26;b++)
            for (int c=1;c<=l[a][b];c++)
                q[a][0]+=char(b+'a');
        for (int b=25;b>=0;b--)
            for (int c=1;c<=l[a][b];c++)
                q[a][1]+=char(b+'a');
    }
    for (int a=1;a<=n;a++) {
        bool opt=true;
        for (int b=1;b<=n;b++) {
            if (a==b) continue;
            if (q[a][0]>=q[b][1]) {
                opt=false;
                break;
            }
        }
        if (opt) cout <<1;
        else cout <<0;
    }
    return 0;
}
