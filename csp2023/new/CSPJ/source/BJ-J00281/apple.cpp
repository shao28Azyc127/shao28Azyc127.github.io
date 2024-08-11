#include<iostream>
using namespace std;
long long n;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin >> n;
    int sum = n;
    int ans1 = 0;
    int ans2 = 0;
    int tot = 0;
    bool find = false;
    while(sum > 0)
    {
        tot++;
        if(sum % 3 == 1 && find == false)
        {
            ans2 = tot;
            find = true;
        }
        if(sum % 3 == 0)
        {
            sum -= sum / 3;
        }
        else
        {
            sum -= sum / 3 + 1;
        }

    }
    ans1 = tot;
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
