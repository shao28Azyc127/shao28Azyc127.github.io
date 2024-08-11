#include<iostream>
using namespace std;
const int maxn =1e9 + 10;
int a[maxn];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    if(n % 3 == 0)cout<<1<<" ";
    for(int i = 1;i <= n;i++)
    {
        a[i] = i;
    }
    int cnt = n,day = 1;
    for(int i = 1;i <= n;i++)
    {
        if(cnt != 0)
        {   if(a[i] != n && i % 3 == 0)
            {
                a[i] = a[i + 1];
                cnt--;
            }
            else if(a[i] == n && i % 3 == 0)
            {
                cout<<day<<" ";
            }
        }
        else
        {
            cout<<day<<endl;
        }
    }
}