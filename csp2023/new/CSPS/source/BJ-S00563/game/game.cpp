#include<bits/stdc++.h>
using namespace std;
int n,l[10000000],r[10000000],d,r1[10000000];
char a[30000000];
void s(int x,int y){
   if(a[x-y]==a[x]){
      int t=0;
      if(r1[x-y-1]==r1[x]) t++;
      d++;
      l[x-y]++;
      r[x]++;
      r1[x]=x-y;
      if(l[x-y]!=0&&r[x-y-1]!=0&&t==0){
        d+=r[x-y-1];
        r[x]+=r[x-y-1];
      }
      if(x-y>1&&x<n){
       s(x+1,y+2);
   }
   }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        s(i,1);
    }
    cout<<d;
    return 0;
}
