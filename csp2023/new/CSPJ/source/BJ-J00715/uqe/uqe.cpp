#include<bits/stdc++.h>
#include<cmath>
using namespace std;
long long t,m,a,b,c;
int y(){
    long long w=b*b-4*a*c;
    if(w<0){
        return 0x3f3f3f;
    }
    if(w>=0){
        return (-b+sqrt(w))/(2*a);
    }
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        int q=y();
        if(q==0x3f3f3f){
            cout<<"NO"<<endl;
        }else{
            cout<<q<<endl;
        }
    }

    return 0;
    }
