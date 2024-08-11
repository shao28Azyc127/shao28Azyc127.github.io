#include<bits/stdc++.h>
using namespace std;
int n,m;
string w[3005];
bool check(int x,int y){
    for(int i=0,j=m-1;i<m&&j>=0;i++,j--){
        if(w[x][i]>w[y][j])return false;
        else if(w[x][i]<w[y][j])return true;
    }
    return false;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        sort(w[i].begin(),w[i].end());
    }
    for(int i=1;i<=n;i++){
        bool pd=1;
        for(int j=1;j<=n;j++){
            if(i!=j&&!check(i,j)){
                pd=0;
                break;
            }
        }
        cout<<pd;
    }
    return 0;
}
