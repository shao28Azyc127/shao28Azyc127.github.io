#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool f(string s)
{
    //map<char,int> m;
    if(int(s.size())&1) return 0;
    //for(auto i:s) m[i]++;
    //for(auto i=m.begin();i!=m.end();i++) if(i->second%2) return 0;
    else
    {
        while(s.size()>=2)
        {
            bool flag=1;
            for(int i=0;i<=s.size()-2;i++)
            {
                if(s[i]==s[i+1])
                {
                    s.erase(i,2);
                    flag=0;
                    break;
                }
            }
            if(flag) return 0;
        }
    }
    return 1;

}
bool b[10050][10050];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int l;
    cin>>l;
    ll ans=0;
    string s;
    cin>>s;
    for(int i=0;i<l;i++)
    {
        for(int j=2;i+j<=l;j+=2)
        {

            if(b[i][j-2]&&s[i+j-1]==s[i+j-2]||b[i][j-4]&&s[i+j-1]==s[i+j-2]&&s[i+j-3]==s[i+j-4]&&s[i+j-1]==s[i+j-3]||b[i][j-6]&&s[i+j-1]==s[i+j-2]&&s[i+j-3]==s[i+j-4]&&s[i+j-5]==s[i+j-6]&&s[i+j-1]==s[i+j-3]&&s[i+j-1]==s[i+j-5]||i>=2&&b[i-2][j+2]&&s[i-2]==s[i-1]||i>=4&&b[i-4][j+4]&&s[i-4]==s[i-3]&&s[i-2]==s[i-1]&&s[i-1]==s[i-3]||i>=6&&b[i-6][j+6]&&s[i-6]==s[i-5]&&s[i-4]==s[i-3]&&s[i-2]==s[i-1]&&s[i-6]==s[i-4]&&s[i-6]==s[i-2]||f(s.substr(i,j))) ans++,b[i][j]=1;//,cout<<s.substr(i,j)<<endl;
        }
    }
    cout<<ans;
    return 0;
}//38727,0.627s,0.551s,0.531s,0.497s
