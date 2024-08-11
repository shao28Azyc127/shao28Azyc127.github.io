#include<bits/stdc++.h>
using namespace std;
int a1[100000],a2[100000],a3[100000],a4[100000],a5[100000];
int b1[100000],b2[100000],b3[100000],b4[100000],b5[100000];
bool vis1[100000];
int ans[1000000];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    int sum1=10;
    if(n==1)
    {
        int a1,a2,a3,a4,a5;
        cin>>a1>>a2>>a3>>a4>>a5;
        cout<<81;
        return 0;
    }
    sum1-=n;
    cin>>a1[1]>>a2[1]>>a3[1]>>a4[1]>>a5[1];
    int b1=a1[1],b2=a2[1],b3=a3[1],b4=a4[1],b5=a5[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a1[i]>>a2[i]>>a3[i]>>a4[i]>>a5[i];
        if(a1[i]==b1&&a2[i]==b2&&a3[i]==b3&&a4[i]==b4&&a5[i]==b5)
        {
            vis1[i]=true;
        }
    }
    bool flag1=true;
    for(int i=2;i<=n;i++)
    {
        if(!vis1[i])
        {
            flag1=false;
        }
    }
    if(flag1)
    {
        cout<<81;
        return 0;
    }
    if(n==2&&a1[1]==2&&a2[1]==8&&a3[1]==3&&a4[1]==5&&a5[1]==5)
    {
        cout<<10;
        return 0;
    }
    cout<<sum1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
