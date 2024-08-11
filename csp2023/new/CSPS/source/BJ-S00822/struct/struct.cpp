#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 109;
struct Tree{
    int align, sz;
    Tree(int s = 0){
        align = sz = s;
        k = 0;
    }
    int k;
    int off[maxn]; int ct[maxn]; string cn[maxn];
}no[maxn]; int nop = 0;
map<string, int> m;
void addChild(int i, int nop, string x, string name){
    no[nop].cn[i] = name;
    int t = m[x];
    no[nop].ct[i] = t;
    if(no[t].align) no[nop].off[i] = no[nop].sz = (no[nop].sz + no[t].align - 1) / no[t].align * no[t].align;
    no[nop].align = max(no[nop].align, no[t].align);
    no[nop].sz += no[t].sz;
}
signed main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    no[m[""] = nop++] = Tree(0);
    no[m["byte"] = nop++] = Tree(1);
    no[m["short"] = nop++] = Tree(2);
    no[m["int"] = nop++] = Tree(4);
    no[m["long"] = nop++] = Tree(8);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int op;
        cin>>op;
        if(op == 1){
            string name;
            cin>>name>>no[nop].k;
            m[name] = nop;
            for(int i=0;i<no[nop].k;i++){
                string x, y;
                cin>>x>>y;
                addChild(i, nop, x, y);
            }
            no[nop].sz = ((no[nop].sz + no[nop].align - 1) / no[nop].align * no[nop].align);
            cout<<no[nop].sz<<" "<<no[nop].align<<endl;
            nop++;
        }else if(op == 2){
            string x, y;
            cin>>x>>y;
            //cout<<"dbg "<<m[""]<<endl;
            addChild(no[m[""]].k++, m[""], x, y);
            cout<<no[0].off[no[0].k-1]<<endl;
        }else if(op == 3){
            string query;
            cin>>query;
            int ql = query.length();
            int p = 0;
            int now = m[""];
            int addr = 0;
            while(p < ql){
                int len = 0;
                for(int i=p;i<ql;i++){
                    if(query[i] == '.') break;
                    len++;
                }
                string var = query.substr(p, len);
                p += len + 1;
                for(int i=0;i<no[now].k;i++){
                    if(no[now].cn[i] == var){
                        addr += no[now].off[i];
                        now = no[now].ct[i];
                        break;
                    }
                }
            }
            cout<<addr<<endl;
        }else if(op == 4){
            int addr;
            cin>>addr;
            int now = m[""];
            string path = "";
            while(true){
                if(addr >= no[now].sz){
                    path = "ERR.";
                    break;
                }
                int c = upper_bound(no[now].off, no[now].off + no[now].k, addr) - no[now].off - 1;
                //cout<<"dbg "<<c<<" "<<no[now].off[0]<<" "<<no[now].k<<" "<<no[now].ct[c]<<endl;
                if(c == -1 || no[now].ct[c] == 0) break;
                path += no[now].cn[c];
                path += ".";
                addr -= no[now].off[c];
                now = no[now].ct[c];
            }
            cout<<path.substr(0, path.length() - 1)<<endl;
        }
    }
    return 0;
}
