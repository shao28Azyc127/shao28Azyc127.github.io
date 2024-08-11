#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
set<int> st;
int f[N],c,n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) st.insert(i);
    int ans=n;
    while(ans!=0){
            int cnt=0,k=0,a[N];
            c++;
        for(auto it:st){
            cnt++;
            if(cnt%3==1){
                a[++k]=it;
                f[it]=c;
                ans--;
            }
        }
        for(int i = 1;i <= k;i++) st.erase(a[i]);
    }
    printf("%d %d",c,f[n]);
}
