#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int gcd(int x,int y){
    if (x==y)return x;
    while (x%y!=0){
        int t=x%y;
        x=y;
        y=t;
    }
    return y;
}
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for (int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int d=b*b-4*a*c;
        if (d<0){
            cout<<"NO\n";
            continue;
        }
        if (b==0&&c==0)cout<<"0\n";
        else {
            if (c==0){
                if (b>0&&a<0||b<0&&a>0){
                    int p=gcd(max(abs(b),abs(a)),min(abs(b),abs(a)));
                    if (a<0){
                        a=-a;
                        b=-b;
                    }
                    cout<<-b/p;
                    if (a/p!=1)cout<<"/"<<a/p;
                }
                else cout<<"0";
            }
            cout<<"\n";
        }
    }
}
