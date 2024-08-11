#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int op;
string a[110];
int b[110];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    string s;
    string c,na;
    int k;
    while(n--){
        scanf("%d",&op);
        if(op==1){
            cin>>s;
            cin>>k;
            long long v = 0,res = 0;
            for(int i = 1;i<=k;i++){
                cin>>a[i]>>na;
                long long t = 0;
                if(a[i]=="short"){res+=2,t = 2;}
                if(a[i]=="int"){res+=4,t = 4;}
                if(a[i]=="long"){res==8,t = 8;}
                if(a[i]=="double"){res+=8,t = 8;}
                if(a[i]=="bool"){res+=1,t = 1;}
                v = max(v,t);
            }
            int sum = res/v;
            if(res%v!=0)sum+=1;
            printf("%d %d",sum*v,v);
        }
    }

    return 0;
}
