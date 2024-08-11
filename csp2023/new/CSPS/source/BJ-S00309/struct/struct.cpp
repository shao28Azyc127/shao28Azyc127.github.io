#include <bits/stdc++.h>
using namespace std;
int n,cnt=-1,res=0;
string s[101],x;
map <string,int> m;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int op;
        scanf("%d",&op);
        if(op==2){
            cin >> x;
            cin >> x;
            s[++res]=x;
            m[x]=cnt+1;
            printf("%d\n",cnt+1);
            cnt+=8;
        }
        else if(op==3){
            cin >> x;
            printf("%d\n",m[x]);
        }
        else if(op==4){
            int a;
            scanf("%d",&a);
            if(s[a/8+1]!="") cout << s[a/8+1] << "\n";
            else puts("ERR");
        }
    }
    return 0;
}
