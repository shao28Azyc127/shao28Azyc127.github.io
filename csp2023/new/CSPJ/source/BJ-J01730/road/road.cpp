#include<bits/stdc++.h>
#define du double
using namespace std;
int far[100001];
int oil[100001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,cost=0;
    du dive=0;
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>far[i];
    for(int i=0;i<n;i++) cin>>oil[i];
    for(int i=0;i<n;i++)
    {
        if(dive>=far[i+1])
        {
            dive-=far[i+1];
            continue;
        }
        int ino=far[i+1];
        for(int j=i+1;j<n;j++)
        {
            if(oil[j]<oil[i]) break;
            else ino+=far[j+1];
        }
        ino-=int(dive);
        if(ino%d!=0) ino=ino/d+1;
        else ino/=d;
        dive+=du(ino)*d;
        cost+=ino*oil[i];
        dive-=far[i+1];
    }
    cout<<cost;
}
