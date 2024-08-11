#include<bits/stdc++.h>
using namespace std;
int h=0;
map<int,string>mw;
map<string,int>mp;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int x;
        scanf("%d",&x);
        if(x==1){
            string s;
            int n;
            cin>>s>>n;
            for(int i=1;i<=n;++i){
                cin>>s>>s;
            }
        }else if(x==2){
            string t,n;
            cin>>t>>n;
            mp[n]=h;
            if(t=="byte"){
                for(int i=1;i<=1;++i){
                    mw[h+i]=n;
                }
                h+=1;
            }else if(t=="short"){
                for(int i=1;i<=2;++i){
                    mw[h+i]=n;
                }
                h+=2;
            }else if(t=="int"){
                for(int i=1;i<=4;++i){
                    mw[h+i]=n;
                }
                h+=4;
            }else{
                for(int i=1;i<=8;++i){
                    mw[h+i]=n;
                }
                h+=8;
            }
        }else if(x==3){
            string s;
            cin>>s;
            printf("%d\n",mp[s]);
        }else if(x==4){
            int y;
            scanf("%d",&y);
            if(mw[y]==""){
                printf("ERR\n");
            }else{
                cout<<mw[y];
            }
        }
    }
    return 0;
}
