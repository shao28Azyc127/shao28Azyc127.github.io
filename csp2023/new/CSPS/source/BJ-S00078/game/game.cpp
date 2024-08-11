#include <iostream>
#include <string>
using namespace std;
bool chk(string x)
{
    int len = x.size();
    int sum = 0;
    int lastsum = 0;
    while(sum != len)
    {
        lastsum = sum;
        //cout << sum << " ";
        int last = 0;
        for(int i = 0 ; i < x.size() ; i ++)
        {
            if(x[i] == '.')
            {
                last = i - 1;
                int j = i;
                while(x[j] == '.')
                {
                    j ++;
                }
                i = j - 1;
            }
            if(x[last] == x[i + 1])
            {
                x[i] = '.';
                x[i + 1] = '.';
                i = i + 2;
                sum += 2;
                last = i + 2;
            }
        }
        if(lastsum == sum)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("game.in" , "r" , stdin);
    freopen("game.out" , "w" , stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0 ; i < n - 2; i ++)
    {
        for(int j = 2 ; j <= n ; j ++)
        {
            string x = s.substr(i , j);
            cnt += chk(x);
        }
    }
    cout << cnt << endl;
    return 0;
}
