#include <bits/stdc++.h>
using namespace std;
int c,t;
int s(int m[10005],int x,int i){
    if(m[i]<=0&&m[i]>=-3){
        return m[i];
    }else if(m[i]==-(m[i]+3)){
        return -3;
    }
    bool flag=false;
    if(m[i]<0){
        flag=!flag;
        x=-(m[i]+3);
    }
    if(!flag){
        return s(m,x,m[-(m[m[i]]+3)]);
    }else{
        return s(m,x,m[m[i]]);
    }
}
int func(){
    int x=0,y=0,m[10005]={},ans=0;
    char a[10005]={};
    cin>>x>>y;
    for(int i=1;i<=y;i++){
        int xa,xb;
        cin>>a[i];
        if(a[i]=='T'){
            cin>>xa;
            m[xa]=-1;
        }else if(a[i]=='U'){
            cin>>xa;
            m[xa]=-3;
        }else if(a[i]=='F'){
            cin>>xa;
            m[xa]=-2;
        }else if(a[i]=='+'){
            cin>>xa>>xb;
            if(m[xb]==-3||m[xb]==-1||m[xb]==-2){
                m[xa]=m[xb];
            }else{
                m[xa]=xb;
            }
        }else if(a[i]=='-'){
            cin>>xa>>xb;
            if(m[xb]==-3){
                m[xa]=-3;
            }else if(m[xb]==-1){
                m[xa]==-2;
            }else if(m[xb]==-2){
                m[xa]==-1;
            }else{
                m[xa]=-2-xb;
            }
        }
    }
    for(int i=1;i<=x;i++){
        m[i]=s(m,x,i);
    }
    for(int i=1;i<=x;i++){
        if(m[i]==-3){
            ans++;
        }
    }
    return ans;
}
int main(){
   freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cout<<func()<<endl;
    }
    return 0;
}
