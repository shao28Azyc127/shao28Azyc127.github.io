#include <bits/stdc++.h>
//#define BUG -1
using namespace std;

const int N=1e5+100;

int n,d;
int v[N];
int a[N];
int minn=100000000;
int sum=0;
int ans;
int len;
int s[N];
int sheng;

int main()
{
    ios::sync_with_stdio(false);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for (int i=1;i<=n-1;i++){
        cin >> v[i];
        sum+=v[i];
        s[i]=s[i-1]+v[i];
    }
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (a[i]<minn){
            minn=a[i];
        }
    }
    if (a[1]==minn){
        int x=sum/d;
        if (x*d!=sum){
            x++;
        }
        cout << a[1]*x << endl;
        return 0;
    }
    #ifdef BUG
    for (int i=1;i<=n;i++){
        cout << s[i] << " ";
    }
    #endif
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (a[j]<a[i]){
            	#ifdef BUG
                cout << j << "<" << i << endl;
                cout << "sheng="<< sheng << endl;
                cout << "len=" << (s[j-1]-s[i-1]) << endl;
                #endif
				int len=(s[j-1]-s[i-1]-sheng)/d;//jia duo shao sheng
                if (len*d!=(s[j-1]-s[i-1]-sheng)){
                    len++;
                }
                ans+=a[i]*len;
                sheng+=len*d-(s[j-1]-s[i-1]);
                #ifdef BUG
                cout << "from " << i << " to " << j << " add " << len << endl;
                cout << ans << endl;
                #endif
				i=j-1;
                goto abc;
            }
        }
        //mei you geng xiao de
		len=(s[n-1]-s[i-1]-sheng)/d;//jia duo shao sheng
        if (len*d!=(s[n-1]-s[i-1]-sheng)){
            len++;
        }
        ans+=a[i]*len;
        sheng+=len*d-(s[n-1]-s[i-1]);
        #ifdef BUG
        cout << "zhi sheng! from " << i << " to " << n << " add " << len << endl;
        cout << ans << endl;
        #endif
        goto ans;
        abc:;
    }
    ans:;
    cout << ans << endl;
    return 0;
}