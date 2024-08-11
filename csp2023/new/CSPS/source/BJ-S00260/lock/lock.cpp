#include <bits/stdc++.h>
using namespace std;
int q[100010];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int n[6],beifen[6];
        cin>>n[1]>>n[2]>>n[3]>>n[4]>>n[5];
        for (int j=1;j<=5;j++) beifen[j]=n[j];
        for (int j=1;j<=5;j++){
            for (int k=1;k<=9;k++){
                n[j]=(n[j]+k)%10;
                int nownum=n[1]*10000+n[2]*1000+n[3]*100+n[4]*10+n[5];
                q[nownum]++;
                n[j]=beifen[j];
            }
        }
        for (int j=1;j<=4;j++){
            for (int k=1;k<=9;k++){
                n[j]=(n[j]+k)%10;
                n[j+1]=(n[j+1]+k)%10;
                int nownum=n[1]*10000+n[2]*1000+n[3]*100+n[4]*10+n[5];
                q[nownum]++;
                n[j]=beifen[j];
                n[j+1]=beifen[j+1];
            }
        }
    }
    int ans=0;
    for(int i=1;i<=99999;i++) if (q[i]==n) ans++;
    cout<<ans;
    return 0;
}
