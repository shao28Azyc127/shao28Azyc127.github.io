#include<bits/stdc++.h>
#pragma GCC(2)
using namespace std;
long long a , b , c , delta , t , m , on , down , n;
int main()
{
    freopen("uqe.in"  ,  "r" ,  stdin);
    freopen("uqe.out" , "w" ,  stdout);
    cin >> t >> m;
    while(t--)
    {
        n = 1;
        scanf("%lld%lld%lld" , &a , &b , &c);
        delta = b * b - 4 * a * c;
        if(delta < 0)
        {
            cout << "NO\n";
            continue;
        }
        if(delta == 0)
        {
            on  = -b;
            down = 2 * a;
            if(on%down== 0)
            {
                cout << on / down << endl;
            }
            else
            {
                for(int i = 2 ; i <= min(on , down) ;  i++ )
                {
                    while(on % i == 0 && down % i == 0)
                    {
                        on /= i;
                        down /= i;
                    }
                }
                cout << on << "/" << down << endl;
            }
        }
        if((1.0 * -b + sqrt(delta)) / (2 * a) > (1.0 * -b - sqrt(delta)) / (2 * a))
        {
            if(int(sqrt(delta)) * int(sqrt(delta)) == delta)
            {
                on = -b + sqrt(delta);
                down = 2 * a;
                for(int i = 2 ; i <= min(on , down) ;  i++ )
                {
                    while(on % i == 0 && down % i == 0)
                    {
                        on /= i;
                        down /= i;
                    }
                }
                if(on%down== 0)
                {
                    cout << on / down << endl;
                }
                else
                {
                    cout << on << "/" << down << endl;
                }
                continue;
            }
            for(int i = 2 ; i * i <= delta ; i++)
            {
                if(int(1.0 * delta / (i * i)) == 1.0 * delta / (i * i))
                {
                    n = i;
                }
            }
            on = -b;
            down = 2 * a;
            int tmp = down;
            for(int i = 2 ; i <= min(on , down) ;  i++ )
            {
                while(on % i == 0 && down % i == 0)
                {
                    on /= i;
                    down /= i;
                }
            }
            if(on % down == 0 && on  == 0)
            {

            }
            else if(on%down == 0)
            {
                cout << on / down << "+";
            }
            else
            {
                cout << on << "/" << down << "+";
            }
            if(n != 1)
            {
                cout << n << "*";
            }
            cout << "sqrt(" << delta / (n * n) << ")" << "/" << tmp << endl;
        }
        else
        {
            if(int(sqrt(delta)) * int(sqrt(delta)) == delta)
            {
                on = -b + sqrt(delta);
                down = 2 * a;
                for(int i = 2 ; i <= min(on , down) ;  i++ )
                {
                    while(on % i == 0 && down % i == 0)
                    {
                        on /= i;
                        down /= i;
                    }
                }
                if(on%down== 0)
                {
                    cout << on / down << endl;
                }
                else
                {
                    cout << on << "/" << down << endl;
                }
                continue;
            }
            for(int i = 2 ; i * i <= delta ; i++)
            {
                if(int(1.0 * delta / (i * i)) == 1.0 * delta / (i * i))
                {
                    n = i;
                }
            }
            on = -b;
            down = 2 * a;
            int tmp= down;
            for(int i = 2 ; i <= min(on , down) ;  i++ )
            {
                while(on % i == 0 && down % i == 0)
                {
                    on /= i;
                    down /= i;
                }
            }
            if(on % down == 0 && on  == 0)
            {

            }
            else if(on%down == 0)
            {
                cout << on / down << "+";
            }
            else
            {
                cout << on << "/" << down << "+";
            }
            cout << -1 * n <<"*sqrt(" << delta / (n * n)<< ")" << "/" << tmp << endl;
        }
    }
    return 0;
}
