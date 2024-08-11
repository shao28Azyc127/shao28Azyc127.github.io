#include<bits/stdc++.h>
using namespace std;
int n,nc,scnt=4,bcnt=0;
string tmp;
struct st{
    int k,kk;
    string nme,cma[107];
    int chld[107],l[107],r[107],jg;
}s[108];
struct bl{
    string nam;
    int id,pl,rpl;//pl cun qian di zhi exp0
}op[108];
int cz(){
    for(int i=1;i<=scnt;++i){
        if(tmp==s[i].nme) return i;
    }
    return 0;
}
int czbl(){
    for(int i=1;i<=bcnt;++i){
        if(tmp==op[i].nam) return i;
    }
    return 0;
}
int czz(int lx){
    for(int i=1;i<=s[lx].kk;++i){
        int flg=1,j=0;
        while(s[lx].cma[i][j]!='\0'){
            if(tmp[j]!=s[lx].cma[i][j]){
                flg=0;
            }
            ++j;
        }
        if(flg) return i;
    }
    return 0;
}
void csh(){
    s[1].k=1,s[1].nme="byte";
    s[1].cma[1]="byte";
    s[1].chld[1]=1;
    s[1].l[1]=0,s[1].r[1]=0;
    s[1].jg=1;
    s[2].k=2,s[2].nme="short";
    s[2].cma[1]="short";
    s[2].chld[1]=2;
    s[2].l[1]=0,s[2].r[1]=1;
    s[2].jg=2;
    s[3].k=4,s[3].nme="int";
    s[3].cma[1]="int";
    s[3].chld[1]=3;
    s[3].l[1]=0,s[3].r[1]=3;
    s[3].jg=4;
    s[4].k=8,s[4].nme="long";
    s[4].cma[1]="long";
    s[4].chld[1]=4;
    s[4].l[1]=0,s[4].r[1]=7;
    s[4].jg=8;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    csh();
    while(n--){
        int opt;
        scanf("%d",&opt);
        if(opt==1){
            ++scnt;
            cin>>s[scnt].nme>>s[scnt].kk;
            for(int i=1;i<=s[scnt].kk;++i){
                cin>>tmp>>s[scnt].cma[i];
                s[scnt].chld[i]=cz();
                s[scnt].jg=max(s[scnt].jg,s[s[scnt].chld[i]].k);
            }
            s[scnt].k=s[scnt].kk*s[scnt].jg;
            printf("%d %d\n",s[scnt].k,s[scnt].jg);
            for(int i=1;i<=s[scnt].kk;++i){
                s[scnt].l[i]=s[scnt].jg*(i-1);
                s[scnt].r[i]=s[scnt].l[i]+s[s[scnt].chld[i]].k-1;
            }
        }else if(opt==2){
            cin>>tmp;
            ++bcnt;
            op[bcnt].id=cz();
            op[bcnt].pl=nc;
            nc+=s[op[bcnt].id].k;
            cin>>op[bcnt].nam;
            printf("%d\n",op[bcnt].pl);
            op[bcnt].rpl=op[bcnt].pl+s[op[bcnt].id].k-1;
        }else if(opt==3){
            string tm;
            cin>>tm;
            int i=0,js=0,fst=0,an,nty,blid,bllx,sz=tm.size();
            tm[sz]='.';
            ++sz;
            while(i<sz){
                if(tm[i]!='.'){
                    tmp[js++]=tm[i];
                }else if(fst==0){
                    js=0;
                    blid=czbl();
                    an=op[blid].pl;
                    bllx=op[blid].id;
                    fst=1;
                    tmp="                    ";
                }else{
                    nty=czz(bllx);
                    an+=s[bllx].l[nty];
                    bllx=s[bllx].chld[nty];
                    js=0;
                    tmp="                    ";
                }
                ++i;
            }
            printf("%d\n",an);
        }else{
            int nd,fo=0;
            scanf("%d",&nd);
            string an;
            for(int i=1;i<bcnt;++i){
                if(nd<=op[i].rpl){
                    if(op[i].id<5) cout<<op[i].nam<<'\n',fo=1;
                }
            }
            if(fo==0) printf("ERR");
        }
    }
    return 0;
}
//pls give me some points 
//let me get 1=