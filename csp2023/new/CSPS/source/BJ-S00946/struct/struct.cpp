#include<bits/stdc++.h>
using namespace std;
#define int long long
map<string,int>struct_name;
int tot;
struct task{
    map<string,int>mp;
    string name[110];
    int cnt,maxd,siz,from[110],opt[110],pos[110];
}t[110];
bool Basic(int x){return x<=4;}
int sum,typ[110],lcy[110];
string name[110];
map<string,int>task_name;

signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int q;cin>>q;
    struct_name["byte"]=1;
    struct_name["short"]=2;
    struct_name["int"]=3;
    struct_name["long"]=4;tot=4;
    for(int i=1;i<=4;i++)t[i].maxd=t[i].siz=(1<<(i-1)),t[i].cnt=1;
    while(q--){
        int opt;cin>>opt;
        if(opt==1){
            string str;tot++;
            cin>>str>>t[tot].cnt;
            string str1,str2;
            for(int i=1;i<=t[tot].cnt;i++){
                cin>>str1>>str2;t[tot].mp[str2]=i;
                t[tot].from[i]=struct_name[str1];
                t[tot].name[i]=str2;
                t[tot].maxd=max(t[tot].maxd,t[t[tot].from[i]].maxd);
            }
            int now=0;
            for(int i=1;i<=t[tot].cnt;i++){
                now=((now+t[t[tot].from[i]].maxd-1)/t[t[tot].from[i]].maxd)*t[t[tot].from[i]].maxd;
                t[tot].pos[i]=now;now+=t[t[tot].from[i]].siz;
            }
            t[tot].siz=(now+t[tot].maxd-1)/t[tot].maxd*t[tot].maxd;
            cout<<t[tot].siz<<" "<<t[tot].maxd<<endl;
            struct_name[str]=tot;
        }
        if(opt==2){
            string str1,str2;cin>>str1>>str2;sum++;
            typ[sum]=struct_name[str1];name[sum]=str2;
            lcy[sum]=(t[typ[sum-1]].siz+lcy[sum-1]+t[typ[sum]].maxd-1)/t[typ[sum]].maxd*t[typ[sum]].maxd;
            cout<<lcy[sum]<<endl;
            task_name[str2]=sum;
        }
        if(opt==3){
            string str;cin>>str;
            int len=str.length(),now=0,pos=0,from;
            string tmp="";
            for(int i=0;i<=len;i++){
                if(i==len||str[i]=='.'){
                    int k;
                    if(now==0){
                        k=task_name[tmp];
                        pos=lcy[k];from=typ[k];now=i;
                    }
                    else{
                        k=t[from].mp[tmp];
                        pos+=t[from].pos[k];from=t[from].from[k];
                    }
                    tmp.clear();
                }
                else tmp+=str[i];
            }
            cout<<pos<<endl;
        }
        if(opt==4){
            int x;cin>>x;
            string ans="";
            int now=0;
            for(int i=1;i<=sum;i++)
                if((i==sum&&x<lcy[i]+t[typ[i]].siz)||lcy[i+1]>x){
                    ans+=name[i];
                    now=typ[i];x-=lcy[i];
                    break;
                }
            if(!now){
                puts("ERR");
                continue;
            }
            while(!Basic(now)){
                // cout<<now<<" "<<x<<" "<<ans<<endl;
                for(int i=1;i<=t[now].cnt;i++)
                    if(i==t[now].cnt||t[now].pos[i+1]>x){
                        ans+='.';ans+=t[now].name[i];
                        x-=t[now].pos[i];now=t[now].from[i];
                        break;
                    }
            }
            if(t[now].siz<=x)puts("ERR");
            else cout<<ans<<endl;
        }
    }
    return 0;
}