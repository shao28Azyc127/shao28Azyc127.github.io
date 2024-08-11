#include<bits/stdc++.h>
using namespace std;
int n,s,v[2000001];
char a[2000001];
int check(int x,int y){
    int t=0;
    memset(v,0,sizeof(v));
    for(int i=1;i<=(y-x+1)/2;++i){
        int f=0;
        for(int j=x;j<=y;++j){
            if(f>0){
                if(v[j]==0){
                    if(a[f]==a[j]) v[f]=1,v[j]=1,f=0,t+=2;
                    else f=j;
                }
            }
            else if(v[j]==0) f=j;
        }
    }
    if(y-x+1==t) return 1;
    return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=2;i<=n;i+=2){
        for(int j=1;j+i-1<=n;++j){
            if(check(j,j+i-1)) ++s;
        }
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
