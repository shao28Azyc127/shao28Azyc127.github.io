#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int num[10][10],sta[10];
int mp[10],now[10],tmp[10];
int mod=10;

void upd_1(int T)
{
    int S=T;
    memset(now,0,sizeof(now));
    memset(tmp,0,sizeof(tmp));
    int cnt_s=0;
    while(S)  now[5-cnt_s]=S%10,S/=10,cnt_s++;
    for(int nm=1;nm<=5;nm++)
    {
        for(int k=1;k<=5;k++)  tmp[k]=now[k];
        for(int k=0;k<=9;k++)
        {
            if(k==now[nm]){continue;}
            tmp[nm]=k;
            int cmp=0;
            for(int i=1;i<=5;i++)  cmp=cmp*10+tmp[i];
            int flag=0;
            for(int i=1;i<=n;i++)  if(cmp==sta[i])  flag=1;
            //if(flag==1)  continue;
            for(int sta_k=1;sta_k<=n;sta_k++)
            {
                if(sta[sta_k]==cmp)  mp[sta_k]=1;
            }
        }
    }
}
void upd_2(int T)
{
    int S=T;
    memset(now,0,sizeof(now));
    memset(tmp,0,sizeof(tmp));
    int cnt_s=0;
    while(S)  now[5-cnt_s]=S%10,S/=10,cnt_s++;
    for(int nm=1;nm<5;nm++)
    {
        for(int k=1;k<=5;k++)  tmp[k]=now[k];
        for(int k=1;k<=9;k++)
        {
            tmp[nm]=(tmp[nm]+k)%mod,tmp[nm+1]=(tmp[nm+1]+k)%mod;
            int cmp=0;
            for(int i=1;i<=5;i++)  cmp=cmp*10+tmp[i];
            for(int sta_k=1;sta_k<=n;sta_k++)
            {
                if(sta[sta_k]==cmp)  mp[sta_k]=1;
            }
            tmp[nm]=now[nm],tmp[nm+1]=now[nm+1];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int K=0;
        for(int j=1;j<=5;j++)  cin>>num[i][j],K=K*10+num[i][j];
        sta[i]=K;
    }
    int ans=0;
    for(int S=0;S<N;S++)
    {
        memset(mp,0,sizeof(mp));
        upd_1(S);
        upd_2(S);
        int flag=1;
        
        for(int i=1;i<=n;i++)  if(mp[i]==0)  flag=0;
        if(flag==1)  ans++;//cout<<S<<endl;
    }
    cout<<ans;
    return 0;
}
