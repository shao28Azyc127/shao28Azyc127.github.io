#include<bits/stdc++.h>
#define rps(i, b, e) for(int i=(b);i<=(e);i++)
#define prs(i, e, b) for(int i=(e);i>=(b);i--)
#define rpg(i, g, x) for(int i=g.head[x];i;i=g.e[i].nxt)
#define opf(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
using namespace std;
namespace cszhpdx {
typedef long long LL;
struct var {
    string type, name;
};
struct typ {
    string name;
    LL size, duiqi;
    vector<var>mem;
};
map<string, typ>mp;
vector<var>wai;
//waiceng de bian liang
inline void dui(LL &x, LL duiqi) {
    x=((x+duiqi-1)/duiqi)*duiqi;
}
void op1() {
    typ x;
    int k;
    cin>>x.name>>k;
    var tmp;
    x.size=x.duiqi=0;
    while(k--) {
        cin>>tmp.type>>tmp.name;
        x.mem.push_back(tmp);
        x.size+=mp[tmp.type].size;
        dui(x.size, mp[tmp.type].duiqi);
        x.duiqi=max(x.duiqi, mp[tmp.type].duiqi);
    }
    dui(x.size, x.duiqi);
    mp[x.name]=x;
    cout<<x.size<<' '<<x.duiqi<<endl;
}
void op2() {
    var tmp;
    cin>>tmp.type>>tmp.name;
    wai.push_back(tmp);
    LL sum=0;
    for(int i=1;i<wai.size();i++) {
        sum+=mp[wai[i-1].type].size;
        dui(sum, mp[wai[i].type].duiqi);
    }
    cout<<sum<<endl;
}
void op3() {
    string op;
    cin>>op;
    vector<string>cf;
    cf.push_back("");
    for(char c:op) {
        if(c!='.')cf[cf.size()-1].push_back(c);
        else cf.push_back("");
    }
    // for(string t:cf)cerr<<t<<endl;
    LL ans=0, lst=0;
    typ x;
    for(var t:wai) {
        if(t.name==cf[0]) {
            x=mp[t.type];break;
        }
        dui(ans, mp[t.type].duiqi);
        ans+=mp[t.type].size;
    }
    for(int i=1;i<cf.size();i++) {
        for(var t:x.mem) {
            if(t.name==cf[i]) {
                x=mp[t.type];break;
            }
            dui(ans, mp[t.type].duiqi);
            ans+=mp[t.type].size;
        }
    }
    dui(ans, x.duiqi);
    cout<<ans<<endl;
}
void op4() {
    LL adr;
    cin>>adr;
    typ x;
    string ans;

    // LL sum=0;
    // bool flg=false;
    // for(var t:wai) {
    //     LL sz=mp[t.type].size, lst=sum;
    //     sum+=sz, dui(sum, mp[t.type].duiqi);
    //     if(sum>adr) {
    //         dui(lst, mp[t.type].duiqi);
    //         flg=true;x=mp[t.type];
    //         sum=lst, ans=t.name;
    //         break;
    //     }
    // }
    // if(!flg)return cout<<"ERR"<<endl, void();
    // while(!x.mem.empty()) {
    //     LL py=0;
    //     flg=false;
    //     for(var t:x.mem) {
    //         LL lst=py;
    //         py+=mp[t.type].size;
    //         dui(py, mp[t.type].duiqi);
    //         if(py+sum>adr) {
    //             flg=true, x=mp[t.type];
    //             sum+=lst, ans+='.', ans+=t.name;
    //             break;
    //         }
    //     }
    //     if(!flg)return cout<<"ERR"<<endl, void();
    // }
    // if(adr>=sum+x.size)return cout<<"ERR"<<endl, void();
    // cout<<ans<<endl;

    if(wai.empty())return cout<<"ERR"<<endl, void();
    LL lst=0, ima=0;
    bool flg=false;
    for(int i=1;i<wai.size();i++) {
        ima=lst+mp[wai[i-1].type].size;
        dui(ima, mp[wai[i].type].duiqi);

        // cerr<<lst<<'|'<<ima<<endl;

        if(ima>adr) {
            x=mp[wai[i-1].type];
            ans=wai[i-1].name;
            flg=true;break;
        }
        lst=ima;
    }
    if(!flg && ima+mp[wai[wai.size()-1].type].size>adr) {
        flg=true, x=mp[wai[wai.size()-1].type];
        ans=wai[wai.size()-1].name;
    }
    else ima=lst;

    // cerr<<ans<<endl;

//     if(!flg)return cout<<"ERR"<<endl, void();
//     while(!x.mem.empty()) {
//         // cout<<x.name<<'|'<<endl;
//         // for(var t:x.mem)cout<<t.type<<'|'<<t.name<<endl;
//         flg=false;
//         LL py=0;lst=0;
//         for(int i=1;i<x.mem.size();i++) {
//             py=lst+mp[x.mem[i-1].type].size;

// // cerr<<lst<<'|'<<py<<endl;

//             dui(py, mp[x.mem[i].type].duiqi);
//             if(ima+py>adr) {
//                 flg=true, x=mp[x.mem[i-1].type];
//                 ans+='.', ans+=x.mem[i-1].name;
//                 break;
//             }
//             lst=py;
//         }
//         if(!flg && ima+py+mp[x.mem[x.mem.size()-1].type].size>adr) {
//             // cout<<x.name<<'|'<<endl;
//             // for(var t:x.mem)cout<<t.type<<'|'<<t.name<<endl;
//             ans+='.', ans+=x.mem[x.mem.size()-1].name;
//             flg=true, x=mp[x.mem[x.mem.size()-1].type];
//         }
//         else py=lst;
//         if(!flg)return cout<<"ERR"<<endl, void();

//         // cerr<<ans<<endl;

//         ima+=py;
//     }
//     if(adr>=ima+x.size)return cout<<"ERR"<<endl, void();
//     cout<<ans<<endl;

    if(!flg)return cout<<"ERR"<<endl, void();
    while(!x.mem.empty()) {
        flg=false, lst=0;
        LL py=0;
        for(int i=1;i<x.mem.size();i++) {
            py+=mp[x.mem[i-1].type].size;
            dui(py, mp[x.mem[i].type].duiqi);
            if(ima+py>adr) {
                flg=true;
                ans+='.', ans+=x.mem[i-1].name;
                x=mp[x.mem[i-1].type];
                break;
            }
            lst=py;
        }
        if(!flg && ima+py+mp[x.mem[x.mem.size()-1].type].size>adr) {
            flg=true;
            ans+='.', ans+=x.mem[x.mem.size()-1].name;
            x=mp[x.mem[x.mem.size()-1].type];
        }
        else py=lst;
        if(!flg)return cout<<"ERR"<<endl, void();
        ima+=py;
    }
    if(adr>=ima+x.size)return cout<<"ERR"<<endl, void();
    cout<<ans<<endl;
}
int main() {
    opf("struct");
    ios::sync_with_stdio(false);


    typ ini;
    ini.name="byte";
    ini.size=ini.duiqi=1;
    mp[ini.name]=ini;
    ini.name="short";
    ini.size=ini.duiqi=2;
    mp[ini.name]=ini;
    ini.name="int";
    ini.size=ini.duiqi=4;
    mp[ini.name]=ini;
    ini.name="long";
    ini.size=ini.duiqi=8;
    mp[ini.name]=ini;


    int q;cin>>q;
    while(q--) {
        int op;cin>>op;
        if(op==1)op1();
        if(op==2)op2();
        if(op==3)op3();
        if(op==4)op4();
    }
    return 0;
}
}
int main() {
    return cszhpdx::main();
}