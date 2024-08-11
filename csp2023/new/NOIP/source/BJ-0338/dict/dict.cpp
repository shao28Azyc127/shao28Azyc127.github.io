#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int n,m,w[N][35];
bool ans[N];
inline bool check2(int i,int j){
    int r=26;
    for(int l=1;l<=26;l++){
        if(!w[i][l])    continue;
            for(;r>=1;r--){
                if(!w[j][r])    continue;
                if(l<r) return 1;
                return 0;
            }
        }
}
inline bool check(int i){
     for(int j=1;j<=n;j++){
            if(i==j)    continue;
            if(!check2(i,j))    return 0;
     }
     return 1;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            w[i][c-'a'+1]++;
        }
    for(int i=1;i<=n;i++)   ans[i]=check(i);
    for(int i=1;i<=n;i++)   cout<<ans[i];
    cout<<endl;
    return 0;
}
