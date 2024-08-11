#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans;
const int N=8007;
//struct hiw{
//int l,r;};
queue<int> hw[N];
vector<int> hw2[N];
int f[N][N];
int hwc[N];
int main(){
    memset(hwc,0,sizeof(hwc));
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
cin>>n>>s;
for(int i=0;i<=n;++i) hwc[i]=0;
for(int i=0;i<n-1;++i){
    int x=i,y=i+1;
    while(x>=0 && y<n){
        if(s[x]!=s[y]){
            break;
        }
        f[x][y]=1;
        f[y][x]=1;
        x--;y++;

    }
}
for(int k=0;k<n;++k){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(!f[i][j])f[i][j]=f[i][k]&f[k+1][j];
            //cout<<'t'<<endl;
        }
    }
}
for(int i=0;i<n;++i){
    for(int j=i;j<n;++j){
        ans+=f[i][j];
    }
}
cout<<ans;
}
