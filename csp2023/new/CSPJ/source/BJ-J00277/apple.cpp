#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<functional>
#include<limits>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
long long n;
long long a[101],ans;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    a[1]=1;
    for(int i=2;i<=70;i++)
    {
        a[i]=(a[i-1]+1)/2+a[i-1];
    }
    //cout<<a[70];
    for(int i=1;i<=70;i++)
    {
        if(a[i]>n)
        {
            break;
        }
        ans=i;
    }
    cout<<ans<<' ';
    int m=n;
    ans=0;
    while(m%3!=1)
    {
        m-=(m+2)/3;
        ans++;
    }
    cout<<ans+1;
    return 0;
}
/*
1 2 3 4 5 6 7 8 9
2 3 5 6 8 9       1 4 7
3 5 8 9           2 6
5 8               3 9
8                 5
                  8



1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
2 3 5 6 8 9 11 12 14 15 17 18 20 21 23 24
3 5 8 9 12 14 17 18 21 23
5 8 12 14 18 21
8 12 18 21
12 18
18


*/
