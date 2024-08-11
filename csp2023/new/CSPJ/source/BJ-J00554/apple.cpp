#include <iostream>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >>n;
    int cnt = 1;
    int ans;
    for(int i = 1;i <= n;i++)
    {
        cnt += i;
        if((n-cnt) < i+1)
        {
            ans = i+2;
            cout <<i+2<<" ";
            break;
        }
    }
    if(n % 3 == 1) cout <<1<<endl;
    else cout <<ans<<endl;
    return 0;
}
