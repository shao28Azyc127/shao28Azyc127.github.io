#include<iostream>
using namespace std;
int head=1,cnt,i=head,cnt2;
int a[100020],vis[100020];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=1,row=1,d=2,pc;
    cin >> n;
    int l=n;
    for(i=1;i<n;i++)
    {
        a[i]=i;
    }
    while(l)
    {
        int cnt=1;
        for(int k=1;k<=n;k++)
        {
             if(!vis[k])
            {
                if(cnt%3!=1){
                    cnt--;
                    continue;
                }
                cnt=3;
                l-- ;
                vis[k]=1;
                if(k==n)
                {
                    pc=row;
                }
            }
        }
        row++;

    }
    cout << row-1 << " " << pc;
    return 0;
}

