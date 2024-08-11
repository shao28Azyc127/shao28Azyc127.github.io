#include <bits/stdc++.h>
using namespace std;
int n1[102000],n2[102000];
int main ()
{
    freopen ("road.in","r",stdin);
    freopen ("road.out","w",stdout);
    int n,d,you=0,youjia,moneymin=0;
    cin>>n>>d;
    for (int i=1;i<n;i++)
        cin>>n1[i];
    for (int i=1;i<=n;i++)
        cin>>n2[i];
    youjia=n2[1];
    for (int j=1;j<n;j++)
    {
        if (n2[j]<youjia) youjia=n2[j];
        if (you>n1[j]) you-=n1[j];
        else
        {
            n1[j]-=you;
            you=0;
            moneymin+=n1[j]/d*youjia;
            if (n1[j]%d!=0)
            {
                moneymin+=youjia;
                you+=d-(n1[j]%d);
            }
        }
    }
    cout<<moneymin<<endl;
    return 0;
}
