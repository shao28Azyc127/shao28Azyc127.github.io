#include<iostream>
using namespace std;
#define maxn 100000
int x;
bool a[maxn+100];
pair<int,int>fun(int n)
{
    int c=n,l=1,ll=-1;
    for(int i=0;i<n;i++)a[i]=false;
    while(c)
    {
        int cnt=3;
        for(int i=0;i<n;i++)
            if(!a[i])
            {
                if(cnt==3)
                {
                    if(i==n-1)ll=l;
                    a[i]=true;
                    c--;
                    cnt=0;
                }
                cnt++;
            }
        l++;
    }
    return{l-1,ll};
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>x;
    pair<int,int>ans=fun(x);
    cout<<ans.first<<" "<<ans.second<<"\n";
    return 0;
}