#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int txx;
struct ABC{//cun shu ju yong
    string leixing,names;
    int st,ed;
}bianlang[1000005];
int now = 0;
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%lld",&txx);
    bianlang[0].ed = -1;
    while(txx--){
        int opt; scanf("%lld",&opt);
        if(opt == 2){//cun shu ju
            now++;
            cin >> bianlang[now].leixing >> bianlang[now].names;
            bianlang[now].st = bianlang[now-1].ed + 1;
            if(bianlang[now].leixing == "byte"){
                 bianlang[now].ed = bianlang[now].st;
            }else if(bianlang[now].leixing == "short"){
                 bianlang[now].st = (int)ceil((double)bianlang[now].st / 2.0) * 2;
                 bianlang[now].ed = bianlang[now].st + 1;
            }else if(bianlang[now].leixing == "int"){
                 bianlang[now].st = (int)ceil((double)bianlang[now].st / 4.0) * 4;
                 bianlang[now].ed = bianlang[now].st + 3;
            }else if(bianlang[now].leixing == "long"){
                 bianlang[now].st = (int)ceil((double)bianlang[now].st / 8.0) * 8;
                 bianlang[now].ed = bianlang[now].st + 7;
            }
        }
        if(opt == 3){
            string s; cin >> s;
            for(int i = 1; i <= now; i++){
                if(bianlang[i].names == s){
                    printf("%lld\n",bianlang[i].st);
                    break;
                }
            }
        }
        if(opt == 4){
            int addr; scanf("%lld",&addr);
            bool hav = 0;
            for(int i = 1; i <= now; i++){
                if(bianlang[i].st <= addr && addr <= bianlang[i].ed){
                    cout << bianlang[i].names << endl;
                    hav = 1; break;
                }
            }
            if(!hav) printf("ERR\n");
        }
    }
    return 0;
}
