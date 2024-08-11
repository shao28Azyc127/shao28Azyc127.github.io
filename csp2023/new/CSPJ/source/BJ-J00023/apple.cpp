#include<bits/stdc++.h>
using namespace std;
long long n,ans1,ans2,a[1000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int q=0;
    for(int k=1;;k++)
    {
        if(a[k]) {continue;}
        else ans1++;
        for(int i=k;i<=n;)
        {
            if(i==n) ans2=ans1;
            if(!a[i]) a[i]=1;
            int s=0,h=i;
            while(a[++h]) s++;
            s++;
            while(a[++h]) s++;
            s++;
            while(a[++h]) s++;
            s++;
            i+=s;
        }
        bool t=1;
        for(int i=1;i<=n;i++)
            if(!a[i]) {t=0;break;}
        if(t) {break;}
    }
    cout<<ans1-q<<" "<<ans2-q;
    return 0;
}
