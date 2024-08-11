#include<bits/stdc++.h>
using namespace std;
int n,t,tttt,cnt,ans,a[101];
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    t=tttt=n;
    while(t) {
        int t2=t/3+(t%3!=0);
        t-=t2;
        cnt++;
    }
    for(int i=1;i<=n;i++) a[i]=i;
    while(n) {
        ans++;
        int tt=0;
        for(int i=1;i<=n;i++)
            if(i%3!=1)
                a[++tt]=a[i];
        int t3=n/3+(n%3!=0),flag=1;
        n-=t3;
        for(int i=1;i<=tt;i++)
            if(a[i]==tttt)
                flag=0;
        if(flag) break;
    }
    cout<<cnt<<" "<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
