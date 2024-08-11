#include <iostream>

#include<bits/stdc++.h>
using namespace std;

int s;
int n;
int a[600],b[600],c[600];
bool v[600][600];
//int t[600][3];//0:shijian,1:howlong can zhangdao a
bool p[600];
long long maxday=-1;
/*
int howlong(int day_quan,int i,int a)
{
    int h=0;
    int cnt=day_quan;
    for(;;)
    {
        h+=max(b[i]+day_quan*c[i],1);
        day_quan++;
        if(h>=a){

            return day_quan-cnt;
        }

    }
}
*/



/*

int aaa(int x)
{
    if(x>=s)return;

    if(x==1)
    {
        //t[1]=1;
        p[1]=1;
        maxday=max(maxday,howlong(1,1,a[1]));
        aaa(x+1);
    }










}






*/










int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);


    memset(v,0,sizeof(v));
    cin>>n;
    s=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(a[i]>s)s=a[i];
    }
    int xx,yy;
    for(int i=1;i<=n-1;i++)
    {
        cin>>xx>>yy;
        //if(yy>xx)swap(xx,yy);
        //v[xx][yy]=1;
    }

    //aaa(1);

    cout<<s;



    return 0;
}
