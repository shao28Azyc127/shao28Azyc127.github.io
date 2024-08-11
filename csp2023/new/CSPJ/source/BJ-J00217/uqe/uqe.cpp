#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool iss(int n)
{
    if(int(sqrt(n)) * int(sqrt(n)) == n) return 1;
    return 0;
}
int ch(int n)
{
    for (int i = n;i >= 2;i--)
        if (n % i == 0 && iss(i))
            return int(sqrt(i));
    return 1;
}
int main()
{
    freopen("upe.in","r",stdin);
    freopen("upe.out","w",stdout);
    int t,n;
    cin >> t >> n;
    for (int i = 1;i <= t;i++)
    {
        int a,b,c;
        cin >> a >> b >>c;
        if (b == 0 && c == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (b * b - 4 * a * c < 0)
        {
            cout << "NO"<< endl;
            continue;
        }
        else if (b * b - 4 * a * c == 0)
        {
            if (-b / 2.0 / a * 2 * a== -b * 1.0)
                cout << -b / 2 / a;
            else
                printf("%d/%d\n",-1*b,2 * a);
        }
        else if(b*b-4*a*c==1) cout << 1;
        else
        {
            double p = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
            if (ch(4 * a * c)==1&&b/2/a*2*a!=b)
                printf("%d/%d+sqrt(%d)/%d\n",-b,2*a,b*b-4*a*c,2*a);
            else if(ch(b*b-4 * a * c)==1&&b/2/a*2*a==b)
                printf("%d+sqrt(%d)/%d\n",-b/2*a,b*b-4*a*c,2*a);
            else if(ch(b*b-4 * a * c)!=1&&b/2/a*2*a!=b)
                printf("%d/%d+%d*sqrt(%d)/%d\n",-b,2*a,ch(b*b-4*a*c),b*b-4*a*c/ch(b*b-4*a*c),2*a);
            else if(ch(b*b-4 * a * c)!=1&&b/2/a*2*a!=b)
                printf("%d+%d*sqrt(%d)/%d\n",-b/2*a,ch(b*b-4*a*c),b*b-4*a*c/ch(b*b-4*a*c),2*a);
        }
    }
    return 0;
}