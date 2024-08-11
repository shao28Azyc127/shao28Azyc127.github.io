#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,ans1,ans2;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int i,j,t=n;
    bool f=1;
    while(t)
    {
        if(t>3&&t%3==1&&f==1)
        {
            ans2++;
            f=0;
        }
        else if(t<=3)
        {

        }
        else if(f)
        {
            ans2++;
        }
        if(t<=3)
        {
            ans1+=t;
            if(f)ans2+=t;
            break;
        }
        else
        {
            t=t-1-(t-1)/3;
            ans1+=1;
        }
    }
    cout<<ans1<<" "<<ans2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
