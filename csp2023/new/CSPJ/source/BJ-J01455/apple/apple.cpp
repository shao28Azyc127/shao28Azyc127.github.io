#inclue <bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
int n;
cin >>n;
for(int i = 0 ; i <= n; i++){
    a[i] = i;
}
int sum = 1;
int q = 0;
for(int i = 1; i <= n; i++){
        if(a[i] != 0){
            q++;
        }
    for(int j = i; j<=q,j+=3){
        a[j] = 0;
    }
    sum++;
    if(a[n] == 0){
        cout << sum;
        break;
    } else {
        continue;
    }

    if(q == 0){
        cout <<  sum;
        break;
    } else {
        continue;
    }
}
return 0;

}

