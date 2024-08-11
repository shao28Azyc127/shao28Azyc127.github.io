#include <bits/stdc++.h>
using namespace std;
long long n,op,k,cnt,pos,tmp,addr;
string s,t,nn;
map<string,long long> mp,mp2,mp3,mp4,mp6;
map<string,string> mp5;
vector<string> v[105],v2;
void check(string x,int ad){
    if(mp2[mp5[x]] - 1 < ad){
        cout << "ERR\n";
        return;
    }else if(mp[mp5[x]] <= 4)  cout << s << '\n';
    else{
        int flag = 0;
        for(int i = 1;i < v[mp[mp5[x]]].size();i++)
            if(mp4[v[mp[mp5[x]]][i]] > ad){
                flag = i - 1;
                break;
            }
        if(!flag) flag = v[mp[mp5[x]]].size() - 1;
        s += '.';
        s += v[mp[mp5[x]]][flag];
        check(v[mp[mp5[x]]][flag],ad - mp4[v[mp[mp5[x]]][flag]]);
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    mp["byte"] = ++cnt,mp6["byte"] = mp3["byte"] = mp2["byte"] = 1;
    mp["short"] = ++cnt,mp6["short"] = mp3["short"] = mp2["short"] = 2;
    mp["int"] = ++cnt,mp6["int"] = mp3["int"] = mp2["int"] = 4;
    mp["long"] = ++cnt,mp6["long"] = mp3["long"] = mp2["long"] = 8;
    cin >> n;
    while(n--){
        cin >> op;
        if(op == 1){
            cin >> s >> k;
            mp[s] = ++cnt;
            mp2[s] = mp3[s] = 0;
            for(int i = 1;i <= k;i++){
                cin >> t >> nn;
                v[cnt].push_back(nn);
                if(!mp6[t]) mp4[nn] = 0;
                else mp4[nn] = (mp2[s] + mp6[t] - 1) / mp6[t] * mp6[t];
                mp2[s] = mp4[nn] + mp2[t] - 1;
                mp3[s] = max(mp3[s],mp3[t]);
                mp5[nn] = t;
                if(i == 1) mp6[s] = mp4[nn];
            }
            mp2[s]++;
            cout << mp2[s] << ' ' << mp3[s] << '\n';
        }else if(op == 2){
            cin >> t >> nn;
            v2.push_back(nn);
            mp5[nn] = t;
            if(!mp6[t]) mp4[nn] = 0;
            else mp4[nn] = (pos + mp6[t] - 1) / mp6[t] * mp6[t];
            cout << mp4[nn] << '\n';
            pos = mp4[nn] + mp2[t] - 1;
        }else if(op == 3){
            cin >> t;
            nn = "";
            tmp = 0;
            for(int i = 0;i < t.length();i++){
                if(t[i] == '.'){
                    tmp += mp4[nn];
                    nn = "";
                }else nn += t[i];
            }
            tmp += mp4[nn];
            cout << tmp << '\n';
        }else{
            cin >> addr;
            s = v2[v2.size() - 1];
            for(int i = 1;i < v2.size();i++)
                if(mp4[v2[i]] > addr){
                    s = v2[i - 1];
                    break;
                }
            check(s,addr - mp4[s]);
        }
    }
    return 0;
}
