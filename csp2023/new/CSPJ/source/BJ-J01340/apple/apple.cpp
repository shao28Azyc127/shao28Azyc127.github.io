#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, nn=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int ans=0;
        for (int j=1;j<=nn;j++)
        {
            int kk=0;
            for (int k=i-1;k>=1;k--)
            {
                if (v[k]==j)
                {
                    kk=k;
                    break;
                }
            }
            int z=0;
            for (int k=kk;k<=i;k++)
            {
                if (v[k]>j)
                {
                    z++;
                }
            }
            if (z==2)
            {
                ans=j;
                break;
            }
        }
        if (ans)
            v.push_back(ans);
        else
        {
            v.push_back(nn+1);
            nn++;
        }
    }
    cout<<nn<<' '<<v[v.size()-1]<<endl;
    return 0;
}
