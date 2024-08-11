#include<bits/stdc++.h>
using namespace std;
bool apple[1000000050];
int n,t,a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        if(a==0||a==-1||a==1||a==b||b==c) cout<<1<<endl;
        else if(a+b+c==0) cout<<"NO"<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
