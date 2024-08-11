#include<bits/stdc++.h>
using namespace std;
int k=1,mu;
int res,temp=0;
int flag=0;
int spass=0,pass=0;
int main(){
    int n,d;
    freopen("road.in.in","r",stdin);
    cin>>n>d;
    int a[n-1];
    for(int i=0;i<=n;i++){
        cin>>a[i];
        spass+=a[i];
    }
    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    while(pass!=spass){
        for(int i=k;i<n;i++){
            if(b[k]>=b[i]){
            flag=1;
                mu=i;
            }
        }
        if(flag==0){
            res=int(spass/d+0.5)*b[k];
            break;
        }
        else{
            for(int i=k;i<a[mu];i++){
                temp+=a[i];
            }
            pass=temp;
            spass-=pass;
            res+=int(temp/d+0.5)*b[k];
        }
        k=mu-i+1;
        flag=0;
    }
    freopen("road.out.out","w",stdout);
    cout<<res;
    return 0;
}
