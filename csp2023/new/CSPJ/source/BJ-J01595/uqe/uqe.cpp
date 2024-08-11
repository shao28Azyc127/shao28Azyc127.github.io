#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll t,m,a,b,c;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        ll f=1;
        for(int j=m;j>=-1*m;j--){
            if(a*j*j+b*j+c==0){
                cout<<j<<endl;
                f=0;
                break;
            }
        }
        if(f==1){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}


