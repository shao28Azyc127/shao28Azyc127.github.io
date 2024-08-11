#include<bits/stdc++.h>
using namespace std;
int t;
int strl,bl,yl;
string str[200];

struct node{
    vector<string> n;
    int l,k;
}a[200];

struct add{
    int s,e;
    string n,t;
}y[200];

int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>t;
    int op;
    string s,m,n;
    int adrr;
    while(t--){
        cin>>op;
        if(op == 1){
            strl++;
            cin>>s>>a[strl].k;
            str[strl] = s;
            for(int i = 1;i <= a[strl].k;i++){
                cin>>m>>n;
                if(m == "byte"){
                    a[strl].l = max(a[strl].l,1);
                }
                if(m == "short"){
                    a[strl].l = max(a[strl].l,2);
                }
                if(m == "int"){
                    a[strl].l = max(a[strl].l,4);
                }
                if(m == "long"){
                    a[strl].l = max(a[strl].l,8);
                }
                a[strl].n.push_back(n);
            }
            cout<<a[strl].k*a[strl].l<<' '<<a[strl].l<<'\n';
        }
        if(op == 2){
            yl++;
            cin>>m>>n;
            y[yl].s = bl;
            y[yl].t = n;
            if(m == "byte"){
                y[yl].n = "byte";
                y[yl].e = bl+1;
                bl += 1;
            }
            if(m == "short"){
                y[yl].n = "short";
                y[yl].e = bl+2;
                bl += 2;
            }
            if(m == "int"){
                y[yl].n = "int";
                y[yl].e = bl+4;
                bl += 4;
            }
            if(m == "long"){
                y[yl].n = "long";
                y[yl].e = bl+8;
                bl += 8;
            }
            for(int i = 1;i <= strl;i++){
                if(m == str[i]){
                    y[yl].n = str[i];
                    y[yl].e = bl+a[i].k*a[i].l;
                    bl += a[i].k*a[i].l;
                }
            }
            cout<<y[yl].s<<'\n';
        }
        if(op == 3){
            cin>>n;
            adrr = -1;
            for(int i = 0;i < n.length();i++){
                if(n[i] == '.'){
                    adrr = i;
                    break;
                }
            }
            if(adrr == -1){
                for(int i = 1;i <= yl;i++){
                    if(n == y[i].t){
                        cout<<y[i].s<<'\n';
                        break;
                    }
                }
            }else{
                string n1,n2;
                for(int i = 0;i < adrr;i++){
                    n1 += n[i];
                }
                for(int i = adrr+1;i < n.length();i++){
                    n2 += n[i];
                }
                for(int i = 1;i <= yl;i++){
                    if(n1 == y[i].t){
                        for(int j = 1;j <= strl;j++){
                            if(str[j] == y[i].n){
                                for(int k = 0;k < a[j].k;k++){
                                    if(a[j].n[k] == n2){
                                        cout<<y[i].s+a[j].l*k<<'\n';
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(op == 4){
            cin>>adrr;
            if(adrr >= bl){
                cout<<"ERR"<<'\n';
                continue;
            }
            for(int i = 1;i <= yl;i++){
                if(adrr >= y[i].s && adrr < y[i].e){
                    if(y[i].n == "byte" || y[i].n == "short" || y[i].n == "int" || y[i].n == "long"){
                        cout<<y[i].t<<'\n';
                    }else{
                        for(int j = 1;j <= strl;j++){
                            if(str[j] == y[i].n){
                                cout<<y[i].t<<'.';
                                for(int k = 0;k < a[j].k;k++){
                                    if(y[i].s+a[j].l*k <= adrr && y[i].s+a[j].l*(k+1) > adrr){
                                        cout<<a[j].n[k]<<'\n';
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
