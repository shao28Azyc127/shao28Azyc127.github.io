#include<bits/stdc++.h>
using namespace std;
int a[15][15],n;
int sta[15][15][15][15][15][15];
void chk1(int p1,int p2,int p3,int p4,int p5,int i)//to lock number i,how does p1p2p3p4p5,
{
    int cnt=0;
    if(a[i][1]!=p1) cnt++;
    if(a[i][2]!=p2) cnt++;
    if(a[i][3]!=p3) cnt++;
    if(a[i][4]!=p4) cnt++;
    if(a[i][5]!=p5) cnt++;
    if(cnt!=1)
        return;
    sta[p1][p2][p3][p4][p5][i]=1;
    return;
}
void chk2(int p1,int p2,int p3,int p4,int p5,int i)
{
    int diff[15],num[15];
    num[1]=p1,num[2]=p2,num[3]=p3,num[4]=p4,num[5]=p5;
    for(int j=1;j<=5;j++)
    {
        if(a[i][j]!=num[j])
            diff[j]=1;
        else
            diff[j]=0;
    }
    int cnt=0;
    for(int j=1;j<=5;j++)
        if(diff[j]==1)
            cnt++;
    if(cnt!=2)
        return;
    for(int j=1;j<=4;j++)
    {
        if(diff[j]==0)
            continue;
        if(diff[j]==1 && diff[j+1]==0)
            return;
        int lac1=(num[j]+10-a[i][j])%10,lac2=(num[j+1]+10-a[i][j+1])%10;
        if(lac1!=lac2)
            return;
        break;
    }
    sta[p1][p2][p3][p4][p5][i]=1;
    return;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    int cnt1=0,cnt2=0;
    for(int p1=0;p1<=9;p1++)
    for(int p2=0;p2<=9;p2++)
    for(int p3=0;p3<=9;p3++)
    for(int p4=0;p4<=9;p4++)
    for(int p5=0;p5<=9;p5++)
    {
        for(int i=1;i<=n;i++)
        {
            chk1(p1,p2,p3,p4,p5,i);
            chk2(p1,p2,p3,p4,p5,i);
        }
    }
    int ans=0;
    for(int p1=0;p1<=9;p1++)
    for(int p2=0;p2<=9;p2++)
    for(int p3=0;p3<=9;p3++)
    for(int p4=0;p4<=9;p4++)
    for(int p5=0;p5<=9;p5++)
    {
        int flg=1;
        for(int i=1;i<=n;i++)
            flg=flg&(sta[p1][p2][p3][p4][p5][i]);
        if(flg==1)
            ans++;
    }
    cout<<ans;
    return 0;
}
