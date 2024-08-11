#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3005;
int n, m, a[N][26], pos[2];
string s[N], mi[N];
int main()
{
    freopen("dict.in","r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            a[i][c-'a']++;
        }
    for(int i=1;i<=n;i++)
        for(int j=25;~j;j--)
            for(int k=1;k<=a[i][j];k++)
                s[i]+=char(j+'a');
    for(int i=1;i<=n;i++)
        for(int j=0;j<26;j++)
            for(int k=1;k<=a[i][j];k++)
                mi[i] += char(j+'a');
    if(s[1]<s[2])
        pos[0]=1,pos[1]=2;
    else
        pos[0]=2,pos[1]=1;
    for(int i=3;i<=n;i++){
        if(s[i] < s[pos[0]])
            pos[1] = pos[0], pos[0] = i;
        else if(s[i] < s[pos[1]])
            pos[1] = i;
    }
    for(int i=1;i<=n;i++){
        if(pos[0] == i && mi[i] < s[pos[1]] || pos[0] != i && mi[i] < s[pos[0]])
            cout << 1;
        else
            cout << 0;
    }
    cout<<'\n';
    return 0;
}
