#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin>>t>>m;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        if(m==1&&b==0&&c==0){
            cout<<0<<endl;
        }
        else if(b==0){
            if(-c/a>=0) cout<<sqrt(-c/a)<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
