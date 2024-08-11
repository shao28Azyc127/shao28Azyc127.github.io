#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int T,M;
int gcd(int x,int y)
{
    for(int i=min(x,y);i>=1;i--)
    {
        if(x%i==0&&y%i==0)
        {
            return i;
        }
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> T >> M;
    for(int i=0;i<T;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int dt=pow(b,2)-4*a*c;
        if(dt<0)
        {
            cout << "NO" <<endl;
        }
        else
        {
            int x1=(b*(-1)+sqrt(dt))/(2*a);
            int x2=(b*(-1)-sqrt(dt))/(2*a);
            int temp=max(x1,x2);
            int p,q;
            for(int i=1;i<=M;i++)
            {
                int j=temp*i;
                if(gcd(i,j)==1)
                {
                    q=i;
                    p=j;
                    break;
                }
            }
            if(q==1)
            {
                cout << p <<endl;
            }
            else
            {
                cout << p << "/" << q <<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
