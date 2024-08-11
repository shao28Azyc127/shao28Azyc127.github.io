#include<bits/stdc++.h>
using namespace std;
bool vis[1000000005];
long long n;
long long i;
long long f(){
    for(long long i=1;i<=n;i++){
        if(vis[i]==0){
            return i;
        }
    }
    return 0;
}
long long t(){
    long long ans;
    long long flag=0;
    for(long long j=i+1;j<=n;j++){
        if(vis[j]==0){
            if(flag==0){
                flag=1;
            }else if(flag==1){
                flag=2;
            }else if(flag==2){
                return j;
            }
        }
    }
    return 0;
}
long long to(){
    long long ans;
    long long flag=0;
    for(long long j=i+1;j<=n;j++){
        if(vis[j]==0){
            if(flag==0){
                flag=1;
            }else if(flag==1){
                flag=2;
            }else if(flag==2){
                return j;
            }
        }
    }
    return f();
}

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n<=3){
        cout<<n<<" "<<n;
        return 0;
    }
    long long ans=0,num=0,x;
    bool flag=1;
    for(i=1;;i=to()){
        if(f()==0){
            break;
        }
        vis[i]=1;
        if(t()==0){
            ans++;
        }
        if(i==n){
            x=ans;
        }
    }
    cout<<ans<<" "<<x;
    return 0;
}
