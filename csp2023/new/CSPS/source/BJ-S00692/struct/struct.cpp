#include<bits/stdc++.h>
using namespace std;
const int maxn = 115;
typedef long long ll;
#define fi first
#define sc second
#define mkp make_pair
map<string, int> typid;
map<string, int> nmid;
int tot = 0;
struct typp{
    vector<pair<pair<int, string>, ll>> pins;
    ll sz; ll pa;
    typp(){
        pins.clear();
    }
    typp(ll szsz, ll papa){
        sz = szsz; pa = papa;
    }
    void ins(int sa, string sb){
        pins.emplace_back(mkp(sa, sb), 0); return ;
    }
}tynm[maxn];
void getpos(int id){
    ll now = 0;
    int plen = tynm[id].pins.size();
    for(int i = 0;i < plen;i++){
        tynm[id].pins[i].sc = now;
        tynm[id].pa = max(tynm[id].pa, tynm[tynm[id].pins[i].fi.fi].pa);
        now = now + tynm[tynm[id].pins[i].fi.fi].sz;
        if(i + 1 == plen) break;
        ll pka = tynm[tynm[id].pins[i + 1].fi.fi].pa;
        now = pka * ((now + pka - 1) / pka);
    }
    now = tynm[id].pa * ((now + tynm[id].pa - 1) / tynm[id].pa);
    tynm[id].sz = now; return ;
}
int n; int k = 0;
pair<pair<int, string>, ll> pf[maxn];
int pol = 0;
ll curnow = 0;
void init(){
    tot = 4;
    tynm[1] = typp(1, 1); typid["byte"] = 1;
    tynm[2] = typp(2, 2); typid["short"] = 2;
    tynm[3] = typp(4, 4); typid["int"] = 3;
    tynm[4] = typp(8, 8); typid["long"] = 4;
    return ;
}
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; init(); // int pct = 0;
    while(n--){
        int op; cin >> op;
        // cerr << op << endl;
        // pct++;
        if(op == 1){
            tot++;
            string ss; cin >> ss; cin >> k;
            typid[ss] = tot;
            for(int i = 1;i <= k;i++){
                string sa, sb; cin >> sa >> sb;
                int tya = typid[sa];
                tynm[tot].ins(tya, sb);
            }
            getpos(tot);
            cout << tynm[tot].sz << " " << tynm[tot].pa << '\n';
        } else if(op == 2){
            string sa, sb; cin >> sa >> sb;
            int tya = typid[sa];
            ++pol; nmid[sb] = pol;
            ll pka = tynm[tya].pa;
            curnow = pka * ((curnow + pka - 1) / pka);
            cout << curnow << '\n';
            pf[pol] = mkp(mkp(tya, sb), curnow);
            curnow += tynm[tya].sz;
            // cerr << curnow << endl;
        } else if(op == 3){
            string ss; cin >> ss;
            ss.push_back('.');
            vector<string> px;
            int las = 0;
            for(int i = 0;i < ss.size();i++){
                if(ss[i] == '.'){
                    string pnow = "";
                    for(int j = las;j < i;j++){
                        pnow.push_back(ss[j]);
                    }
                    px.push_back(pnow); las = i + 1;
                }
            }
            int pxlen = px.size();
            int pid = nmid[px[0]];
            ll ans = pf[pid].sc; pid = pf[pid].fi.fi;
            /*
            if(pct == 82){
                cerr << ss << endl;
            }
            */
            for(int i = 1;i < pxlen;i++){
                string pn = px[i];
                // cerr << pn << endl;
                for(auto pfr : tynm[pid].pins){
                    if(pfr.fi.sc == pn){
                        ans += pfr.sc; pid = pfr.fi.fi; break;
                    }
                }
            }
            cout << ans << '\n';
        } else if(op == 4){
            ll posk; cin >> posk;
            if(posk >= curnow){
                cout << "ERR" << '\n'; continue;
            }
            int pid = 0;
            for(int i = 1;i <= pol;i++){
                if(pf[i].sc > posk){
                    pid = i - 1; break;
                }
            }
            if(pid == 0) pid = pol;
            // cerr << "? " << pid << endl;
            string ans;
            posk -= pf[pid].sc; ans = pf[pid].fi.sc;
            pid = pf[pid].fi.fi; 
            bool fl = 1;
            while(true){
                if(posk >= tynm[pid].sz){
                    cout << "ERR" << '\n'; fl = 0; break;
                }
                if(pid <= 4) break;
                int kid = 0; pair<pair<int, string>, ll> plas;
                for(auto pfr : tynm[pid].pins){
                    if(pfr.sc > posk){
                        break;
                    }
                    plas = pfr;
                }
                ans.push_back('.');
                ans += plas.fi.sc;
                posk -= plas.sc;
                pid = plas.fi.fi;
            }
            if(fl == 0) continue;
            cout << ans << '\n';
        }
    }
    cout.flush(); return 0;
}
