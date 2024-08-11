#include<bits/stdc++.h>
using namespace std;
int n,ans,k=3,s;
bool flag=0;
queue<int>q;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for (int i=2;i<=n;i++) if (n%3!=1) q.push(i);
    if (q.back()!=n) cout<<"1 ",flag=1;
    ans++;
    while (q.size()){
        q.pop();
        for (int i=1;i<q.size();i++){
            if (i%3!=0) q.push(q.front());
            q.pop();
        }
        if (q.back()!=n && flag==0) cout<<s<<" ",flag=1;
        s++;
        ans++;
    }
    cout<<ans;
    return 0;
}
