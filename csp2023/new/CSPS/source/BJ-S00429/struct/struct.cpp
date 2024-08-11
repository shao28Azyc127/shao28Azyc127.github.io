#include<bits/stdc++.h>
using namespace std;
map<string,long long> mp;
int main() {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    scanf("%d",&n);
    mp["byte"]=1;
    mp["short"]=2;
    mp["int"]=4;
    mp["long"]=8;
    while (n--) {
        int op,k;
        scanf("%d",&op);
        if (op!=1) continue;
        string s;
        cin>>s;
        scanf("%d",&k);
        long long Max=0;
        for (int i=1;i<=k;i++) {
            string x1,x2;
            cin>>x1>>x2;
            Max=max(Max,mp[x1]);
        }
        mp[s]=Max*k;
        printf("%d %d\n",Max*k,Max);
    }
    return 0;
}
