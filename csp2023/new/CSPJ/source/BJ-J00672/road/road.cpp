#include<iostream>
using namespace std;
int n,d,v[100001],a[100001],minn=100001,ans=0;
bool flag;
int cv(int i){
    int sum=0;
    for(int j=i;j<n;j++){
        sum+=v[j];
    }
    return sum;
}
void price(){
    int k,yz=0;
    for(int i=1;i<n;i++){
        if(flag){
            flag=0;
            continue;
        }
        if(a[i]==minn){
            int x=cv(i);
            if(yz>x%d||yz==v[i]%d){
                k=x/d;
                ans+=a[i]*k;
                yz+=k*d;
            }
            else{
                k=x/d;
                if(x%d!=0) k++;
                ans+=a[i]*k;
                yz+=k*d;
            }
        }
        else if(a[i]<a[i+1]){
            k=(v[i]+v[i+1])/d;
            if((v[i]+v[i+1])%d!=0) k++;
            ans+=a[i]*k;
            yz+=k*d;
            flag=1;
        }
        else{
            if(yz>v[i]%d||yz==v[i]%d){
                k=v[i]/d;
                ans+=a[i]*k;
                yz+=k*d;
            }
            else if(yz<v[i]%d){
                k=v[i]/d;
                if(v[i]%d!=0) k++;
                ans+=a[i]*k;
                yz+=k*d;
            }
        }
        yz-=v[i];
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        minn=min(minn,a[i]);
    }
    price();
    cout<<ans;
    return 0;
}
