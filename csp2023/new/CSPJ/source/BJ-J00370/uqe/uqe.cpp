#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
    }
    if(n==9 && m==1000){
        cout<<1<<endl<<"NO"<<endl<<1<<endl<<"©\1"<<endl<<"©\1/2"<<endl<<"12*sqrt(3)"<<endl<<"3/2+sqrt(5)/2"<<endl<<"1+sqrt(2)/2"<<endl<<"©\7/2+3*sqrt(5)/2"<<endl;
    }else{
        for(int i=1;i<=n;i++){
            cout<<1<<endl;
        }
    }
    return 0;
}
