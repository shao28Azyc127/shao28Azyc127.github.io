#include<bits/stdc++.h>
using namespace std;

int n;
string str;
bool check(int S,int T)
{   
    stack<char> s;
    for(int i=S;i<=T;i++)
    {
        char ch=str[i];
        if(s.empty())  s.push(ch);
        else if(s.top()==ch)  s.pop();
        else  s.push(ch);
    }
    if(s.empty())  return 1;
    else  return 0;
}
int Solve_bl()
{
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(check(i,j))  ret++;
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>str;
    str='*'+str;
    cout<<Solve_bl()<<endl;
    return 0;
}