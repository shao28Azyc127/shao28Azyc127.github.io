#include<iostream>
using namespace std;
long long n,a[100000000],s,ans=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin>>n;
    for(int j=1;j<=n;j++){
        if(a[j]==0) {
            while(a[j]==0){
                j++;
            }
        }
        ans++;
        for(int i=j;i<=n;i+=3){
            a[i]=0;
            if(i==n) s=i;
        }
    }
    cout<<ans<<' '<<s;
    return 0;
}
