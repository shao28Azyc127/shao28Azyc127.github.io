#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005],sum=0,ans=0,s=1,asn=0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i==1){
            for(int j=0;j<n;j=j+3){
                a[j]=0;
                if(j==n-1){
                    ans++;
                    s = s-1;
                }
            }
            sum++;
            if(s==1){
                ans++;
            }
            sort(a,a+n);
        }else{
            for(int j=0;j<n-1;j++){
                if(a[j]==0){
                    continue;
                }
                if(j%3==0&&a[j]!=0){
                    a[j]=0;
                }
                if(j==n-1){
                    ans++;
                    s = s-1;
                }
            }
            sum++;
            if(s==1){
                ans++;
            }
            sort(a,a+n);
        }
        for(int i=0;i<n-1;i++){
            if(a[i]==0){
                asn = asn;
            }
        }
        if(asn==0)
        {
            cout<<sum<<" "<<ans;
            return 0;
        }
    }
    cout<<sum<<" "<<ans;
    return 0;
}
