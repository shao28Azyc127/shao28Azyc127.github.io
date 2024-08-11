#include<bits/stdc++.h>

using namespace std;

struct name_type{
    string name;
    string type;
};

long long T;
string ts[105],ns[105],os[105];
long long b[105];
map<string,long long> rule1;
map<string,long long> len;
map<pair<string,string>,long long> place;
map<long long,pair<string,string>> place2;
map<pair<string,string>,long long> place3;
map<string,string> check;
map<string,string> check2;
long long ii;

long long pf(string s){
    string ss = "";
    vector<string> s2 = {};
    long long iii = 0;
    long long pb;
    for(iii = 0;iii<s.length();iii++){
        ss = "";
        for(long long i = iii;i<s.length();i++){
            if(s[i] == '.'){
                iii = i;
                break;
            }
            ss+=s[i];
        }
        s2.push_back(ss);
    }
    pb = place3[make_pair(check[s2[0]],s2[0])];
    for(long long i = 0;i<s2.size()-1;i++){

    }
}

int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    rule1["byte"] = 1;
    rule1["short"] = 2;
    rule1["int"] = 4;
    rule1["long"] = 8;
    cin >> T;
    ii = 1;
    while(T--){
        long long op;
        cin >> op;
        if(op == 1){
            string s;
            long long k;
            cin >> s >> k;
            long long a = 0;
            long long o[k+5];
            o[1] = 0;
            for(long long i = 1;i<=k;i++){
                cin >> ts[i] >> ns[i];
                if(i != 1){o[i] = o[i-1]+rule1[ts[i-1]];}
                a = max(a,rule1[ts[i]]);
                if(ts[i]!="byte"&&ts[i]!="short"&&ts[i]!="int"&&ts[i]!="long"){
                    check[ns[i]] = ts[i];
                    check2[ts[i]] = ns[i];
                }
            }
            place[make_pair(s,ns[1])] = 0;
            place2[0] = make_pair(s,ns[1]);
            for(long long i = 2;i<=k;i++){
                while(o[i]%rule1[ts[i]]!=0&&o[i]>=o[i-1]+rule1[ts[i-1]]){
                    o[i]++;
                }
                place[make_pair(s,ns[i])] = o[i];
                place2[o[i]] = make_pair(s,ns[i]);
            }
            long long ss = o[k] + rule1[ts[k]];
            while(ss%a!=0&&ss>=o[k]+rule1[ts[k]]){
                ss++;
            }
            rule1[s] = a;
            len[s] = ss;
            cout << ss << " " << a << endl;
        }
        else if(op == 2){
            string t,n;
            cin >> t >> n;
            check[n] = t;
            check2[t] = n;
            if(ii == 1){
                b[ii] = 0;
                place3[make_pair(t,n)] = b[ii];
                ii++;
            }
            else{
                b[ii] = b[ii-1] + len[t];
                while(b[ii]%rule1[t]!=0&&b[ii]>=b[ii-1]+len[t]){
                    b[ii]++;
                }
                place3[make_pair(t,n)] = b[ii];
                ii++;
            }
            cout << b[ii - 1] << endl;
        }
        else if(op == 3){
            string s;
            cin >> s;
        }
        else if(op == 4){
            long long addr;
            cin >> addr;
        }
    }
    return 0;
}
