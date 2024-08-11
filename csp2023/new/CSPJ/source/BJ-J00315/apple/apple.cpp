#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int pg,t,d,i,s[pg],j;
    cin>>pg;
    for(i=1;i<=pg;i++){
        s[i]=i;
    }
    for(i=1;i<=pg;i){
        while(s[i]!=0&&s[i]+2<=pg){
            for(j=s[i];j<=pg;j+=3){
                s[j]=0;
                i=1;
                s[i]=s[i+1];
                s[i+1]=s[i+2];
            }
            t++;
        }
        s[i]=0;
        t++;
        if(s[j]==pg){
            d=t+1;
        }
    }
    cout<<t<<" "<<d;
    return 0;
}