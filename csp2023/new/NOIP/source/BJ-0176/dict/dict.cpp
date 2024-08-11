#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
long long n,m,i,j;
char c[3005][3005],cc;
string maxs,mins,s;
bool cmp(char x,char y){
    return x<y;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    cc='z'+1;
    for(i=1;i<=m;i++){
        mins=cc+mins;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>c[i][j];
        }
    }
    for(i=1;i<=n;i++){
        sort(c[i]+1,c[i]+1+m,cmp);
        s="";
        for(j=m;j>=1;j--){
            s+=c[i][j];
        }
        if(s<mins){
            mins=s;
        }
    }
    for(i=1;i<=n;i++){
        s="";
        for(j=1;j<=m;j++){
            s+=c[i][j];
        }
        if(s<=mins){
            cout<<1;
        }
        if(s>mins){
            cout<<0;
        }
    }
    return 0;
}
