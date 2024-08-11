#include<bits/stdc++.h>
using namespace std;
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int n=b*b-4*a*c;
        if(n<0){
            cout<<"NO"<<endl;
            continue;
        }
        int x1=((0-b)-sqrt(n))/2/a;
        int x2=((0-b)+sqrt(n))/2/a
    }
    return 0;
}
