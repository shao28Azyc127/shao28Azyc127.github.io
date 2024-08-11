#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;


int n = 0;
int d = 0;
int s = 0;
int main()
{
    void print(void);
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    cin >> n;

    if (n <= 0)
    {
        print();
    }
    else
    {
        while(n > 0)
        {
            d++;
            n--;
            if ((s == 0) && (n % 3 == 0))
                s = d;
            n -= (n / 3);
        }
        print();
    }

    return 0;
}

void print()
{
    cout << d << ' ' << s << endl;
}
