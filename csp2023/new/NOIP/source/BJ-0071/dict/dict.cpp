#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
ifstream cin ("dict.in");
ofstream cout ("dict.out");
string s[3010];
int main ()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    int mi1=0,mi2=0;
    for (int i=1;i<=n;i++)
    {
        sort(s[i].begin(),s[i].end(),[](char a,char b){return a>b;});
        if (mi1==0 or s[i]<s[mi1])
        {
            mi2=mi1;
            mi1=i;
        }
        else if (mi2==0 or s[i]<s[mi2])
        {
            mi2=i;
        }
    }
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (s[i]==s[mi1])
        {
            cnt++;
        }
    }
    string tmp1=s[mi1],tmp2=s[mi2];
    for (int i=1;i<=n;i++)
    {
        string ls=s[i];
        sort(s[i].begin(),s[i].end());
        if (ls==tmp1)
        {
            if (cnt==1)
            {
                cout<<(s[i]<tmp2);
            }
            else
            {
                cout<<(s[i]<tmp1);
            }
        }
        else
        {
            cout<<(s[i]<tmp1);
        }
    }
    cout<<endl;
}