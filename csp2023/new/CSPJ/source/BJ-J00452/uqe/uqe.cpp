#include <bits/stdc++.h>
using namespace std;
int m,t;
long long f(int a,int b,int c,int x){
    long long s;
    s=a*x*x+b*x+c;
    return s;
}
string itos(int x){
    string kc="";
    if(x<0) kc+='-';
    x=abs(x);
    int ws[100];
    int flag=1;
    while(x!=0){
        ws[flag++]=x%10;
        x/=10;
    }

    for(int i=flag-1;i>=1;i--)
        kc+=(ws[i]+'0');
    return kc;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    int o,p,q;
    int maxans;
    for(int i=1;i<=t;i++){
        cin>>o>>p>>q;
        maxans=-10000000;
        for(int j=-5000;j<=5000;j++){
            if(f(o,p,q,j)==0)   maxans=max(maxans,j);
        }
        if(maxans!=-10000000)cout<<itos(maxans)<<endl;
        else    cout<<"NO"<<endl;
    }
    return 0;
}
