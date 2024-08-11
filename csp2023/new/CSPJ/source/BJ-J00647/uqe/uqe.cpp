#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b==0&&c==0){
            cout<<0<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
