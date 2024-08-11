#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

string p[105], q1[105];
int q[105];
int q2[105];
int n, n1 = 0,n2 = 0;
long long now = 0;
struct Node{
    string name, cynames[105], cylx[105];
    long long num, dx = 0, dq = 0;
}t[105];




int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >>n;
    int op, tnum = 1;
    while(n --){
        cin >> op;
        if (op == 1){
            cin >> t[tnum].name >> t[tnum].num;
            for(int i = 1;i <= t[tnum].num;i ++){
                cin >> t[tnum].cylx[i] >> t[tnum].cynames[i];
                if (t[tnum].cylx[i] == "short" && t[tnum].dq < 2) t[tnum].dq = 2;
                else if(t[tnum].cylx[i] == "byte" && t[tnum].dq < 1)t[tnum].dq = 1;
                else if(t[tnum].cylx[i] == "int" && t[tnum].dq < 4)t[tnum].dq = 4;
                else if(t[tnum].cylx[i] == "long" && t[tnum].dq < 8)t[tnum].dq = 8;
            }
            cout << t[tnum].dq * t[tnum].num  << ' ' << t[tnum].dq << endl;
            p[n1] = t[tnum].name;
            q[n1] = t[tnum].dx;
            n1++;
            tnum++;
        }else if(op == 2){
            string a1, a2;
            cin >>a1>>a2;
            int k1;
            if (a1 == "short") k1 = 2;
            else if (a1 == "int") k1 = 4;
            else if (a1 == "long") k1 = 8;
            else if (a1 == "byte") k1 = 1;
            else{
                for (int i = 0;i < n1;i ++){
                    if (a1 == p[i])k1= q[i];
                }
            }
            cout << now << endl;
            q1[n2] = a2;
            q2[n2] = now;
            q2[n2 + 1] = now + k1;
            n2++;
            now += k1;

        }else if(op == 3){
            string a3;
            cin >> a3;
            for (int i = 0;i < n2;i ++){
                if (q1[i] == a3){
                    cout << q2[i] <<endl;
                    break;
                }
            }
        }else{
            int a4;
            cin >>a4;
            bool flag = 1;
            for (int i = 0;i < n2 +1;i ++){
                if (q2[i] > a4){
                    cout << q1[i - 1] <<endl;
                    flag = 0;
                    break;
                }
            }
            if(flag ) cout << "ERR " << endl;
        }
    }
    return 0;
}
