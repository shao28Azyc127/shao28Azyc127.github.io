#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int T, M;
int fenzi2_1, fenzi2_2, fenzi2_3;
int fang[1005];
int gcd(int x, int y)
{
    if(y == 0) return x;
    return gcd(y, x % y);
}
void fang_delta(int x)
{
    for(int i = 1001;i >= 2;i --)
    {
        if(fenzi2_2 % fang[i] == 0)
        {
            fenzi2_2 /= fang[i];
            fenzi2_1 *= i;
            fenzi2_3 *= i;
        }
    }
    return;
}
void init()
{
    for(int i = 1;i <= 1001;i ++) fang[i] = i * i;
    return;
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &M);
    init();
    while(T --)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int delta = b * b - 4 * a * c;
        if(delta < 0)
        {
            puts("NO");
            continue;
        }
        fenzi2_1 = 1, fenzi2_2 = delta, fenzi2_3 = -1;
        int fenmu = 2 * a;
        int fenzi1 = -b;
        int gongyue1 = gcd(abs(fenmu), abs(fenzi1));
        if(fenzi1 < 0 && fenmu < 0) gongyue1 *= -1;
        fang_delta(delta);
        int gongyue2 = gcd(abs(fenmu), abs(fenzi2_1));
        if(fenzi2_1 < 0 && fenmu < 0) gongyue2 *= -1;
        int gongyue3 = gcd(abs(fenmu), abs(fenzi2_3));
        if(fenzi2_3 < 0 && fenmu < 0) gongyue3 *= -1;
        int lastgongyue1 = gcd(abs(gongyue1), abs(gongyue2));
        if(gongyue1 < 0 && gongyue2 < 0) lastgongyue1 *= -1;
        int lastgongyue2 = gcd(abs(gongyue1), abs(gongyue3));
        if(gongyue1 < 0 && gongyue3 < 0) lastgongyue2 *= -1;
        int ans1_1 = fenmu / lastgongyue1;
        int ans1_2 = fenzi1 / lastgongyue1;
        int ans1_3 = fenzi2_1 / lastgongyue1;
        int ans1_4 = fenzi2_2;
        int ans2_1 = fenmu / lastgongyue2;
        int ans2_2 = fenzi1 / lastgongyue2;
        int ans2_3 = fenzi2_3 / lastgongyue2;
        int ans2_4 = fenzi2_2;
        // cout << ans1_1 << " " << ans1_2 << " " << ans1_3 << " " << ans1_4 << endl;
        // cout << ans2_1 << " " << ans2_2 << " " << ans2_3 << " " << ans2_4 << endl;
        if(fenmu > 0) // ans1
        {
            if(ans1_1 != 1)
            {
                if(ans1_4 == 1 && ans1_3 == 1)
                {
                    int he = ans1_2 + 1;
                    int yuee = gcd(he, ans1_1);
                    if(ans1_1 / yuee < 0) yuee *= -1;
                    if(ans1_1 / yuee != 1)
                    cout << he / yuee << '/' << ans1_1 / yuee << endl;
                    else
                    cout << he / yuee << endl;
                }
                else if(ans1_4 == 1)
                {
                    int he = ans1_2 + ans1_3;
                    int yuee = gcd(he, ans1_1);
                    if(ans1_1 / yuee < 0) yuee *= -1;
                    if(ans1_1 / yuee != 1)
                    cout << he / yuee << '/' << ans1_1 / yuee << endl;
                    else
                    cout << he / yuee << endl;
                }
                else if(ans1_3 == 1)
                {
                    int yuee = gcd(ans1_2, ans1_1);
                    if(ans1_1 / yuee < 0) yuee *= -1;
                    if(ans1_1 / yuee != 1)
                    cout << ans1_2 / yuee << '/' << ans1_1 / yuee << '+';
                    else
                    cout << ans1_2 / yuee << '+';
                    cout << "sqrt(" << ans1_4 << ")" << '/' << ans1_1 << endl;
                }
                else
                {
                    if((ans1_4 == 0 || ans1_3 == 0) && ans1_2 == 0)
                    {
                        cout << 0 << endl;
                    }
                    else if(ans1_4 == 0 || ans1_3 == 0)
                    {
                        int yuee = gcd(ans1_2, ans1_1);
                        if(ans1_1 / yuee < 0) yuee *= -1;
                        if(ans1_1 / yuee != 1)
                        cout << ans1_2 / yuee << '/' << ans1_1 / yuee << endl;
                        else
                        cout << ans1_2 / yuee << endl;
                    }
                    else if(ans1_2 == 0)
                    {
                        int yuee = gcd(ans1_3, ans1_1);
                        if(ans1_1 / yuee < 0) yuee *= -1;
                        if(ans1_1 / yuee != 1)
                        cout << ans1_3 / yuee << '*' << "sqrt(" << ans1_4 << ")" << '/' << ans1_1 / yuee << endl;
                        else
                        cout << ans1_3 / yuee << '*' << "sqrt(" << ans1_4 << ")" << endl;
                    }
                    else
                    {
                        int yuee = gcd(ans1_2, ans1_1);
                        if(ans1_1 / yuee < 0) yuee *= -1;
                        if(ans1_1 / yuee != 1)
                        cout << ans1_2 / yuee << '/' << ans1_1 / yuee << '+';
                        else
                        cout << ans1_2 / yuee << '+';

                        yuee = gcd(ans1_3, ans1_1);
                        if(ans1_1 / yuee < 0) yuee *= -1;
                        if(ans1_1 / yuee == 1 && ans1_3 / yuee == 1)
                        cout << "sqrt(" << ans1_4 << ")" << endl;
                        else if(ans1_3 / yuee == 1)
                        cout << "sqrt(" << ans1_4 << ")" << '/' << ans1_1 / yuee << endl;
                        else if(ans1_1 / yuee == 1)
                        cout << ans1_3 / yuee << '*' << "sqrt(" << ans1_4 << ")" << endl;
                        else
                        cout << ans1_3 / yuee << '*' << "sqrt(" << ans1_4 << ")" << '/' << ans1_1 / yuee << endl;
                    }
                }
            }
            if(ans1_1 == 1)
            {
                if(ans1_4 == 1 && ans1_3 == 1)
                {
                    cout << ans1_2 + 1 << endl;
                }
                else if(ans1_4 == 1)
                {
                    cout << ans1_2 + ans1_3 << endl;
                }
                else if(ans1_3 == 1)
                {
                    cout << ans1_2 << '+';
                    cout << "sqrt(" << ans1_4 << ")" << endl;
                }
                else
                {
                    if((ans1_4 == 0 || ans1_3 == 0) && ans1_2 == 0)
                    {
                        cout << 0 << endl;
                    }
                    else if(ans1_4 == 0 || ans1_3 == 0)
                    {
                        cout << ans1_2 << endl;
                    }
                    else if(ans1_2 == 0)
                    {
                        cout << ans1_3 << '*' << "sqrt(" << ans1_4 << ")" << endl;
                    }
                    else
                    {
                        cout << ans1_2 << '+';
                        cout << ans1_3 << '*' << "sqrt(" << ans1_4 << ")" << endl;
                    }
                }
            }
        }
        if(fenmu < 0) // ans2
        {
            if(ans2_1 != 1)
            {
                if(ans2_4 == 1 && ans2_3 == 1)
                {
                    int he = ans2_2 + 1;
                    int yuee = gcd(he, ans2_1);
                    if(ans2_1 / yuee < 0) yuee *= -1;
                    if(ans2_1 / yuee != 1)
                    cout << he / yuee << '/' << ans2_1 / yuee << endl;
                    else
                    cout << he / yuee << endl;
                }
                else if(ans2_4 == 1)
                {
                    int he = ans2_2 + ans2_3;
                    int yuee = gcd(he, ans2_1);
                    if(ans2_1 / yuee < 0) yuee *= -1;
                    if(ans2_1 / yuee != 1)
                    cout << he / yuee << '/' << ans2_1 / yuee << endl;
                    else
                    cout << he / yuee << endl;
                }
                else if(ans2_3 == 1)
                {
                    int yuee = gcd(ans2_2, ans2_1);
                    if(ans2_1 / yuee < 0) yuee *= -1;
                    if(ans2_1 / yuee != 1)
                    cout << ans2_2 / yuee << '/' << ans2_1 / yuee << '+';
                    else
                    cout << ans2_2 / yuee << '+';
                    cout << "sqrt(" << ans2_4 << ")" << '/' << ans2_1 << endl;
                }
                else
                {
                    if((ans2_4 == 0 || ans2_3 == 0) && ans2_2 == 0)
                    {
                        cout << 0 << endl;
                    }
                    else if(ans2_4 == 0 || ans2_3 == 0)
                    {
                        int yuee = gcd(ans2_2, ans2_1);
                        if(ans2_1 / yuee < 0) yuee *= -1;
                        if(ans2_1 / yuee != 1)
                        cout << ans2_2 / yuee << '/' << ans2_1 / yuee << endl;
                        else
                        cout << ans2_2 / yuee << endl;
                    }
                    else if(ans2_2 == 0)
                    {
                        int yuee = gcd(ans2_3, ans2_1);
                        if(ans2_1 / yuee < 0) yuee *= -1;
                        if(ans2_1 / yuee != 1)
                        cout << ans2_3 / yuee << '*' << "sqrt(" << ans2_4 << ")" << '/' << ans2_1 / yuee << endl;
                        else
                        cout << ans2_3 / yuee << '*' << "sqrt(" << ans2_4 << ")" << endl;
                    }
                    else
                    {
                        int yuee = gcd(ans2_2, ans2_1);
                        if(ans2_1 / yuee < 0) yuee *= -1;
                        if(ans2_1 / yuee != 1)
                        cout << ans2_2 / yuee << '/' << ans2_1 / yuee << '+';
                        else
                        cout << ans2_2 / yuee << '+';

                        yuee = gcd(ans2_3, ans2_1);
                        if(ans2_1 / yuee < 0) yuee *= -1;
                        if(ans2_1 / yuee == 1 && ans2_3 / yuee == 1)
                        cout << "sqrt(" << ans2_4 << ")" << endl;
                        else if(ans2_3 / yuee == 1)
                        cout << "sqrt(" << ans2_4 << ")" << '/' << ans2_1 / yuee << endl;
                        else if(ans2_1 / yuee == 1)
                        cout << ans2_3 / yuee << '*' << "sqrt(" << ans2_4 << ")" << endl;
                        else
                        cout << ans2_3 / yuee << '*' << "sqrt(" << ans2_4 << ")" << '/' << ans2_1 / yuee << endl;
                    }
                }
            }
            if(ans2_1 == 1)
            {
                if(ans2_4 == 1 && ans2_3 == 1)
                {
                    cout << ans2_2 + 1 << endl;
                }
                else if(ans2_4 == 1)
                {
                    cout << ans2_2 + ans2_3 << endl;
                }
                else if(ans2_3 == 1)
                {
                    cout << ans2_2 << '+';
                    cout << "sqrt(" << ans2_4 << ")" << endl;
                }
                else
                {
                    if((ans2_4 == 0 || ans2_3 == 0) && ans2_2 == 0)
                    {
                        cout << 0 << endl;
                    }
                    else if(ans2_4 == 0 || ans2_3 == 0)
                    {
                        cout << ans2_2 << endl;
                    }
                    else if(ans2_2 == 0)
                    {
                        cout << ans2_3 << '*' << "sqrt(" << ans2_4 << ")" << endl;
                    }
                    else
                    {
                        cout << ans2_2 << '+';
                        cout << ans2_3 << '*' << "sqrt(" << ans2_4 << ")" << endl;
                    }
                }
            }
        }
    }
    return 0;
}