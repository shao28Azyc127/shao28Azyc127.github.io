#include <fstream>
#include <string>
#include <stack>
using namespace std;
ifstream cin ("game.in");
ofstream cout ("game.out");
bool chk[2000010];
stack <int> st;
int main ()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=' '+s;
    long long int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (not chk[i])
        {
            while (not st.empty())
            {
                st.pop();
            }
            int t=0;
            for (int j=i;j<=n;j++)
            {
                if (st.empty() or s[st.top()]!=s[j])
                {
                    st.push(j);
                }
                else
                {
                    st.pop();
                }
                if (st.empty())
                {
                    chk[j+1]=1;
                    t++;
                }
            }
            ans+=1ll*t*(t+1)/2ll;
        }
    }
    cout<<ans<<endl;
}