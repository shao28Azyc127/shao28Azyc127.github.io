#include<iostream>
using namespace std;
int cnt=0;
string c;
string s;
string w;
int n;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            s[j]=c[j];
            w=c;
            for(int k=i+1;k<=j;k++)
            {
                if(w[k]==w[k+1])
                {
                    w[k]=' ';
                    w[k+1]=' ';
                }
            }
        }
        if(w=="")
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
