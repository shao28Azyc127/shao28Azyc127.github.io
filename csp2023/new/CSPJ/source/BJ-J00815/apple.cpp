#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int ant=n;
    int num=0,dayy=0;
    int stdd[100005];
    bool std2[100005];
    std2[0]=false;
    for (int i=1;i<=n;i++)
    {
        stdd[i]=i;
        std2[i]=true;
    }

    for (int j=1;j<=n;j++)
    {
        dayy++;
        num=0;
        for(int i=1;i<=ant;i++)
        {

            if(stdd[i]%3==1)
            {
                num++;
            }

        }
        ant=ant-num;
        if (ant==0)
        {
            cout<<dayy<<" ";
            break;
        }

    }
    int a=n;
    int shu=1;
    int day2=1;
    while(a!=0)
    {
        if(shu==n)
        {
            cout<<day2;
            break;
        }
        a--;

        std2[shu]=false;
        for(int i=1;i<=3;i++)
        {
            shu++;
            while(std2[shu]==false)
            {
                shu++;
            }
        }
        if (shu>n)
        {
            day2++;
        }
        if(shu>n)
        {
            shu=shu-n-100017;
            while(std2[shu]==false)
            {
                shu++;
            }
        }
        while(shu<0)
        {
            shu++;
            while(std2[shu]==false)
            {
                shu++;
            }
        }
    }
    return 0;
}
