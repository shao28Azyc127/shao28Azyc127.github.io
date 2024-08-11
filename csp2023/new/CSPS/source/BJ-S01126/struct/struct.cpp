#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n,cnt = 4,dq[110],op,k,pos,p;
map <string,int> id,nid[110];
map <string,long long> o[110];
vector <int> ps[110];
vector <long long> g[110];
vector <string> gg[110];
char s[15],t[15],u[105][15],c;
long long siz[110],ans,addr;
string nm;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    id["byte"] = 1;
    id["short"] = 2;
    id["int"] = 3;
    id["long"] = 4;
    siz[1] = dq[1] = 1;
    siz[2] = dq[2] = 2;
    siz[3] = dq[3] = 4;
    siz[4] = dq[4] = 8;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&op);
        if(op == 1){
            scanf(" %s %d",s,&k);
            id[s] = ++cnt;
            for(int i = 0;i < k;i++){
                scanf(" %s %s",s,u[i]);
                dq[cnt] = max(dq[cnt],dq[id[s]]);
                ps[cnt].push_back(id[s]);
                gg[cnt].push_back(u[i]);
                nid[cnt][u[i]] = id[s];
            }
            for(int i = 0;i < k;i++){
                g[cnt].push_back(o[cnt][u[i]] = (siz[cnt] = (siz[cnt] / dq[ps[cnt][i]] + (bool)(siz[cnt] % dq[ps[cnt][i]])) * dq[ps[cnt][i]]));
                siz[cnt] += siz[ps[cnt][i]];
            }
            printf("%lld %d\n",siz[cnt] = (siz[cnt] / dq[cnt] + (bool)(siz[cnt] % dq[cnt])) * dq[cnt],dq[cnt]);
        }
        else if(op == 2){
            scanf(" %s %s",s,t);
            ps[0].push_back(id[s]);
            gg[0].push_back(t);
            nid[0][t] = id[s];
            printf("%lld\n",o[0][t] = (siz[0] = (siz[0] / dq[id[s]] + (bool)(siz[0] % dq[id[s]])) * dq[id[s]]));
            g[0].push_back(o[0][t]);
            siz[0] += siz[id[s]];
        }
        else if(op == 3){
            pos = ans = 0;
            c = getchar();
            while(c != '\n'){
                nm.clear();
                c = getchar();
                while(c != '.' && c != '\n'){
                    nm.push_back(c);
                    c = getchar();
                }
                ans += o[pos][nm];
                pos = nid[pos][nm];
            }
            printf("%lld\n",ans);
        }
        else{
            scanf("%lld",&addr);
            pos = 0;
            nm.clear();
            while(pos < 1 || pos > 4){
                if(siz[pos] <= addr){
                    break;
                }
                p = 0;
                while(p < g[pos].size() && g[pos][p] <= addr){
                    p++;
                }
                addr -= g[pos][--p];
                if(pos){
                    nm += ".";
                }
                nm += gg[pos][p];
                pos = ps[pos][p];
            }
            if(pos < 1 || pos > 4 || siz[pos] <= addr){
                printf("ERR\n");
            }
            else{
                printf("%s\n",nm.data());
            }
        }
    }
    return 0;
}
