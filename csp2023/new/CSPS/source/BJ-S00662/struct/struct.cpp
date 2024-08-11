#include<fstream>

using namespace std;

ifstream cin ("struct.in");
ofstream cout ("struct.out");
int k,n,op,sum;
string s;

int add1(int k){
    string t,n;
    int ma = 0;
    for(int i = 1;i <= k;i ++){
        cin >> t >> n;
        if(t == "byte"){
            ma = max(ma,1);
        } else if(t == "short"){
            ma = max(ma,2);
        } else if(t == "int"){
            ma = max(ma,4);
        } else {
            ma = max(ma,8);
        }
    }
    return ma;
}

void add2(){
    cout << sum << endl;
}

int main(){
    cin >> n;
    while(n --){
        cin >> op;
        if(op == 1){
            cin >> s >> k;
            int an = add1(k);
            cout << k * an << " " << an << endl;
        } else if(op == 2){
            add2();
        } else if(op == 3){#include<fstream>

using namespace std;

ifstream cin ("struct.in");
ofstream cout ("struct.out");
int k,n,op,sum;
string s;

int add1(int k){
    string t,n;
    int ma = 0;
    for(int i = 1;i <= k;i ++){
        cin >> t >> n;
        if(t == "byte"){
            ma = max(ma,1);
        } else if(t == "short"){
            ma = max(ma,2);
        } else if(t == "int"){
            ma = max(ma,4);
        } else {
            ma = max(ma,8);
        }
    }
    return ma;
}

void add2(){
    cout << sum << endl;
}

int main(){
    cin >> n;
    while(n --){
        cin >> op;
        if(op == 1){
            cin >> s >> k;
            int an = add1(k);
            cout << k * an << " " << an << endl;
        } else if(op == 2){
            add2();
        } else if(op == 3){
            //add3();
        } else {
            cout << "ERR" << endl;
        }
    }
    return 0;
}