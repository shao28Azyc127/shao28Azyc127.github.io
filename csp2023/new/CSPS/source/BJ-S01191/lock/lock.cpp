#include <bits/stdc++.h>
using namespace std;

struct pwd
{
    int p[5];
    pwd(int a[])
    {
        p[0]=a[0];
        p[1]=a[1];
        p[2]=a[2];
        p[3]=a[3];
        p[4]=a[4];
    }

    bool operator==(const pwd &pp) const
    {
        for(int i=0;i<5;i++)
        {
            if(pp.p[i]!=p[i])
            {
                return false;
            }
        }
        return true;
    }
};

bool findp(vector<pwd> &a,pwd p)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==p)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    int n;
    scanf("%d",&n);
    n--;
    int p[5]={0};
    vector<pwd> a;
    vector<pwd> ans;

    if(n==0)
    {
        cout<<81;
        return 0;
    }
        scanf("%d%d%d%d%d",&p[0],&p[1],&p[2],&p[3],&p[4]);
   //     cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<" "<<p[3]<<" "<<p[4]<<" ";
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<9;j++)
            {
                p[i]++;
                if(p[i]==10)p[i]=0;
                ans.push_back(pwd(p));
            }
            p[i]++;
            if(p[i]==10)p[i]=0;
        }
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<9;j++)
            {
                p[i]++;
                p[i+1]++;
                if(p[i]==10)p[i]=0;
                if(p[i+1]==10)p[i+1]=0;
                ans.push_back(pwd(p));
            }
            p[i]++;
            p[i+1]++;
            if(p[i]==10)p[i]=0;
            if(p[i+1]==10)p[i+1]=0;
        }

    while(n--)
    {
        scanf("%d%d%d%d%d",&p[0],&p[1],&p[2],&p[3],&p[4]);
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<9;j++)
            {
                p[i]++;
                if(p[i]==10)p[i]=0;
                if(findp(ans,pwd(p)))
                    a.push_back(pwd(p));
            }
            p[i]++;
            if(p[i]==10)p[i]-=10;
        }
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<9;j++)
            {
                p[i]++;
                p[i+1]++;
                if(p[i]==10)p[i]=0;
                if(p[i+1]==10)p[i+1]=0;
                if(findp(ans,pwd(p)))
                    a.push_back(pwd(p));
            }
            p[i]++;
            p[i+1]++;
            if(p[i]==10)p[i]=0;
            if(p[i+1]==10)p[i+1]=0;
        }
        swap(ans,a);
    }

    cout<<ans.size();

    return 0;
}
