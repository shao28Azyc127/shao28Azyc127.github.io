#include<bits/stdc++.h>
using namespace std;
//cout << "thanks god,places help me AK CSP-J" << endl£»
const int N=1e9+1;
bool a[N];
long long ans,j=1;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin >> n;
    long long k=n,qn=n;
    memset(a,1,sizeof a);
    long long cnt=3;
    while(n>0)
    {
        for(long long i=j;i<=qn;i++)
        {
            if(cnt==3&&a[i]==1)
            {
                if(k==i)
                {
                    ans=j;
                }
                a[i]=0;
                //cerr << i << ' ';
                n--;
                cnt=1;
            }
            else if(a[i]==1) cnt++;
        }
        //cerr << endl;
        cnt=3;
        j++;
    }
    cout << j-1 << ' ' << ans;
    return 0;
}
