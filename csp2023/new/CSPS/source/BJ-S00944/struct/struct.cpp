#include <cstdio>
#include <map>
#include <iostream>
#include <string>
using namespace std;
struct cy{
    string lx;
    string nam;
};//一个成员
struct node{
    long long dqlen,zy,gs;//对齐要求 占用内存 成员个数
    string nam;//名称
    cy t[107];
};//类型
struct ys{
    string lx,nam;
    long long add;
};
map<string,node> mp;
map<string,ys> mm;
long long addr=0;
int cnt=0,tot=0;
node a[107];
ys b[107];
string ans="";
bool dfs(string la,long long now,long long dz){
    for(int i=0;i<mp[la].zy;i++){
        long long tmp;
        if(mp[mp[la].t[i].lx].gs>1){
            tmp=mp[mp[la].t[i].lx].zy;
        }else tmp=mp[la].dqlen;
        if(now+tmp>dz){
            ans+=".";
            ans+=mp[la].t[i].nam;
            if(mp[mp[la].t[i].lx].gs>1){
                return dfs(mp[la].t[i].lx,now,dz);
            }else{
                int dqyq=mp[la].dqlen;
                int yn=now;
                if(mp[la].t[i].lx=="short") now+=2;
                else if(mp[la].t[i].lx=="int") now+=4;
                else if(mp[la].t[i].lx=="byte") now++;
                else if(mp[la].t[i].lx=="long") now+=8;
                if(now<=dz && dz<yn+dqyq) return false;
                return true;
            }
        }else now+=tmp;
    }
//    printf("GAGA\n");
    return true;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    a[1].dqlen=1,a[1].zy=1,a[1].gs=1;
    a[1].nam="byte";
    a[1].t[1]=(cy){"byte","byte"};
    mp[a[1].nam]=a[1];
    a[2].dqlen=2,a[1].zy=2,a[1].gs=1;
    a[2].nam="short";
    a[2].t[1]=(cy){"short","short"};
    mp[a[2].nam]=a[2];
    a[3].dqlen=4,a[1].zy=4,a[1].gs=1;
    a[3].nam="int";
    a[3].t[1]=(cy){"int","int"};
    mp[a[3].nam]=a[3];
    a[4].dqlen=6,a[1].zy=6,a[1].gs=1;
    a[4].nam="long";
    a[4].t[1]=(cy){"long","long"};
    mp[a[4].nam]=a[4];
    tot=4;
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            tot++;
            int k;
            cin>>a[tot].nam;
            scanf("%d",&k);
            long long maxx=0,ttt=0;
            long long sum=0;
            for(int j=1;j<=k;j++){
                cin>>a[tot].t[j].lx>>a[tot].t[j].nam;
                maxx=max(maxx,mp[a[tot].t[j].lx].dqlen);
                if(mp[a[tot].t[j].lx].gs>1) sum+=mp[a[tot].t[j].lx].zy;
                else ttt++;
            }
            a[tot].dqlen=maxx;
            a[tot].zy=sum+ttt*maxx;
            a[tot].gs=k;
            mp[a[tot].nam]=a[tot];
            printf("%lld %lld\n",a[tot].zy,a[tot].dqlen);
        }else if(op==2){
            string t,n;
            cin>>t>>n;
            b[++cnt].nam=n;
            b[cnt].lx=t;
            b[cnt].add=addr;
            mm[n]=b[cnt];
            printf("%lld\n",addr);
            addr+=mp[t].zy;
        }else if(op==3){
            string s,t="";
            cin>>s;
            int ll=s.length(),idx=-1;
            for(int i=0;i<ll;i++){
                if(s[i]=='.'){
                    idx=i;
                    break;
                }else t+=s[i];
            }
            if(idx==-1){
                printf("%lld\n",mm[t].add);
                continue;
            }
            long long now=mm[t].add;
            string la=mm[t].lx;
//            cout<<t<<" "<<la<<endl;
            bool flag=true;
            while(flag){
                flag=false;
                t="";
                for(int i=idx+1;i<ll;i++){
                    if(s[i]=='.'){
                        idx=i;
                        flag=true;
                        break;
                    }else t+=s[i];
                }
//                cout<<t<<" "<<la<<endl;
                for(int i=1;i<=mp[la].gs;i++){
                    if(mp[la].t[i].nam==t){
                        la=mp[la].t[i].lx;
                        break;
                    }else now+=mp[la].dqlen;
                }
            }
            printf("%lld\n",now);
        }else if(op==4){
            long long dz;
            scanf("%lld",&dz);
            if(dz>=addr){
                printf("ERR\n");
                continue;
            }
            bool flag;
            for(int i=1;i<=cnt;i++){
                if(b[i].add<=dz && b[i+1].add>dz){
                    ans+=b[i].nam;
                    flag=dfs(b[i].lx,b[i].add,dz);
                    break;
                }
            }
            if(!flag) printf("ERR\n");
            else cout<<ans<<endl;
        }
    }
    return 0;
}
/*
回来吧，syh
我最骄傲的信仰
历历在目的侦察
守卫集二的自豪
依稀记得U盘
还有给力A班
把线筛都定罪
再写1h也不累!
*/