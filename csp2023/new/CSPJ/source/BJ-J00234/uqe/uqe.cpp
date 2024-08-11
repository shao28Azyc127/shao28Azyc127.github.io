#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        if(-a*c>=0&&c%a==0){
            cout<<sqrt(-c/a)<<endl;
        }

        else{
            cout<<"NO"<<endl;
        }
    }

return 0;
}

