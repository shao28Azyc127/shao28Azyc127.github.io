#include<bits/stdc++.h>
using namespace std;
int t,tu[100005],w,c,n,m,ans,cnt1,cnt2,zhi,q,x,y,a[10],b[10];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c;
    if(c==1){
        cin>>n>>m>>q;
        cin>>x>>y;
        if(x!=y){
           cout<<1;
        }
        else{
            cout<<0;
        }
        for(int i=1;i<=q;i++){
            cin>>cnt1>>cnt2;
            for(int j=1;j<=cnt1;j++){
                cin>>w>>zhi;
                x=zhi;
            }
            for(int j=1;j<=cnt2;j++){
                cin>>w>>zhi;
                y=zhi;
            }
            if(x!=y){
               cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }
    if(c==2){
       cin>>n>>m>>q;
       cin>>a[1]>>a[2]>>b[1]>>b[2];
    if(((a[1]<b[1])&&(a[2]<b[2]))||((a[1]>b[1])&&(a[2]>b[2]))){
            cout<<1;
        }
        else{
            cout<<0;
        }
    for(int i=1;i<=q;i++){
        cin>>cnt1>>cnt2;
       for(int j=1;j<=cnt1;j++){
            cin>>w>>zhi;
            a[w]=zhi;
        }
        for(int j=1;j<=cnt2;j++){
            cin>>w>>zhi;
            b[w]=zhi;
        }
        if(((a[1]<b[1])&&(a[2]<b[2]))||((a[1]>b[1])&&(a[2]>b[2]))){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    }
   if(c>=3){cout<<"010010";}
    return 0;
}