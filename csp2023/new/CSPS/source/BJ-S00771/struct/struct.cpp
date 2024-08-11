#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map <string,int> box;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    box["byte"] = 1;
    box["short"] = 2;
    box["int"] = 4;
    box["long"] = 8;
    int l;
    cin >> l;
    for (int i = 1;i <= l;i++){
        int op;
        cin >> op;
        if (op == 1){
            string s;
            int k;
            cin >> s >> k;
            int ans = 0;
            for (int i = 1;i <=k;i++){
                string t,n;
                cin >> t >> n;
                ans = max(ans,box[t]);
            }
            cout << ans * k << " " << ans << endl;
            box[s] = ans;
        }
    }
    return 0;
}

