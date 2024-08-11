#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<char> stack_char;
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    long long n;
    string s;
    char a, b;
    long long cnt=0;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        if(stack_char.size()==0)
        {
            stack_char.push(s[i]);
        }
        else{
            if(stack_char.top() == s[i])
            {
                stack_char.pop();
                cnt++;
            }
            else{
                stack_char.push(s[i]);
            }
        }
    }
    if(stack_char.size()!=0) cout<<cnt;
    else cout<<cnt+1;
    return 0;
}
