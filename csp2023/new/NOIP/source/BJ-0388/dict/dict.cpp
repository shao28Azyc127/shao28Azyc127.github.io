#include <bits/stdc++.h>
#define int long long

using namespace std;

string a[3001],a1[3001];
int tong[30];

bool cmp1(char a,char b){
    return a < b;
}

bool cmp2(char a,char b){
    return a > b;
}

signed main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    //cout << "Hello world!" << endl;
    int n,m;
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (j == i) continue;
            //a1[j] = a[j];
            /*
            for (int k = 0; k < m; k++){
                for (int ttt = 0; ttt <= k; ttt++){
                    if (a1[j][ttt] < a1[j][k]){
                        swap(a1[j][ttt],a1[j][k]);
                    }
                }
            }*/
            //memset(tong,0,sizeof(tong));
            for (int k = 0; k < 30; k++) tong[k] = 0;
            for (int tongs = 0; tongs < m; tongs++) tong[a[j][tongs]-'a']++;
            a1[j] = "";
            for (int tongs = 29; tongs >= 0; tongs--){
                if (tong[tongs] > 0){
                    for (int tongss = 1; tongss <= tong[tongs]; tongss++){
                        a1[j] += char(tongs+'a');
                    }
                }
            }
            //printf("%d\n",j);
            //sort(a1[j].begin(),a1[j].end(),cmp2);
            //printf("%d %s => %s\n",i,a[j].c_str(),a1[j].c_str());
        }
        a1[i] = "";
        /*
        for (int j = 0; j < m; j++){
            for (int k = 0; k <= j; k++){
                if (a1[i][k] > a1[i][j]){
                    swap(a1[i][j],a1[i][k]);
                }
            }
        }*/
        for (int k = 0; k < 30; k++) tong[k] = 0;
            for (int tongs = 0; tongs < m; tongs++) tong[a[i][tongs]-'a']++;
            a1[i] = "";
            for (int tongs = 0; tongs < 30; tongs++){
                if (tong[tongs] > 0){
                    for (int tongss = 1; tongss <= tong[tongs]; tongss++){
                        a1[i] += char(tongs+'a');
                    }
                }
            }
        //sort(a1[i].begin(),a1[i].end(),cmp1);
        //printf("%d %s => %s\n",i,a[i].c_str(),a1[i].c_str());
        //printf("%d\n",i);
        bool f = 1;
        for (int j = 1; j <= n; j++){
            if (j == i) continue;
            //printf("cp %s & %s\n",a1[j].c_str(),a1[i].c_str());
            if (a1[j] < a1[i]){
                f = 0;
                break;
            }
        }
        cout << f;
    }
    return 0;
}
