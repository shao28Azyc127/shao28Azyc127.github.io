#include<bits/stdc++.h>
using namespace std;
//CSP-S 2023 RP ++!!!
int n, op, k, tot;
string s, t, name;
long long addr, cnt;

map <string, long long> mapp;
map <long long, string> mapp2;

struct HJY{
    int l, m;
    string id;
    string a[105];
    string type[105];
}hjy;

int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    scanf("%d", &n);
    while(n --){
        scanf("%d", &op);
        if(op == 1){
            cin >> s;
            scanf("%d", &k);
            hjy.l = 0, hjy.m = 0;
            while(k --){
                cin >> t >> name;
                hjy.id = s;
                hjy.a[tot] = name;
                hjy.type[tot ++] = t;
                if(t == "byte"){
                    hjy.l ++;
                    hjy.m = max(hjy.m, 1);
                }else if(t == "short"){
                    while(hjy.l % 2 != 0){
                        hjy.l ++;
                    }
                    hjy.l += 2;
                    hjy.m = max(hjy.m, 2);
                }else if(t == "int"){
                    while(hjy.l % 4 != 0){
                        hjy.l ++;
                    }
                    hjy.l += 4;
                    hjy.m = max(hjy.m, 4);
                }else if(t == "long"){
                    while(hjy.l % 8 != 0){
                        hjy.l ++;
                    }
                    hjy.l += 8;
                    hjy.m = max(hjy.m, 8);
                }
            }
            printf("%d %d\n", hjy.l, hjy.m);
        }
        if(op == 2){
            cin >> t >> s;
            if(t == "byte"){
                mapp[s] = addr;
                mapp2[addr] = s;
                addr ++;
                mapp2[addr] = s;
            }else if(t == "short"){
                while(addr % 2 != 0){
                    addr ++;
                }
                mapp[s] = addr;
                mapp2[addr] = s;
                mapp2[addr + 1] = s;
                addr += 2;
                mapp2[addr] = s;
            }else if(t == "int"){
                while(addr % 4 != 0){
                    addr ++;
                }
                mapp2[addr] = s;
                mapp[s] = addr;
                mapp2[addr + 1] = s;
                mapp2[addr + 2] = s;
                mapp2[addr + 3] = s;
                addr += 4;
                mapp2[addr] = s;
            }else if(t == "long"){
                while(addr % 8 != 0){
                    addr ++;
                }
                mapp2[addr] = s;
                mapp[s] = addr;
                mapp2[addr + 1] = s;
                mapp2[addr + 2] = s;
                mapp2[addr + 3] = s;
                mapp2[addr + 4] = s;
                mapp2[addr + 5] = s;
                mapp2[addr + 6] = s;
                mapp2[addr + 7] = s;
                addr += 8;
                mapp2[addr] = s;
            }else if(t == hjy.id){
                while(addr % hjy.l != 0){
                    addr ++;
                }
                mapp2[addr] = s;
                mapp[s] = addr;
                for(int i = 1; i < hjy.l; i ++){
                    mapp2[addr + i] = s;
                }
                addr += hjy.l;
                mapp2[addr] = s;
            }
            printf("%lld\n", mapp[s]);
        }else if(op == 3){
            cin >> s;
                printf("%lld\n", mapp[s]);
        }else if(op == 4){
            scanf("%lld", &cnt);
            if(mapp2[cnt] != ""){
                cout << mapp2[cnt] << endl;
            }else{
                printf("ERR\n");
            }

        }
    }
    return 0;
}
