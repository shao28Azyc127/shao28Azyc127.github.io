#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,M,a,b,c,z;
signed main(){
   freeopen("uqe.in",'r',stdin);
   freeopen("uqe.out",'w',stdout);
    cin>>T>>M;
    for(int i=1;i<=T;i++){
        int ans=0;
        cin>>a>>b>>c;
        int d=b*b-4*a*c;
        if(d<0){
            cout<<"NO"<<endl;
        }
        else cout<<-1*b<<"/"<<2*a<<"+sqrt("<<d<<")"<<"/"<<2*a;
    }
    return 0;
}

