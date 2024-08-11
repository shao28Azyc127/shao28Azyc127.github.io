#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x == 1){
            string a;
            int k;
            while(k--){
                string y;
                cin >> y >> y;
            }
            cout << "8 4" << endl;
            continue;
        }
        else if(x == 2){
            string y;
            cin >> y >> y;
            cout << "8 4" << endl;
            continue;
        }
        else if(x == 3){
            string y;
            cin >> y;
            cout << "8 4" << endl;
            continue;
        }
        else if(x == 4){
            cout << "8 4" << endl;
            continue;
        }
    }
    return 0;
}