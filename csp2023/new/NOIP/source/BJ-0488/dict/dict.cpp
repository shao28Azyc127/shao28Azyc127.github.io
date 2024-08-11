#include <bits/stdc++.h>
using namespace std;

int n, m, tot;
char ch[30], ch1, s[3010], ss[3010];
string smax[3010], smin[3010], s1;

bool cmp(char a, char b){
    return a < b;
}

bool cmp2(char a, char b){
    return a > b;
}

int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    if(m == 1){
        for(int i = 1; i <= n; i ++){
            cin >> ch[i];
        }
        ch1 = ch[1];
        for(int i = 2; i <= n; i ++){
            if(ch[i] < ch1){
                ch1 = ch[i];
                tot = i;
            }
        }
        for(int i = 1; i <= n; i ++){
            if(i == tot){
                printf("1");
            }else{
                printf("0");
            }
        }
    }else{
        for(int i = 1; i <= n; i ++){
            cin >> s;
            for(int j = 0; j < m; j ++){
                ss[j] = s[j];
            }
            sort(s, s + m, cmp);
            sort(ss, ss + m, cmp2);
            smin[i] = s;
            smax[i] = ss;
        }
        s1 = smax[1];
        for(int i = 2; i <= n; i ++){
            if(smax[i] < s1){
                tot = i;
                s1 = smax[i];
            }
        }
        for(int i = 1; i <= n; i ++){
            if(i == tot){
                printf("1");
                continue;
            }
            if(smin[i] >= s1){
                printf("0");
                continue;
            }
            printf("1");
        }
 //       for(int i = 1; i <= n; i ++){
  //          cout << smin[i] << " " << smax[i] << endl;
 //       }
//        for(int i = 1; i <= n; i ++){
 //           for(int j = 1; j <= n; j ++){
 //               cout << smin[i] << " " << smax[j] << " ";
 //               if(smin[i] >= smax[j]){
 //                   printf("0");
 //               }else{
  //                  printf("1");
   //             }
  //          }
  //          cout << endl;
  //      }
    }
    return 0;
}
