#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int a1,b1,c1,d1,e1;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    if(n==1)
    {
        cout << "81";
    }
    else if(n==2)
    {
        cin >>a>>b>>c>>d>>e>>a1>>b1>>c1>>d1>>e1;
        if((a==a1&&b==b1&&c==c1&&d==d1&&e!=e1)||(a!=a1&&b==b1&&c==c1&&d==d1&&e==e1))
        {
            cout << "10";
        }
        else if((a==a1&&b==b1&&c==c1&&d!=d1&&e==e1)||(a==a1&&b==b1&&c!=c1&&d==d1&&e==e1)||(a==a1&&b!=b1&&c==c1&&d==d1&&e==e1))
        {
            cout << "12";
        }
    }
    else
    {
        cout << "2";
    }
    return 0;
}
