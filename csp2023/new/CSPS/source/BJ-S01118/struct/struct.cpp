#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string,int> mp;
int cnt;
string adr[(int)1e5];
void create(int num,string s){
    if(cnt%num) cnt+=(num-cnt%num);
    mp[s] = cnt;
    for(int i = 0;i < num;i++){
        adr[cnt+i] = s;
    }
    cout << cnt<<"\n";
    cnt+=num;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin >> n;
    while(n--){
        int op;
        cin >> op;
        if(op==2){
            string s,s1;
            cin >>s1>>s;
            if(s1[0] == 'b'){
                create(1,s);
            }
            if(s1[0] == 's'){
                create(2,s);
            }
            if(s1[0] == 'i'){
                create(4,s);
            }
            if(s1[0] == 'l'){
                create(8,s);
            }
        }
        else if(op==3){
            string s;cin >> s;cout << mp[s]<<"\n";
        }
        else if(op==4){
            long long abc;cin >> abc;
            if(adr[abc]!="")cout << adr[abc]<<"\n";
            else cout << "ERR\n";
        }
    }
    return 0;
}
