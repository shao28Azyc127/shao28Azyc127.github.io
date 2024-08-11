#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a,a1 = 0,a2 = 0;
    int s;
    cin >> a;
    for(int i = 1;i > 0;i++)
    {
        if((a - 1)%3 == 0&&a2 == 0)
        {
            a2 = i;
        }
        a -= (a + 2)/3;
        if(a <= 0)
        {
            a1 = i;
            break;
        }
    }
    cout << a1 << ' ' << a2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}