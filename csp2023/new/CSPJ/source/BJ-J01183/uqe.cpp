#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(b==0&&c==0)   cout << "0" << endl;
        else if(b==0)
        {
            if(c>0)  cout << "NO" << endl;
            else
            {
                int x=0-c,cnt=1;
                for(int i=2;i<=31;i++)
                {
                    while(x%(i*i)==0)
                    {
                        cnt*=i;
                        x/=(i*i);
                    }
                }
                if(cnt==1)  cout << "sqrt(" << x << ")" << endl;
                else cout << cnt << "*sqrt(" << x << ")" << endl;
            }
        }
        else if(c==0)
        {
            if(b<0) cout << 0-b << endl;
            else cout << "0" << endl;
        }
    }
    return 0;
}