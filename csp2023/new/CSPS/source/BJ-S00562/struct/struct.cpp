# include<iostream>
# include<algorithm>
# include<cmath>
# define endl "\n"
# define int long long
using namespace std;
int n, cnt=0, now=0;
int op[101];
string snam; int snum;
string stype[1001], sname[1001], type[1001], name[1001], ask[1001];
int a[150000001], start[101], addr[1001];
bool flag=false;
string n2n[101];
signed main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> op[i];
        if(op[i]==1) {
            flag=true;
            cin >> snam >> snum;
            for(int i=1; i<=snum; i++) {
                cin >> stype[i] >> sname[i];
            }
        } else if(op[i]==2) {
            cin >> type[i] >> name[i];
        } else if(op[i]==3) {
            cin >> ask[i];
        } else {
            cin >> addr[i];
        }
    }
    if(flag==false) {
        for(int _=1; _<=n; _++) {
            if(op[_]==2) {
                string t=type[_], nam=name[_];
                n2n[++cnt]=nam;
                int size;
                if(t=="byte") size=1;
                if(t=="short") size=2;
                if(t=="int") size=4;
                if(t=="long") size=8;
                int i;
                for(i=now; i%size!=0; i++);
                start[cnt]=i;
                for(int j=i; j<=i+size-1; j++) {
                    a[j]=cnt;
                }
                now=i+size;
            } else if(op[_]==4) {
                int add=addr[_];
                if(a[add])
                    cout << n2n[a[add]] << endl;
                else
                    cout << "ERR" << endl;
            } else {
                string s=ask[_];
                for(int i=1; i<=cnt; i++) {
                    if(n2n[i]==s) {
                        cout << start[i] << endl;
                        break;
                    }
                }
            }
        }
    } else {
        for(int _=1; _<=n; _++) {
            if(op[_]==2) {
                if(type[_]==snam) {
                    for(int j=1; j<=snum; j++) {
                        string t=stype[j], nam=snam;
                        nam+="."; nam+=sname[j];
                        n2n[++cnt]=nam;
                        int size;
                        if(t=="byte") size=1;
                        if(t=="short") size=2;
                        if(t=="int") size=4;
                        if(t=="long") size=8;
                        int i;
                        for(i=now; i%size!=0; i++);
                        start[cnt]=i;
                        for(int j=i; j<=i+size-1; j++) {
                            a[j]=cnt;
                        }
                        now=i+size;
                    }
                } else {
                    string t=type[_], nam=name[_];
                    n2n[++cnt]=nam;
                    int size;
                    if(t=="byte") size=1;
                    if(t=="short") size=2;
                    if(t=="int") size=4;
                    if(t=="long") size=8;
                    int i;
                    for(i=now; i%size!=0; i++);
                    start[cnt]=i;
                    for(int j=i; j<=i+size-1; j++) {
                        a[j]=cnt;
                    }
                    now=i+size;
                }
            } else if(op[_]==4) {
                int add=addr[_];
                if(a[add])
                    cout << n2n[a[add]] << endl;
                else
                    cout << "ERR" << endl;
            } else {
                string s=ask[_];
                for(int i=1; i<=cnt; i++) {
                    if(n2n[i]==s) {
                        cout << start[i] << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
