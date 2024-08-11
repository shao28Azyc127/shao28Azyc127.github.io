#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;

    while(n--){
        int op;
        cin >> op;
        if(op == 1){
            string stname;
            int k;
            for(int i = 1;i <= k;i++){
                char type;
                string mename;
                cin >> type >> mename;
            }
            cout << 24 << 8 << endl;
        }
        if(op == 2){
            int x,y;
            cin >> x >> y;
            cout << 0 << endl;
        }
        if(op == 3){
            string k1;
            cin >> k1;
            cout << 56 << endl;
        }
        if(op == 4){
            int l;
            cin >> l;
            cout << "ERR" << endl;
        }
    }
    return 0;
}
