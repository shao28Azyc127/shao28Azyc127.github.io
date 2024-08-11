#include<iostream>
#include<cstdio>
using namespace std;
bool v[1000000000];
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    for(int i=0;i<1e9;i++){
        v[i]==false;
    }
    cin>>n;
    int t=1,sum=0,ans=0,num=0,l=2;
    while(true){
        if(sum>=n){
            break;
        }
        if(t>n){
            t=1;
            ans++;
            l=2;
        }
        if(v[t]==false&&l>=2){
            v[t]=true;
            l=0;
            sum++;
            if(t==n){
                num=ans+1;
            }
        }
        else if(l<2){
            if(v[t]==false){
                l++;
            }
        }
        t++;
    }
    cout<<ans+1<<" "<<num;
    return 0;
}
