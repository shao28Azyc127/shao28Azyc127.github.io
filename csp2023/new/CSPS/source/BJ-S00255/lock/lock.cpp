#include <bits/stdc++.h>
using namespace std;
const int maxm=100010;
int n,m,ans,num[maxm],val[10],sep[7];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>sep[1]>>sep[2]>>sep[3]>>sep[4]>>sep[5];
        for(int i=1;i<=9;i++)
        {
            int a1=((sep[1]+i)%10);
            int a2=((sep[2]+i)%10);
            int a3=((sep[3]+i)%10);
            int a4=((sep[4]+i)%10);
            int a5=((sep[5]+i)%10);
            num[a1*10000+sep[2]*1000+sep[3]*100+sep[4]*10+sep[5]]++;
            num[sep[1]*10000+a2*1000+sep[3]*100+sep[4]*10+sep[5]]++;
            num[sep[1]*10000+sep[2]*1000+a3*100+sep[4]*10+sep[5]]++;
            num[sep[1]*10000+sep[2]*1000+sep[3]*100+a4*10+sep[5]]++;
            num[sep[1]*10000+sep[2]*1000+sep[3]*100+sep[4]*10+a5]++;
            num[a1*10000+a2*1000+sep[3]*100+sep[4]*10+sep[5]]++;
            num[sep[1]*10000+a2*1000+a3*100+sep[4]*10+sep[5]]++;
            num[sep[1]*10000+sep[2]*1000+a3*100+a4*10+sep[5]]++;
            num[sep[1]*10000+sep[2]*1000+sep[3]*100+a4*10+a5]++;
        }
    }
    for(int i=0;i<=99999;i++)
    {
        if(num[i]==n) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
