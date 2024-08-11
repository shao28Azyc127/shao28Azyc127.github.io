#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c,res;
        cin>>a>>b>>c;
        res=b*b-4*a*c;
        if(res<0)cout<<"No"<<'\n';
        else cout<<max((-b+sqrt(res))/(2*a),(-b-sqrt(res))/(2*a))<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
