#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[12][6],ans,plan[6];
bool chk(int x,int k1,int k2,int k3,int k4,int k5)
{
    int diff=0;
    diff+=(a[x][1]!=k1);
    diff+=(a[x][2]!=k2);
    diff+=(a[x][3]!=k3);
    diff+=(a[x][4]!=k4);
    diff+=(a[x][5]!=k5);
    if(diff==0) return false;
    if(diff<=1) return true;
    if(diff>=3) return false;
    plan[1]=k1;
    plan[2]=k2;
    plan[3]=k3;
    plan[4]=k4;
    plan[5]=k5;
    int fst,lst;
    for(int i=1;i<=5;i++)
    {
        if(plan[i]!=a[x][i])
        {
            fst=i;
            break;
        }
    }
    for(int i=5;i>=1;i--)
    {
        if(plan[i]!=a[x][i])
        {
            lst=i;
            break;
        }
    }
    if(lst-fst>=2) return false;
    int pro1=(a[x][fst]-a[x][lst]+10)%10;
    int pro2=(plan[fst]-plan[lst]+10)%10;
    if(pro1==pro2) return true;
    else return false;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    }
    for(int x1=0;x1<=9;x1++)
    {
        for(int x2=0;x2<=9;x2++)
        {
            for(int x3=0;x3<=9;x3++)
            {
                for(int x4=0;x4<=9;x4++)
                {
                    for(int x5=0;x5<=9;x5++)
                    {
                        for(int i=1;i<=n;i++)
                        {
                            if(!chk(i,x1,x2,x3,x4,x5)) break;
                            if(i==n)
                            {
                                ans++;
                                //cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" "<<x5<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}







