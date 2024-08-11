#include<bits/stdc++.h>
using namespace std;
void solve(int a,int b,int c){
    int dl=b*b-4*a*c;
    if(dl<0){
        cout<<"NO\n";
        return;
    }else if(dl==0){
        cout<<1<<'\n';
        return;
    }
    int q=sqrt(dl);
    int u=-b+q;
    cout<<u/(2*a)<<'\n';
    return;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        solve(a,b,c);
    }
    return 0;
}
