#include <bits/stdc++.h>
using namespace std;

string a[3005];
string maxa[3005];
string minmaxa;
int n,m;

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    minmaxa="";
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sort(a[i].begin(),a[i].end());
        maxa[i]=a[i];
        reverse(maxa[i].begin(),maxa[i].end());
        if(minmaxa==""||minmaxa>maxa[i]){
            minmaxa=maxa[i];
        }
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cout<<(a[i]<=minmaxa?1:0);
    }
    cout<<endl;
    return 0;
}
