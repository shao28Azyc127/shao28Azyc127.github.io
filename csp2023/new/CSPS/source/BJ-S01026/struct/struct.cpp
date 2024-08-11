#include<bits/stdc++.h>
using namespace std;
int read(){
    char ch = getchar();
    int pn = 1, k = 0;
    while(ch > '9' || ch < '0'){
        if(ch == '-') pn = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        k *= 10;
        k += ch - '0';
        ch = getchar();
    }
    return pn*k;
}
struct basi{
    string name;
    int len;
    int duiqi;
};
struct def{
    string name;
    int len;
    int itemNum;
    int duiqi;
    basi items[100];
}things[10];
int nodeNum;
struct dosth{
    string name;
    int start;
    int endat;
}joker[10000];
int jokenum;
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n = read();
    while(n--){
        int op = read();
        if(op == 1){
            cin >> things[nodeNum].name;
            int k = read();
            string alpha;
            int beta = 0;
            things[nodeNum].itemNum = k;
            for(int i = 0; i < k; i ++){
                cin >> alpha >> things[nodeNum].items[i].name;
                if(alpha == "byte"){
                    things[nodeNum].items[i].len = 1;
                    things[nodeNum].items[i].duiqi = 1;
                    things[nodeNum].duiqi = max(1, things[nodeNum].duiqi);
                    beta ++;
                }
                else if(alpha == "short"){
                    things[nodeNum].items[i].len = 2;
                    things[nodeNum].items[i].duiqi = 2;
                    things[nodeNum].duiqi = max(2, things[nodeNum].duiqi);
                    if(beta % 2 == 1){
                        beta += 3;
                    }
                    else{
                        beta += 2;
                    }
                }
                else if(alpha == "int"){
                    things[nodeNum].items[i].len = 4;
                    things[nodeNum].items[i].duiqi = 4;
                    things[nodeNum].duiqi = max(4, things[nodeNum].duiqi);
                    if(beta % 4 == 0){
                        beta += 4;
                    }
                    else{
                        beta = (beta / 4 + 2) * 4;
                    }
                }
                else if(alpha == "long"){
                    things[nodeNum].items[i].len = 8;
                    things[nodeNum].items[i].duiqi = 8;
                    things[nodeNum].duiqi = max(8, things[nodeNum].duiqi);
                    if(beta % 8 == 0){
                        beta += 8;
                    }
                    else{
                        beta = (beta / 8 + 2) * 8;
                    }
                }
            }
            things[nodeNum].len = beta;
            printf("%d %d\n", things[nodeNum].len, things[nodeNum].duiqi);
            nodeNum ++;
        }
        else if(op == 2){
            string alpha, beta;
            cin >> alpha >> beta;
            if(alpha == "byte"){
                joker[jokenum].name = beta;
                joker[jokenum].start = joker[jokenum-1].endat + 1;
                joker[jokenum].endat = joker[jokenum].start + 1;
                printf("%d\n", joker[jokenum].start);
            }
            else if(alpha == "short"){
                joker[jokenum].name = beta;
                if((joker[jokenum-1].endat+1) % 2 == 0){
                    joker[jokenum].start = joker[jokenum-1].endat+1;
                }
                else{
                    joker[jokenum].start = (joker[jokenum-1].endat+1+2) / 2 * 2;
                }
                joker[jokenum].endat = joker[jokenum].start+1;
                printf("%d\n", joker[jokenum].start);
            }
            else if(alpha == "int"){
                joker[jokenum].name = beta;
                if((joker[jokenum-1].endat+1) % 4 == 0){
                    joker[jokenum].start = joker[jokenum-1].endat+1;
                }
                else{
                    joker[jokenum].start = (joker[jokenum-1].endat+1+4) / 4 * 4;
                }
                joker[jokenum].endat = joker[jokenum].start+3;
                printf("%d\n", joker[jokenum].start);
            }
            else if(alpha == "long"){
                joker[jokenum].name = beta;
                if((joker[jokenum-1].endat+1) % 8 == 0){
                    joker[jokenum].start = joker[jokenum-1].endat+1;
                }
                else{
                    joker[jokenum].start = (joker[jokenum-1].endat+1+8) / 8 * 8;
                }
                joker[jokenum].endat = joker[jokenum].start+7;
                printf("%d\n", joker[jokenum].start);
            }
            else{
                for(int i = 0; i < nodeNum; i ++){
                    if(alpha == things[i].name){
                        for(int j = 0; j < things[i].itemNum; j ++){
                            joker[jokenum].name = beta + '.' + things[i].items[j].name;
                            if((joker[jokenum-1].endat+1) % things[i].items[j].len == 0){
                                joker[jokenum].start = joker[jokenum-1].endat+1;
                            }
                            else{
                                joker[jokenum].start = (joker[jokenum-1].endat+1+things[i].items[j].len) / things[i].items[j].len * things[i].items[j].len;
                            }
                            joker[jokenum].endat = joker[jokenum].start+things[i].items[j].len - 1;
                            if(j == 0)
                                printf("%d\n", joker[jokenum].start);
                            jokenum ++;
                        }
                        break;
                    }
                }
            }
            jokenum ++;
        }
        else if(op == 3){
            string alpha;
            cin >> alpha;
            for(int i = 0; i < jokenum; i ++){
                if(joker[i].name == alpha){
                    printf("%d\n", joker[i].start);
                    break;
                }
            }
        }
        else{
            int alpha = read();
            for(int i = 0; i < jokenum; i ++){
                if(joker[i].start <= alpha && joker[i].endat >= alpha){
                    cout << joker[i].name << endl;
                    break;
                }
                else if(joker[i].start > alpha){
                    printf("ERR\n");
                    break;
                }
            }
        }
    }
    fcloseall();
    return 0;
}
