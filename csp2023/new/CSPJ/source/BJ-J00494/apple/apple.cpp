#include <iostream>
#include <cstdio>
using namespace std;


bool A[1000000000];


int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int n;
    cin >> n;

    int nd;
    int days;
    for(days = 1; ; ++days)
    {
        int flag = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(A[i]) continue;
            if(flag == 0)
            {
                A[i] = true;
                if(i == n)
                    nd = days;
            }
            flag = (flag + 1) % 3;
        }
        int OK = false;
        for(int j = 1; j <= n; ++j)
        {
            if(!A[j]) OK = true;
        }
        if(!OK) break;
    }

    cout << days << " " << nd << endl;

    return 0;
}
