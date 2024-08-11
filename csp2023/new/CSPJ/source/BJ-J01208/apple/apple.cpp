#include <iostream>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.ans", "w", stdout);
    int n, i = 0, j = 0;
    bool flag = true;
    cin >> n;
    while(n != 0)
    {
        i++;
        if(n % 3 != 1 && flag == true)
        {
            j++;
        }
        if(n % 3 == 1) flag = false;
        n -= (n - 1) / 3 + 1;
    }
    cout << i << " " << j + 1 << endl;
    return 0;
}