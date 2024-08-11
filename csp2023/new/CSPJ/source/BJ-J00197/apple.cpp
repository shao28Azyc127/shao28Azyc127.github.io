#include <bits/stdc++.h>
using namespace std;
int n,cnt,ans=1;
const int maxn=1e6+5;
int a[maxn],an[maxn]={0};
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n<=3){
        cout<<n<<" "<<n<<endl;
        return 0;
    }
    int b=5;
    an[1]=1;
    an[4]=3;
    an[7]=4;
    for(int i=10;i<=maxn;i+=0){
        for(int j=1;j<=b-4;j++){
            an[i]=b;i+=3;
        }
        b++;
    }
    if(n%3==1){
        cout<<an[n]<<"1"<<endl;
        return 0;
    }
    else{
    while(n!=1){
        cnt=0;
        for(int i=1;i<=n;i++){
            if(i%3!=1){
                cnt++;
                a[cnt]=i;
                if(i==n){
                int c=ans;
                }
            }
        n=n-cnt;
        ans++;
        }
    }
    cout<<ans<<" "<<c<<endl;
    return 0;
    }
}