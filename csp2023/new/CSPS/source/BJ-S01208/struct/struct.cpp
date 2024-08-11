#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
int n;

int main(){
    freopen("struct.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        int t=0;
        string a1,a2;
        if(op==2){
            cin>>a1>>a2;
            t+=8;
        }
        freopen("struct.out","w",stdout);
        if(op==3)cout<<t;
        if(op==4)cout<<a2;
    }
    return 0;
}
