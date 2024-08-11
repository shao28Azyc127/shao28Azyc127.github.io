#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int q, upper;
void outputWithFrac(double number)
{
    if(number == 1)
    {
        printf("1");
        return;
    }
    int p, q = 1;
    if(number == floor(number))
    {
        cout << number;
        return;
    }
    while(number != floor(number))
    {
        number *= 10;
        q *= 10;
    }
    p = int(number);
    for(int i = 2; i <= q; i++)
    {
        if(q % i == 0 && p % i == 0)
        {
            p /= i, q /= i;
            i--;
        }
    }
    cout << p << "/" << q;
}
bool isDou(int number)
{
    return int(sqrt(number)) * int(sqrt(number)) == number;
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &q, &upper);
    while(q--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int delta = b * b - 4 * a * c;
        cout << sqrt(delta) << endl;
        if(delta < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if(delta == 0)
        {

            outputWithFrac(-b / 1.0 / (2 * a));
            cout << endl;
            continue;
        }
        if(isDou(delta))
        {
            int sq = sqrt(delta);
            outputWithFrac(max((-b + sq) / 1.0 / (a * 2), (-b - sq) / 1.0 / (a * 2)));
            cout << endl;
            continue;
        }
    }
    return 0;
}