//struct.cpp
#include <bits/stdc++.h>
using namespace std;
long long n,alladr;
map<string,long long> mp;
map<long long,string> mp2;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%lld",&n);
    while(n--){
        int opt;
        scanf("%lld",&opt);
        string typ,nam,bigtype,types[105],nams[105];
        int allnum,maxx=0;
        if(opt==1){
            cin>>bigtype>>allnum;
            for(int i=0;i<allnum;i++){
                cin>>types[i]>>nams[i];
                if(types[i]=="byte"){
                      maxx=max(maxx,1);
                }else if(types[i]=="short"){
                    maxx=max(maxx,2);
                }else if(types[i]=="int"){
                    maxx=max(maxx,4);
                }else if(types[i]=="long"){
                    maxx=max(maxx,8);
                }
            }
            }


        if(opt==2){
            cin>>typ>>nam;
            if(typ=="byte"){
                mp[nam]=alladr;
                mp2[alladr]=nam;
                alladr+=1;
            }else if(typ=="short"){
                mp[nam]=alladr;
                for(int i=0;i<2;i++)mp2[alladr+i]=nam;
                alladr+=2;
            }else if(typ=="int"){
                mp[nam]=alladr;
                for(int i=0;i<4;i++)mp2[alladr+i]=nam;
                alladr+=4;
            }else if(typ=="long"){
                mp[nam]=alladr;
                for(int i=0;i<8;i++)mp2[alladr+i]=nam;
                alladr+=8;
            }else if(typ==bigtype){
                for(int i=0;i<allnum;i++){
                if(typ=="byte"){
                mp[typ+"."+nams[i]]=alladr;
                mp2[alladr]=typ+"."+nams[i];
                alladr+=1;
            }else if(typ=="short"){
                mp[typ+"."+nams[i]]=alladr;
                for(int i=0;i<2;i++)mp2[alladr+i]=typ+"."+nams[i];
                alladr+=2;
            }else if(typ=="int"){
                mp[typ+"."+nams[i]]=alladr;
                for(int i=0;i<4;i++)mp2[alladr+i]=typ+"."+nams[i];
                alladr+=4;
            }else if(typ=="long"){
                mp[typ+"."+nams[i]]=alladr;
                for(int i=0;i<8;i++)mp2[alladr+i]=typ+"."+nams[i];
                alladr+=8;
            }
            }
            }
        }
        if(opt==3){
            string nam;
            cin>>nam;
            printf("%lld\n",mp[nam]);
        }
        if(opt==4){
            long long k;
            scanf("%lld",&k);
            if(k>alladr){
                printf("ERR\n");
            }else{
                cout<<mp2[k]<<"\n";
            }
        }
    }
    return 0;

}
