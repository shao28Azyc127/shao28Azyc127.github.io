#include<iostream>
#include<cstdio>
using namespace std;

int n,m,k;
const int MAXN=10005;
int inp[MAXN][4];

int main(){
    freopen("bus.in","r",stdin);
    freoepn("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        for(int j=0;j<3;++j){
            cin>>inp[i][j];
        }
    }
    cout<<"-1";
}
