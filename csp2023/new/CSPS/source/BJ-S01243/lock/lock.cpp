#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10;
int n,m,k,s,t,a[N],b[N];
map<int,int> se;
void aaa(){
    int xx=0;
    for (int i=0;i<5;++i) xx=xx*10+b[i];
    se[xx]++;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        for (int j=0;j<5;++j) cin>>a[j];
        for (int j=0;j<5;++j){
            for (int k=0;k<5;++k) b[k]=a[k];
            for (int k=1;k<=9;++k) {
                b[j]=(b[j]+1)%10;
                aaa();
            }
        }
        for (int j=0;j<4;++j){
            for (int k=0;k<5;++k) b[k]=a[k];
            for (int k=1;k<=9;++k) {
                b[j]=(b[j]+1)%10;
                b[j+1]=(b[j+1]+1)%10;
                aaa();
            }
        }
    }
    int ans=0;
    for (auto &i:se)
        if (i.second==n) ++ans;
    cout<<ans;

}
