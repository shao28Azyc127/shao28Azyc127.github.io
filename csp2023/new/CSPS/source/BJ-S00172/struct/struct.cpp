#include <bits/stdc++.h>
using namespace std;
int n,inde = 0,now = 0;
struct neicun{
    string ty;
    string name;
    int use;
}nei[100];
struct sct{
    string name;
    string typ[100];
    string val[100];
    int need = 0;
}lst[100];
int main(){
    freopen("struct1.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        int k;
        cin >> k;
        if(k == 1){
            string nam;
            int num;
            cin >> nam >> num;
            lst[inde].name = nam;
            for(int j = 0;j < num;j++){
                string ty,called;
                cin >> ty >> called;
                lst[inde].typ[j] = ty;
                lst[inde].val[j] = called;
                if(lst[inde].typ[j] == "byte") lst[inde].need = max(lst[inde].need,1);
                if(lst[inde].typ[j] == "short") lst[inde].need = max(lst[inde].need,2);
                if(lst[inde].typ[j] == "int") lst[inde].need = max(lst[inde].need,4);
                if(lst[inde].typ[j] == "long") lst[inde].need = max(lst[inde].need,8);
                for(int i = 0;i < inde;i++){
                    if(lst[i].name == lst[inde].typ[j]) lst[inde].need = max(lst[inde].need,lst[i].need);
                }
                cout << 2 * lst[inde].need << ' ' << lst[inde].need << endl;
            inde++;
            }
        }
        if(k == 2){
            int t,n;
            cin >> t >> n;
            nei[now].name = t;
            nei[now].ty = n;
            if(nei[now].ty == "byte") nei[now].use = 1;
            if(nei[now].ty == "short") nei[now].use = 2;
            if(nei[now].ty == "int")nei[now].use = 4;
            if(nei[now].ty == "long") nei[now].use = 8;
            for(int i = 0;i < inde;i++){
                if(lst[i].name == nei[now].ty) nei[now].use = lst[i].need;
            }
        }
    }
    return 0;
}
