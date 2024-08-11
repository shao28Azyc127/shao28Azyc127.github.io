#include<iostream>
#include<cstring>
using namespace std;
const int N=1e6+9;
bool b[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int n;
    cin >> n;
    int dl=0;
    int ans=0;
    int ans2=0;

    while(dl<=n)
    {

        int k=0;
        bool flag=0;
        for(int i=1; i<=n; i++)
        {
            if(b[i]==0)
            {
                flag=1;
                k++;
                if(k%3==1)
                {
                    b[i]=1;
                    dl++;
                    if(i==n) ans2=ans+1;
                }

            }

        }
        if(!flag) break;
        ans++;
      //  cout << ans <<endl;
    }
    cout << ans << " " << ans2 << endl;
    return 0;
}
