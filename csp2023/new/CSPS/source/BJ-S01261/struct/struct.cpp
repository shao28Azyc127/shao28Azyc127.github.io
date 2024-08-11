//I'll only try to get the score for the special condition A...
#include <iostream>
#include <map>
#include <algorithm>
#define ll long long

using namespace std;

int n;

map<string, int> mp;        //length
map<string, int> mp2;       //dui qi biao zhun
map<string, ll> mp3;        //each element
map<ll, ll> mp4;            //each area
map<ll, string> mp5;        //each name of the beginning

char de[15];    //define name
char type[15];
char na[15];    //name
ll addr;

ll ans = 0;

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    mp["byte"] = 1;
    mp["short"] = 2;
    mp["int"] = 4;
    mp["long"] = 8;
    mp2["byte"] = 1;
    mp2["short"] = 2;
    mp2["int"] = 4;
    mp2["long"] = 8;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        int op;
        scanf("%d",&op);
        if(op == 1){    //Okay, ignore it
            int k;
            cin >> de;
            scanf("%d",&k);
            for(int j = 1;j <= k;j++){
                cin >> type >> na;
                //Okay, I'll give up......
            }
        }
        else if(op == 2){
            cin >> type >> na;
            int standard = mp2.find(type)->second;
            int len = mp.find(type)->second;
            ll duiqi = standard;
            if(ans%standard){
                while(duiqi < ans) duiqi += standard;
            }
            else{
                duiqi = ans;
            }
            mp3[na] = duiqi;
            ans = duiqi+len;
            mp4[duiqi] = ans-1;
            mp5[duiqi] = na;
            printf("%d\n",duiqi);
        }
        else if(op == 3){
            cin >> na;
            printf("%lld\n",mp3.find(na)->second);
        }
        else if(op == 4){
            scanf("%lld",&addr);
            map <ll,ll> ::iterator it;
            it = mp4.upper_bound(addr);
            it--;
            if(it->first <= addr && it->second >= addr){
                cout << mp5.find(it->first)->second << endl;
            }
            else{
                printf("ERR\n");
            }
        }
    }
    return 0;
}
