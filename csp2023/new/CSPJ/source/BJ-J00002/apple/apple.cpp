#include<cstdio>
#include<iostream>
using namespace std;

long long t,n,t2;
bool f = false;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >>n;
    t = n;
    int cnt = 0,cnt2 = 0;
    while(t > 0)
    {
        if(t % 3 == 1 && f == false)
        {
            cnt2 = cnt + 1;
            f = true;
        }

        cnt++;
        long long m;
        if(t % 3 == 0)m = t / 3;
        else m = t / 3 + 1;
        t -= m;

    }
    cout << cnt << " " << cnt2 << endl;
    return 0;
}
