#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int L[N], R[N];
string s;
int ans;
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin>>n;
    cin>>s;

    memset(R, -1, sizeof R);
    memset(L, -1, sizeof L);
    for(int i=1; i<n; i++) L[i]=i-1;
    for(int i=0; i<n-1; i++) R[i]=i+1;
    int head=0;
    while(n){
        //cout<<1<<endl;
        int t, j, i;
        //for(int i=head; i>=0; i=R[i]) cout<<s[i-1];
        //cout<<endl;
        for(i=head; i>=0; i=j){
            //cout<<2<<endl;
            t=1;
            for(j=R[i]; j>=0; j=R[j]){
                //cout<<3<<endl;
                if(s[j]==s[i]) t++;
                else {
                    if(i>0)  R[L[i]]=j;
                    else head=j;
                    L[j]=L[i];
                    break;
                }
            }
            //printf("%d", t);
            ans+=t*(t-1)/2;
            n-=t;
        }
        if(t==1) {
            break;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}