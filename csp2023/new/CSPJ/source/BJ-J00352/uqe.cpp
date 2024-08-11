#include<bits/stdc++.h>
using namespace std;
//cout<<"Thanks god.Please help me AK CSP-J!";
bool pd(int n){
    int cnt=0;
    while(1){
        int p=n*cnt,f=0;
        int q=cnt;
        for(int i=sqrt(q);i>1;i--){
            if(p%i==0&&q%i==0){
                f=1;
                break;
            }
        }
        if(!f){
            return 1;
        }else{
            return 0;
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(b==0&&c==0){
            cout<<0<<endl;
        }
    }
    return 0;
}
