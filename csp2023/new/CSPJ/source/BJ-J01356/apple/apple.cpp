#include <bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
bool is_ans2=1;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while (n>=1)
    {
        if (n%3==0)
        {
            ans1++;
            n-=n/3;
        }
        else
        {
            if (n%3==1 && is_ans2)
            {
                n-=n/3+1;
                ans1++;
                ans2=ans1;
                is_ans2=0;
                continue;
            }
            n-=n/3+1;
            ans1++;
        }
    }
    cout<<ans1<<' '<<ans2;
}
