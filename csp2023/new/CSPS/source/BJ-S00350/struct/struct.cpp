#include<bits/stdc++.h>
using namespace std;
struct mynode{
    string name;
    int eachsize, k;
    string nameme[110], typepe[110];
};
struct node{
    long long first, last, isnode;
    string name;
};
long long op, n, num, addr, P = 99991, numnode;
string type, name;
node save[10000];
mynode a[110];
int v[100000];
int hashh(string x){
    long long s = 0, wei = 1;
    for(int i=0;i<x.size();i++){
        s += ((x[i] - 'a') * wei) % P;
        wei*=26;
    }
    return s%P;
}
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin>>n;
    v[hashh("byte")] = 1;
    v[hashh("short")] = 2;
    v[hashh("int")] = 4;
    v[hashh("long")] = 8;
    save[0].last = -1;
    for(int i=1;i<=n;i++){
        scanf("%lld", &op);
        if(op==1){
            int k, eachsize = 0;
            cin>>name;
            scanf("%d", &k);
            numnode++;
            a[numnode].name = name, a[numnode].k = k;
            for(int j=1;j<=k;j++){
                cin>>a[numnode].typepe[j]>>a[numnode].nameme[j];
                eachsize = max(eachsize, v[hashh(a[numnode].typepe[j])]);
            }
            a[numnode].eachsize = eachsize;
            v[hashh(name)] = k * eachsize;

        }
        if(op==2){
            cin>>type>>name;
            bool flag = false;
            for(int i=1;i<=numnode;i++){
                if(a[i].name==type){
                    num++;
                    save[num].first = save[num-1].last + 1;
                    save[num].last = save[num].first + a[i].k * a[i].eachsize - 1;
                    save[num].name = name;
                    save[num].isnode = 11451412;
                    int fir = save[num].first;
                    for(int j=1;j<=a[i].k;j++){
                        num++;
                        save[num].first = (j-1) * a[i].eachsize + fir;
                        save[num].last = save[num].first + v[hashh(a[i].typepe[j])] - 1;
                        save[num].name = name +"." + a[i].nameme[j];
                    }
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            num++;
            save[num].first = save[num-1].last + 1;
            save[num].last = save[num].first + v[hashh(type)] - 1;
            save[num].name = name;

        }
        if(op==3){
            cin>>name;
            for(int i=1;i<=num;i++){
                if(save[i].name == name) printf("%lld\n", save[i].first);
            }
        }
        if(op==4){
            cin>>addr;
            string ans = "ERR";
            for(int i=1;i<=num;i++){
                if(save[i].first<=addr && save[i].last>=addr && save[i].isnode!=11451412){
                    ans = save[i].name;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

