#include<bits/stdc++.h>
using namespace std;
int n,d;
int v[100005],a[100005];
long long ans=0;
int minn=2147482647,minid;
int you=0;
long long anss=0;
int shang(int a,int b){
    if (a%b==0) return a/b;
    return a/b+1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=2;i<=n;i++){
        int l;
        cin>>l;
        v[i]=l;
        ans+=l;
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]<minn){
            minn=a[i];
            minid=i;
        }
    }
    if (minid==i){
        if (ans%d==0){
            cout<<ans/d*a[1];
        }
        else{
            cout<<(ans/d+1)*a[i];
        }
        return 0;
    }
    for (int i=1;i<=n;i++){
        if (you==0){
            you+=shang(v[i+1],d);
            anss+=you*a[i];
        }
        else if (v[i+1]>you){
            you+=shang(v[i+1]-you,d);
            anss+=shang(v[i+1]-you,d)*a[i];
        }
        else{
            if (a[i+1]>=a[i] and i<n-1){
                you+=shang(v[i+1]+v[i+2],d);
                anss+=shang(v[i+1]+v[i+2],d)*a[i];
            }
        }
        you-=v[i]/d;
    }
    cout<<anss<<endl;
    return 0;
}
//Xuzehou AK IOI!
