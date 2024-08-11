#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
queue <int> zys;
int zysfj(int a)
{
    int b = a;
    for(int i = 2;i < b / 2;)
    {
        if(a % i == 0)
        {
            a /= i;
            zys.push(i);
        }
        else
        {
            i++;
        }
    }
    return 0;
}
int zdgys(int a,int b)
{
    if(a < b)
    {
        int c = a;
        a = b;
        b = c;
    }
    int c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 0;i < t;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        long long d = (b * b) - (4 * a * c);
        if(d < 0)
        {
            cout << "NO" << endl;
            break;
        }
        double sd = sqrt(d);
        int sd1 = sd;
        if(sd1 == sd)
        {
            int down = 2 * a;
            int high = 0 - b + sd;
            if(high == 0)
            {
                cout << 0 << endl;
            }
            if(down < 0)
            {
                down = 0 - down;
                high = 0 - high;
            }
            int zh;
            if(high > 0)
            {
                zh = high;
            }
            else
            {
                zh = 0 - high;
            }
            int zd = zdgys(zh,down);
            high /= zd;
            down /= zd;
            if(down == 1)
            {
                cout << high << endl;
                break;
            }
            else
            {
                cout << high << "/" << down;
            }
        }
        else
        {
            bool sfjh = 1;
            int down = 2 * a;
            int high = 0 - b;
            if(high == 0)
            {
                sfjh = 0;
                cout << 0;
            }
            if(down < 0)
            {
                down = 0 - down;
                high = 0 - high;
            }
            int zh;
            if(high > 0)
            {
                zh = high;
            }
            else
            {
                zh = 0 - high;
            }
            int zd = zdgys(zh,down);
            high /= zd;
            down /= zd;
            if(down == 1 && high != 0)
            {
                cout << high;
            }
            if(high != 0 && down != 1)
            {
                cout << high << "/" << down;
            }




            zysfj(d);
            int last = 0;
            int rea = 1;
            while(!zys.empty())
            {
                int a = zys.front();
                zys.pop();
                if(last == a)
                {
                    rea *= a;
                    last = 0;
                }
            }
            d /= (rea * rea);
            int down1 = 2 * a;
            if(down1 < 0)
            {
                down1 = 0 - down1;
                rea = 0 - rea;
            }
            if(rea > 0)
            {
                zh = rea;
            }
            else
            {
                zh = 0 - rea;
            }
            zd = zdgys(zh,down1);
            rea /= zd;
            down1 /= zd;
            if(rea < 0)
            {
                cout << rea << "sqrt(" << d << ")/" << down1;
            }
            else if(rea == 1)
            {
                if(sfjh)
                {
                    cout << "+" << "sqrt(" << d << ")/" << down1;
                }
                else
                {
                    cout << "sqrt(" << d << ")/" << down1;
                }
            }
            else if(rea == -1)
            {
                cout << "-sqrt(" << d << ")/" << down1;
            }
            else
            {
                if(sfjh)
                {
                    cout << "+" << rea << "sqrt(" << d << ")/" << down1;
                }
                else
                {
                    cout << rea << "sqrt(" << d << ")/" << down1;
                }
            }
        }
    }
    return 0;
}