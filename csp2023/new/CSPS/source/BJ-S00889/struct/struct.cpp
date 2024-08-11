//1-10 ABC 
#include <bits/stdc++.h>
using namespace std;

int T;
int op;
string s;
int k;
string t,n;


int last=0;
int struct_last=0;
map <string,int> mp;
map <string,int> a;
int maxx=0;
string b[1000000];

struct node
{
    /* data */
    string name;
    int sum;
    map <string,int> mp;//name long
    int buqi;
    int memoy;
}st[110];

int tot;

void check(int x){
    if (last==0){
        return;
    }
    while (true){
        if ((last)%x==0){
            break;
        }
        else{
            last++;
        }
    }
}

void update(int x,int size,string who){
    for (int i=x;i<x+size;i++){
        b[i]=who;
    }
}

void solve(int x,string n){
    if (last==0 || last%st[x].memoy==0){
        AAA:;
        for (auto i:st[x].mp){
            check(i.second);
            string str=n+"."+i.first;
            a[str]=last;
            update(last,i.second,str);
            // cout << "struct!" << str << " from:" << last << endl;
            last+=i.second-1;
        }
    }
    else{
        while (true){
            if (last%st[x].memoy==0){
                break;
            }
            else{
                last++;
            }
        }
        goto AAA;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    mp.insert(make_pair("byte",1));
    mp.insert(make_pair("short",2));
    mp.insert(make_pair("int",4));
    mp.insert(make_pair("long",8));
    cin >> T;
    while (T--){
        cin >> op;
        if (op==1){
            maxx=0;
            tot++;
            struct_last=0;
            cin >> s >> k;
            st[tot].name=s;
            st[tot].sum=k;
            for (int i=1;i<=k;i++){
                cin >> t >> n;
                st[tot].mp.insert(make_pair(n,mp[t]));
                maxx=max(maxx,mp[t]);
                if (mp[t]==1){
                    struct_last++;
                }
                if (struct_last==0 || (struct_last)%mp[t]==0){
                    struct_last+=mp[t]-1;
                }
                else{
                    while (true){
                        if ((struct_last)%mp[t]==0){
                            break;
                        }
                        struct_last++;
                    }
                    struct_last+=mp[t]-1;
                }
                // cout << struct_last << endl;
            }
            st[tot].buqi=maxx;
            while (true){
                if ((struct_last+1)%maxx==0){
                    break;
                }
                struct_last++;
            }
            st[tot].memoy=struct_last+1;
            // cout << st[tot].memoy << " " << st[tot].buqi << endl;
        }
        else if (op==2){
            cin >> t >> n;//type xxxxxxx
            for (int i=1;i<=tot;i++){
                if (st[i].name==t){
                    // cout << "is struct" << endl;
                    solve(i,n);
                    goto abc;
                }
            }
            if (mp[t]==1){
                if (last==0){
                    a.insert(make_pair(n,last));
                    cout << 0 << endl;
                    last++;
                }
                else{
                    last++;
                    a.insert(make_pair(n,last));                
                    cout << a[n] << endl;
                    last++;
                }
                continue;
            }
            if (last==0 || (last)%mp[t]==0){
                a.insert(make_pair(n,last));
                update(last,mp[t],n);
                last+=mp[t]-1;
            }
            else{
                int x=mp[t];
                while (true){
                    if ((last)%x==0){
                        break;
                    }
                    last++;
                }
                a.insert(make_pair(n,last));
                update(last,mp[t],n);
                last+=mp[t]-1;
            }
            cout << a[n] << endl;
        }
        else if (op==3){
            string s;
            cin >> s;
            cout << a[s] << endl;
        }
        else{
            int k;
            cin >> k;
            if (b[k]==""){
                cout << "ERR" << endl;
            }
            else{
                cout << b[k] << endl; 
            }
        }
        abc:;
    }
    return 0;
}
// 10
// 1 a 4
// int aa
// short ab
// long ac
// byte ad
// 1 b 4
// a ba
// int bb
// short bc
// a bd
// 2 b x
// 2 a y
// 3 x.bd.ab
// 3 x.ba
// 3 y.ac
// 4 42
// 4 20
// 4 100

// 24 8
// 56 8
// 0
// 56
// 36
// 0
// 64
// x.bd.ac
// ERR
// ERR
