#include<bits/stdc++.h>
using namespace std;
int x;
int f(int n)//那最后一个
{
    if (n%3==1)
        return 1;
    if (n<=3)
        return n;
    if (n%3==0)
        return 1+f(n-n/3);
    if (n%3==2)
        return 1+f(n-(n+1)/3);

}
int g(int n)//那说有苹果
{
    if (n==3)
        return 3;
    if (n==2)
        return 2;
    if (n==1)
        return 1;
    else if (n%3==0)
    {

        return 1+g(n-n/3);
    }
    else if (n%3==2)
    {
        return 1+g(n-n/3-1);
    }

    else if (n%3==1)
    {
        return 1+g(n-n/3-1);
    }

}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> x;
    cout << g(x);
    cout << " ";
    cout << f(x);
    return 0;
}
