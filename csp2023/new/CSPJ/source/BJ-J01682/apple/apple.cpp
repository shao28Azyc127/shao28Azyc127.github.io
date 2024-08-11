#include <bits/stdc++.h>
using namespace std;
int n;
queue<int> a;
int day,ans;
int num;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    num=n;
    for (int i=1;i<=n;i++)
    {
        a.push(i);
    }
    while (!a.empty())
    {
        day++;
        int j;
        if (num%3==0)
        {
            j=num/3;
        }
        else
        {
            j=num/3+1;
        }
        int point=0;

        for (int i=1;i<=j;i++)
        {

            if (a.front()==n)
            {
                ans=day;

            }
            a.pop();
            num--;
            if (!a.empty() && point<num)
            {
                a.push(a.front());
                a.pop();
                point++;
            }
             if (!a.empty() && point<num)
            {
                a.push(a.front());
                a.pop();
                point++;
            }


        }
    }
    cout<<day<<" "<<ans;
    return 0;
}