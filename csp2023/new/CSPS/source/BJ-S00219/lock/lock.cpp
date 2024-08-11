#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int a[10][10];
int n;
bool check(int i1,int i2,int i3,int i4,int i5)
{
    for(int i=1;i<=n;i++)
    {
        if((i1==a[i][1])+(i2==a[i][2])+(i3==a[i][3])+(i4==a[i][4])+(i5==a[i][5])==4)
            continue;
        if((i1==a[i][1])+(i2==a[i][2])+(i3==a[i][3])+(i4==a[i][4])+(i5==a[i][5])!=3)
            return false;
        if(((i1==a[i][1])+(i2==a[i][2])==0)&&((i1-a[i][1]+10)%10==(i2-a[i][2]+10)%10))
            continue;
        if(((i2==a[i][2])+(i3==a[i][3])==0)&&((i2-a[i][2]+10)%10==(i3-a[i][3]+10)%10))
            continue;
        if(((i3==a[i][3])+(i4==a[i][4])==0)&&((i3-a[i][3]+10)%10==(i4-a[i][4]+10)%10))
            continue;
        if(((i4==a[i][4])+(i5==a[i][5])==0)&&((i4-a[i][4]+10)%10==(i5-a[i][5]+10)%10))
            continue;
        return false;
    }
    return true;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    if(n==1)
    {
        cout<<"81"<<endl;
        return 0;
    }
    int ans=0;
    for(int i1=0;i1<=9;i1++)
        for(int i2=0;i2<=9;i2++)
            for(int i3=0;i3<=9;i3++)
                for(int i4=0;i4<=9;i4++)
                    for(int i5=0;i5<=9;i5++)
                        if(check(i1,i2,i3,i4,i5)==true)
                            ans++;
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
