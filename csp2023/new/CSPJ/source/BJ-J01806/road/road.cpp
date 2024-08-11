#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,d,minn=2147483647,bj,sum,bj1,flag,cc,akioi;
int v[100001],a[100001],num[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        num[i]=num[i-1]+v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<minn){
            minn=a[i];
            bj=i;
        }
    }
    if(bj==1){
        if(sum%d==0){
            cout<<(sum/d)*a[1];
            return 0;
        }
        else{
            cout<<(sum/d+1)*a[1];
        }
        return 0;
    }
    for(int i=1;i<=n;){
        flag=0;
        for(int j=i+1;j<=n-1;j++){
            if(a[j]<a[i]){
                bj1=j;
                flag=1;
                break;
            }
        }
        if(flag==0){
            if((sum-num[i])%d==0){
                cc+=((sum-num[i-1])/d)*a[i];
            }
            else{
                cc+=((sum-num[i-1])/d+1)*a[i];
            }
            break;
        }
        else{
            if((num[bj1]-num[i])%d==0){
                cc+=((num[bj1]-num[i])/d)*a[i];
            }
            else{
                cc+=((num[bj1]-num[i])/d+1)*a[i];
            }
            i=bj1;
        }
    }
    cout<<cc;
    return 0;
}
