#include <bits/stdc++.h>
using namespace std;
int n,m;
string vocab[3005],mins[3005],maxs[3005];
bool rulemax(char a,char b)
{
    return a>b;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    string tp;
    for(int i=1;i<=n;i++)
    {
        cin>>tp;
        vocab[i]=tp;
        sort(tp.begin(),tp.end(),rulemax);
        maxs[i]=tp;
        reverse(tp.begin(),tp.end());
        mins[i]=tp;
    }
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(mins[i]>maxs[j])
            {
                flag=true;
                break;
            }
        }
        if(flag==true)
        {
            cout<<0;
            flag=false;
        }
        else
        {
            cout<<1;
        }
    }
    return 0;
}
