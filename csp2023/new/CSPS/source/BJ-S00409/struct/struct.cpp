#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int n,op;
int gei=0; //global element index
struct srt{
    int offset;
};
struct mps{
    bool type=0; // 0 for base, 1 for custom
    int id,off,size,sort;
};
struct inst{
    int off;
    int eid;
};
int goff=0;
map<string,mps> nmp; // element root name map
map<int,map<string,mps>> imp; //
map<string,string> smap; // var to type map
map<string,int>aap;
srt info[114514];
string adm[114514];
int main(){
freopen("struct.in","r",stdin);
freopen("struct.out","w",stdout);
    // make infos for base strt
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    nmp["byte"]={0,++gei,0,1,1};
    nmp["short"]={0,++gei,0,2,2};
    nmp["int"]={0,++gei,0,4,4};
    nmp["long"]={0,++gei,0,8,8};
    info[++gei]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&op);
        if(op==1){
            int k;
            string s;
            scanf("%d",&k);
            cin >> s;
            int co=0;
            // find a.b.c
            // mp[mp[nmp[ro]["a"].id]["b"].id]
            // string ro="root";
            //nmp[s]={1,++gei,roff};
            int ns=gei;
            int fsort=1;
            while(k--){
                //int ni;
                string ti,ni;
                cin >> ti >> ni;
                //scanf("%d",ni);
                int coff=0;
                // short int bype l
                if(ti=="short"){
                    coff=2;
                }if(ti=="int"){
                    coff=4;
                }if(ti=="byte"){
                    coff=1;
                }if(ti=="long"){
                    coff=8;
                }else coff=nmp[ti].size;
                //info[++gei]=(srt){};
                imp[ns][ni]=(mps){0,nmp[ti].id,co};
                fsort=max(fsort,coff);
                co+=coff;
            }
            nmp[s].sort=fsort;
            nmp[s].size=co;
        }
        if (op==2){
            string ti,ni;
            int st=1;;
            cin >> ti >> ni;
            if (goff%nmp[ti].sort==0)st=goff;
            else st=(goff/nmp[ti].sort+1)*nmp[ti].sort;
            aap[ni]=st;
            for(int i=st;i<st+nmp[ti].size;++i){
                adm[i]=ni;
            }
            goff+=nmp[ti].size;
        }
        if(op==3){
            string s;
            cin >> s;
            cout << aap[s]<<"\n";
        }
        if(op==4){
            int add;
            cin >> add;
            if(adm[add].size()<=0)cout <<"ERR\n";
            else cout << adm[add]<<"\n";
        }
    }
return 0;
}