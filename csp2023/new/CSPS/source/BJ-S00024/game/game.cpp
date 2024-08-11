#include <bits/stdc++.h>
using namespace std;
string str;
bool cl(int a,int b)
{
    stack <int>num;
    for(int i=a;i<=b;i++)
    {
        if(!num.empty()&&str[i]==num.top()) num.pop();
        else num.push(str[i]);
    }
    if(num.empty()) return 1;
    return 0;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;

    cin>>str;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((j-i+1)%2!=0)
            {
                continue;
            }
            else{
                if(cl(i,j))
                {
                    sum++;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
