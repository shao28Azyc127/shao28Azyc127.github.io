#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x = 0, w = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') w *= -1; ch = getchar();}
    while(ch <= '9' && ch >= '0'){x = x * 10 + ch - '0'; ch = getchar();}
    return x * w;
}
char chm[3005], chs[3005];
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n = read(), m = read();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            chm[i] = c > chm[i] ? c : chm[i];
            chs[i] = (chs[i] == 0) ? c : (c < chs[i] ? c : chs[i]);
        }
    }
    if(n == 1){
        cout<<"1";
        return 0;
    }
    for(int i=0;i<n;i++){
        int ans = 1;
        for(int j=0;j<n;j++){
            if(i == j) continue;
            if(chs[i] >= chm[j]){
                ans = 0;
                break;
            }
        }
        cout<<ans;
    }
    return 0;
}
