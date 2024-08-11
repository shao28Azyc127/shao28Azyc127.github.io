#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> mp;
string s[1005];
int now = 0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int q; cin >> q;
    for(int i = 1;i <= q;i++){
        int opt; cin >> opt;
        if(opt == 2){
            string type,name;
            cin >> type >> name;
            mp[name] = now;
            cout << now << endl;
            int len;
            if(type[0] == 'b') len = 1;
            else if(type[0] == 's') len = 2;
            else if(type[0] == 'i') len = 4;
            else len = 8;
            for(int j = now;j <= now + len - 1;j++) s[j] = name;
            now += len;
        }
        else if(opt == 3){
            string name; cin >> name;
            cout << mp[name] << endl;
        }
        else if(opt == 4){
            int x; cin >> x;
            if(x < now) cout << s[x] << endl;
            else cout << "ERR" << endl;
        }
    }
    return 0;
}