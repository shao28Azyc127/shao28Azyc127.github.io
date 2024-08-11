#include<bits/stdc++.h>
using namespace std;
int T,M;
int ans;
bool already=false;
int a[5500];
int b[5500],c[5500];
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    for(int i=1;i<=T;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=T;i++){
        for(int j=M;j>=(-1)*M;j--){
            if(a[i]*j*j + b[i]*j + c[i] == 0){
                cout<<j<<endl;
                already=true;
                break;
        }}
        if(already==false)
            cout<<"NO";
    }
    return 0;
}
