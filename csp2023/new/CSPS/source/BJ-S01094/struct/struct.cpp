#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL NR = 1e2;
struct Node{
    LL dq, num;
    LL sz[NR + 10];//chengyuan de daxiao
    LL d[NR + 10];//chengyuan de duiqi
    LL o[NR + 10];//chengyuan de pian yi liang
    LL l[NR + 10];//chengyuan de leixing
    map<string, LL> mp;
}a[NR + 10];
/*
1 byte
2 short
3 LL
4 long
*/
LL l[NR + 10];
LL sz[NR + 10];
LL dq[NR + 10];
LL st[NR + 10];
map<string, LL> mp;
map<string, LL> ys;//yuan su

int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    LL T;
    scanf("%lld", &T);
    LL id = 4;
    LL cnt = 0;
    while(T--){
        LL op;
        scanf("%lld", &op);
        if(op == 1){
            string s;
            LL k;
            cin>>s;
            scanf("%lld", &k);
            mp[s] = ++id;
            a[id].num = k;
            string t, nam;
            for(LL i = 1;i <= k;i++){
                cin>>t>>nam;
                if(nam[0] == 'b'){
                    a[id].sz[i] = 1;
                    a[id].d[i] = 1;
                    a[id].l[i] = 1;
                }
                if(nam[0] == 's'){
                    a[id].sz[i] = 2;
                    a[id].d[i] = 2;
                    a[id].l[i] = 2;
                }
                if(nam[0] == 'i'){
                    a[id].sz[i] = 4;
                    a[id].d[i] = 4;
                    a[id].l[i] = 3;
                }
                if(nam[0] == 'l'){
                    a[id].sz[i] = 8;
                    a[id].d[i] = 8;
                    a[id].l[i] = 4;
                }
                a[id].mp[nam] = i;
                a[id].dq = max(a[id].dq, a[id].d[i]);
                if(i == 1){
                    a[id].o[i] = 0;
                }
                else{
                    a[id].o[i] = (LL)ceil(1.0 * (a[id].o[i - 1] + a[id].sz[i - 1]) / a[id].d[i]) * a[id].d[i];
                }
            }
        }
        if(op == 2){
            string t, nam;
            cin>>t>>nam;
            cnt++;
            if(nam[0] == 'b'){
                l[cnt] = 1;
                sz[cnt] = 1;
                dq[cnt] = 1;
                ys[nam] = cnt;
                continue;
            }
            else if(nam[0] == 's'){
                l[cnt] = 2;
                sz[cnt] = 2;
                dq[cnt] = 2;
                ys[nam] = cnt;
                continue;
            }
            else if(nam[0] == 'i'){
                l[cnt] = 3;
                sz[cnt] = 4;
                dq[cnt] = 4;
                ys[nam] = cnt;
                continue;
            }
            else if(nam[0] == 'l'){
                l[cnt] = 4;
                sz[cnt] = 8;
                dq[cnt] = 8;
                ys[nam] = cnt;
                continue;
            }
            else{
                LL tmp = mp[t];
                l[cnt] = tmp;
                sz[cnt] = a[tmp].num * a[tmp].dq;
                dq[cnt] = a[tmp].dq;
                ys[nam] = cnt;
            }
            if(cnt == 1){
                st[cnt] = 0;
            }
            else{
                st[cnt] = (LL)ceil(1.0 * (st[cnt - 1] + sz[cnt - 1]) / dq[cnt]) * dq[cnt];
            }
        }
        if(op == 3){
            string tmp;
            cin>>tmp;
            string s1 = "", s2 = "";
            bool flag = false;
            for(LL i = 0;i < tmp.length();i++){
                if(tmp[i] == '.'){
                    flag = true;
                    continue;
                }
                if(!flag){
                    s1 += tmp[i];
                }
                else s2 += tmp[i];
            }
            if(!flag){
                printf("%lld %lld\n", st[ys[s1]], st[ys[s1]] + sz[ys[s1]] - 1);
            }
            else{
                printf("%lld %lld\n", a[l[ys[s1]]].o[a[l[ys[s1]]].mp[s2]], a[l[ys[s1]]].o[a[l[ys[s1]]].mp[s2]] + a[l[ys[s1]]].sz[a[l[ys[s1]]].mp[s2]]);
            }
        }
        if(op == 4){
            LL addr;
            scanf("%lld", &addr);
            LL sum = 0, tmp;
            for(LL i = 1;i <= cnt;i++){
                if(sum + dq[i] < addr){
                    sum += dq[i];
                }
                else{
                    tmp = i;
                    break;
                }
            }
            for(LL i = 1;i <= a[l[tmp]].num;i++){
                if(sum + a[l[tmp]].d[i] < addr) sum += dq[i];
                else{
                    if(sum + a[l[tmp]].sz[i] >= addr){
                        printf("%lld %lld\n", sum, sum + a[l[tmp]].sz[i]);
                    }
                    else printf("ERR\n");
                }
            }
        }
    }
	return 0;
}
/*
8
accabccb
*/
