#include <bits/stdc++.h>
using namespace std;
bool a[100000005];
int b[100000005];
int c[100000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    memset(a,1,sizeof(a));
    for(int i=1;i<=n;i++){
        int cnt=2;
        for(int j=1;j<=n;j++){
            cnt=(cnt+a[j])%3;
            if(cnt==0&&a[j])b[j]=i,a[j]=0;
        }
    }

    for(int i=1;i<=n;i++) c[i]=b[i],b[i]=max(b[i],b[i-1]);
    cout<<b[n]<<" "<<c[n]<<endl;
    return 0;
}
