#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e6+10;
int n;
char s[maxn],tmp[maxn];
int mat[maxn],cnt[maxn],lst[maxn];
int ans;
void sol()
{
    memset(mat,0,sizeof(mat));
    memset(cnt,0,sizeof(cnt));
    stack<int> st;
    for(int i=1;i<=n;i++)
    {
        if(st.empty())
        {
            st.push(i);
            continue;
        }
        if(s[st.top()]==s[i])
        {
            mat[st.top()]=i;
            mat[i]=st.top();
            if(mat[i]!=lst[i]) ans++;
            st.pop();
        }
        else st.push(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(!mat[i]) continue;
        if(mat[i]<i) continue;
        if(!mat[i-1]||mat[i-1]>i)
        {
            cnt[i]=1;
            cnt[mat[i]]=1;
            continue;
        }
        cnt[mat[i]]=cnt[i]=cnt[i-1]+1;
        if(mat[i]!=lst[i]) ans+=cnt[mat[i]]-1;
    }
}
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld%s",&n,s+1);

    if(n<=8000)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            stack<int> st;
            for(int j=i;j<=n;j++)
            {
                if(st.empty())
                {
                    st.push(j);
                    continue;
                }
                if(s[st.top()]==s[j]) st.pop();
                else st.push(j);
                if(st.empty())
                {
                    //cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        return 0;
    }


    sol();
    int c=0,t=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i]!=s[i-1])
        {
            if(t>=4&&t%2==0)
            {
                int tmp=(t-2)/2;
                c+=tmp*(tmp+1)/2;
            }
            t=1;
        }
        else t++;
    }
    if(t%2==0) c+=(t-2)/2;
    for(int i=1;i<=n;i++) lst[i]=n-mat[n-i+1]+1;
    sol();
    printf("%lld\n",ans+c);
	return 0;
}
