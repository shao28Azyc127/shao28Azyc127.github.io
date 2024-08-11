#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[5001],b[5001],c[5001];
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>t;
    for(int i = 0;i < n;i++){
        cin>>a[i]>>b[i]>>c[i];
        int s = b[i]*b[i]-4*a[i]*c[i];
        if(s < 0){
            cout<<"NO"<<endl;
        }
        else{
            if(s == 0){
                float p,q;
                for(int i = 0;i <10000,i++){
                    for(int j = 0;j < 10000;j++){
                        if(p*q == 0){
                            cout<<p<<q<<endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
