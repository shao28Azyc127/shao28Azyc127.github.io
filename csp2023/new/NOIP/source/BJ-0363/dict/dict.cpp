#include <bits/stdc++.h>
using namespace std;
const int N=3e3+5,T=0.94*CLOCKS_PER_SEC;
int n,m;
bool ans;
char str[N][N],str1[N][N],str2[N][N];
inline void file(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
}
inline bool cmp1(char x,char y){return x<y;}
inline void cpy1(int k){for(int i=0;i<m;++i) str1[k][i]=str[k][i];}
inline bool cmp2(char x,char y){return x>y;}
inline void cpy2(int k){for(int i=0;i<m;++i) str2[k][i]=str[k][i];}
inline bool check(int x,int y){
    if(x==y) return 0;
    for(int i=0;i<m;++i){
        if(str1[x][i]<str2[y][i]) return 0;
        if(str1[x][i]>str2[y][i]) return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        cin >> str[i];
        sort(str[i],str[i]+m,cmp1),cpy1(i);
        sort(str[i],str[i]+m,cmp2),cpy2(i);
    }
    for(int i=1;i<=n;++i){
        ans=1;
        for(int j=1;j<=n;++j) if(check(i,j)){ans=0;break;}
        cout << ans;
    }
    return 0;
}