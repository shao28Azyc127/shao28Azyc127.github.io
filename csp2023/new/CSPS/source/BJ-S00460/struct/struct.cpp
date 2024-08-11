#include<bits/stdc++.h>
using namespace std;
#define int long long
const int BP = 998244853;
const int BPBP = 3817139732701;//11451419198103 / 3
int n;
int Rst[105], Rsum[105], cnt;
string Rna[105];//, cnt;
int ceilM(int s, int k){
    //cout<<"CeilM"<<' '<<s<<' '<<k<<' '<<((s - 1) / k + 1) * k<<endl;
    if(s == 0)
        return 0;
    return ((s - 1) / k + 1) * k;
}
struct str{
    int base, len;
    int hash;
    /*vector<int> f;
    vector<int> name;
    vector<int> sum;*/
    int k;
    int f[150], sum[150];
    string name[150]; 
}a[1005];
int cur = 4;
int H(string s){
    int base = 26, res = 0;//, p = 26;
    for(int i = 0;i < s.length();i++){
        res *= base;
        res += (s[i] - 'a');
        res %= BPBP;
    }
    return (res + 1145) % BPBP;
}
int Q(string s){
    for(int i = 1;i <= cur;i++)
        if(a[i].hash == H(s))
            return i;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin>>n;
    a[1].base = 1, a[1].len = 1, a[1].hash = H("byte");
    a[2].base = 2, a[2].len = 2, a[2].hash = H("short");//1 2 4 8dou xie cheng 1 le
    a[3].base = 4, a[3].len = 4, a[3].hash = H("int");
    a[4].base = 8, a[4].len = 8, a[4].hash = H("long");
    //cout<<a[1].hash<<' '<<a[2].hash<<' '<<a[3].hash<<' '<<a[4].hash<<endl;
    while(n--){
        int op;
        cin>>op;
        if(op == 1){
            string s;
            int k;
            cin>>s>>k;
            //cout<<s<<' '<<k<<endl;
            a[++cur].hash = H(s);
            a[cur].sum[0] = 0;
            //cout<<H(s)<<' '<<cur<<' '<<a[cur].hash<<endl;
            for(int i = 1;i <= k;i++){
                string st, na;
                cin>>st>>na;
                //cout<<H(st)<<' '<<Q(st)<<' '<<a[Q(st)].len<<endl;
                a[cur].base = max(a[cur].base, a[Q(st)].base);
                a[cur].f[++a[cur].k] = Q(st);
                a[cur].name[a[cur].k] = na;
                //cout<<a[cur].name<<endl;
                int sum = ceilM(a[cur].sum[a[cur].k - 1], a[Q(st)].base);
                a[cur].sum[a[cur].k] = sum + a[Q(st)].len;
                //cout<<a[cur].sum[a[cur].k - 1]<<endl;
            }
            a[cur].len = ceilM(a[cur].sum[a[cur].k], a[cur].base);
            cout<<a[cur].len<<' '<<a[cur].base<<endl;
        }
        if(op == 2){
            string st, na;
            cin>>st>>na;
            Rst[++cnt] = Q(st), Rna[cnt] = na, Rsum[cnt] = ceilM(Rsum[cnt - 1], a[Q(st)].base) + a[Q(st)].len;
            //cout<<a[Q(st)].len<<endl;
            cout<<Rsum[cnt - 1]<<endl;//Rst????
        }
        if(op == 3){
            string s;
            cin>>s;
            int sum = 0;
            int slen = 0;
            char c[20];
            int res = 0;
            for(int i = 0;i <= s.length();i++){
                /*if(i < s.length()){
                    cout<<i<<' '<<s[i]<<endl;
                }*/
                //cout<<i<<' '<<"res"<<' '<<res<<endl;
                if(i == s.length() || s[i] == '.'){
                    //cout<<"slen"<<' '<<slen<<endl;
                    if(i == slen){
                        for(int j = 1;j <= cnt;j++){
                            int flag = 1;
                            //cout<<Rna[j].length();
                            if(Rna[j].length() != slen)
                                flag = 0;
                            else{
                                for(int k = 0;k < slen;k++)
                                    if(Rna[j][k] != c[k])
                                        flag = 0;
                            }
                            //cout<<j<<' '<<flag<<endl;
                            if(!flag)
                                continue;
                            //cout<<"check"<<' '<<j<<endl;
                            res = Rst[j];//j
                            sum = Rsum[j] - a[Rst[j]].len;
                            break;
                        }
                    }
                    else{
                        //cout<<1<<endl;
                        for(int j = 1;j <= a[res].k;j++){
                            int flag = 1;
                            //cout<<slen<<' '<<"namelen"<<' '<<a[res].name[j].length()<<endl;
                            if(a[res].name[j].length() != slen)
                                flag = 0;
                            else{
                                for(int k = 0;k < slen;k++){
                                    //cout<<j<<' '<<k<<' '<<a[res].name[j][k]<<' '<<c[k]<<endl;
                                    if(a[res].name[j][k] != c[k])
                                        flag = 0;
                                }
                            }
                            //cout<<j<<' '<<flag<<endl;
                            if(!flag)
                                continue;
                            //cout<<"check"<<' '<<j<<endl;
                            sum += a[res].sum[j] - a[a[res].f[j]].len;
                            res = a[res].f[j];//.f[i]//cnt?
                            break;
                        }
                    }
                    slen = 0;
                }
                else{
                    //res *= 26, res += s[i] - 'a', res %= BPBP;//wu da cheng BMVM/BMBM
                    c[slen++] = s[i];
                }
            }
            cout<<sum<<endl;
        }
        if(op == 4){
            int addr;
            cin>>addr;
            int res = 0;
            int rr = 0;
            int flag = 1;
            for(int i = 1;i <= cnt;i++){
                if(addr > Rsum[i])
                    continue;
                rr = i;
                res = Rst[i];//i
                break;
            }
            if(!rr){
                cout<<"ERR"<<endl;
                continue;
            }
            if(addr <= Rsum[res] - a[Rst[res]].len){
                cout<<"ERR"<<endl;
                continue;
            }
            addr -= Rsum[res - 1];
            int adddr = addr;
            int resres = res;
            while(res > 4){
                int g = 0;
                for(int i = 1;i <= a[res].k;i++){
                    if(addr > a[res].sum[i])
                        continue;
                    g = 1;
                    if(addr <= a[res].sum[i] - a[a[res].f[i]].len){
                        cout<<"ERR"<<endl;
                        flag = 0;
                        break;
                    }
                    addr -= a[res].sum[i] - a[a[res].f[i]].len;
                    res = a[res].f[i];
                    break;
                }
                if(!g){
                    cout<<"ERR"<<endl;
                    flag = 0;
                }
                if(!flag)
                    break;
            }
            if(!flag)
                continue;
            res = resres;
            addr = adddr;
            //cout<<res<<endl;
            cout<<Rna[rr];
            while(res){
                int g = 0;
                for(int i = 1;i <= a[res].k;i++){
                    //cout<<addr<<' '<<a[res].sum[i]<<endl;
                    if(addr > a[res].sum[i])
                        continue;
                    cout<<"."<<a[res].name[i];
                    addr -= a[res].sum[i] - a[a[res].f[i]].len;
                    res = a[res].f[i];
                    g = 1;
                    break;
                }
                if(res <= 4 || g == 0)
                    break;
            }
            cout<<endl;
        }
    }
    return 0;
}


