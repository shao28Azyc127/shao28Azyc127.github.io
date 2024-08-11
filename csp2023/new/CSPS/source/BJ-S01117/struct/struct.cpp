#include<bits/stdc++.h>
using namespace std;
const long long M = 10e8;
long long addr = 0;
int a[4] = {1, 2, 4, 8};
char m[M];

int f(string s){
    if(s == "byte"){
        return 1;
    }
    if(s == "short"){
        return 2;
    }
    if(s == "int"){
        return 4;
    }
    if(s == "long"){
        return 8;
    }
    return 0;
}

int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n, op, Max = -1, al = 0;
    string name, t, N;
    int k;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin>>op;
        if(op == 1){
            cin>>name>>k;
            for(int j = 0; j < k; j ++){
                cin >> t >> N;
                Max = max(Max, f(t));
                al += f(t);
            }
            if(al % Max != 0){
            	al += Max - (al % Max);
            }
            cout<<al<<" "<<Max<<endl;
        }
        else if(op == 2){
        	cin >> t ;
        }
    }
    return 0;
}