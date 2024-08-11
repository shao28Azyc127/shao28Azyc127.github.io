#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[9]={3,1,2,3,1,4,2,1,5};
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*
    1
      1:1
    1 2
      1:1
      2:2
    1 2 3
      1:1
      2:2
      3:3
    1 2 3 4
      1:1 4
      2:2
      3:3
    1 2 3 4 5
      1:1 4
      2:2
      3:3
      4:5
    1 2 3 4 5 6
      1:1 4
      2:2 6
      3:3
      4:5
    1 2 3 4 5 6 7
      1:1 4 7
      2:2 6
      3:3
      4:5
    1 2 3 4 5 6 7 8
      1:1 4 7
      2:2 6
      3:3
      4:5
      5:8
    1 2 3 4 5 6 7 8 9
      1:1 4 7
      2:2 6
      3:3 9
      4:5
      5:8
    1 2 3 4 5 6 7 8 9 10
      1:1 4 7 10
      2:2 6
      3:3 9
      4:5
      5:8
    1 2 3 4 5 6 7 8 9 10 11
      1:1 4 7 10
      2:2 6 11
      3:3 9
      4:5
      5:8
      1 2 3 3 4 4 4 5 5 5 5
      1 2 3 1 4 2 1 5 3 1 2
    */
    unsigned long long n,t=1,flag=0;
    cin>>n;
    if(n==1)
    {
        cout<<1<<' ';
    }
    else
    {
        for(int i=2;;i++)
        {
            for(int j=1;j<=i-1;j++)
            {
                t++;
                if(t==n)
                {
                    cout<<i<<' ';
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
    }
    cout<<a[n%9]<<endl;
    return 0;
}
