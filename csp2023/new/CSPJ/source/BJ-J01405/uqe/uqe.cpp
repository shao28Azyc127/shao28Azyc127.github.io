#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int jud=b*b-4*a*c;
        if(jud<0) cout<<"NO";
        else{
            int x=(sqrt(jud)-b)/2*a,y=(-sqrt(jud)-b)/2*a;
            cout<<max(x,y);
        }
    }


    return 0;
}
