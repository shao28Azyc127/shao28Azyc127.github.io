#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    int n; //testCases
    cin >> n;

    //if(n == 1){
    //    cout << 81 << endl;
    //    return 0;
    //}

    int i,j,k,fth;
    int dt[n][5];

    for(i = 0;i < n;i++){
        for(j = 0;j < 5;j++){
            cin >> dt[i][j];
        }
    }

    int cases[81][5];
    bool good[81];
    //generate base cases
    for(i = 0;i < 81;i++){
        cases[i][0] = dt[0][0];
        cases[i][1] = dt[0][1];
        cases[i][2] = dt[0][2];
        cases[i][3] = dt[0][3];
        cases[i][4] = dt[0][4];
        good[i] = true;
    }

    int cnt = 0;
    for(i = 0;i < 5;i++){//single
        for(j = 1;j < 10;j++){
            cases[cnt][i] += j;
            if(cases[cnt][i] >= 10){
                cases[cnt][i] -= 10;
            }
            cnt++;
        }
    }
    for(i = 0;i < 4;i++){//double
        for(j = 1;j < 10;j++){
            cases[cnt][i] += j;
            if(cases[cnt][i] >= 10){
                cases[cnt][i] -= 10;
            }
            cases[cnt][i+1] += j;
            if(cases[cnt][i+1] >= 10){
                cases[cnt][i+1] -= 10;
            }
            cnt++;
        }
    }

    int diff[5];
    int status;
    //0=fuck theres nothing, proceeed to double
    //1=found it! just continue

    //for each cases
    for(i = 1;i < n;i++){
        //make every possible case(that are still possible)
        //run the caculation once and see is the current case included in the return
        //cout << "RUN" << i+1 << endl;

        for(j = 0;j < 81;j++){
            if(!good[j]) continue;

            status = 0;

            for(k = 0;k < 5;k++){//single
                for(fth = 1;fth < 10;fth++){
                    diff[0] = cases[j][0];
                    diff[1] = cases[j][1];
                    diff[2] = cases[j][2];
                    diff[3] = cases[j][3];
                    diff[4] = cases[j][4];

                    diff[k] += fth;
                    if(diff[k] >= 10){
                        diff[k] -= 10;
                    }
                
                    if(diff[0] == dt[i][0] && diff[1] == dt[i][1] && diff[2] == dt[i][2] && diff[3] == dt[i][3] && diff[4] == dt[i][4]){//Nintendooooooooooo MEMES
                        status = 1;
                        break;
                    }
                }
            }

            if(status == 1) continue;

            for(k = 0;k < 4;k++){//double
                for(fth = 1;fth < 10;fth++){
                    diff[0] = cases[j][0];
                    diff[1] = cases[j][1];
                    diff[2] = cases[j][2];
                    diff[3] = cases[j][3];
                    diff[4] = cases[j][4];

                    diff[k] += fth;
                    if(diff[k] >= 10){
                        diff[k] -= 10;
                    }
                    diff[k+1] += fth;
                    if(diff[k+1] >= 10){
                        diff[k+1] -= 10;
                    }
                
                    if(diff[0] == dt[i][0] && diff[1] == dt[i][1] && diff[2] == dt[i][2] && diff[3] == dt[i][3] && diff[4] == dt[i][4]){//Nintendooooooooooo MEMES
                        status = 1;
                        break;
                    }
                }
            }

            if(status == 0){
                good[j] = false; //goodraj - ebimayo
                //cout << "SUS ";
            }
            //cout << cases[j][0] << " " << cases[j][1] << " " << cases[j][2] << " " << cases[j][3] << " " << cases[j][4] << endl;
        }
    }

    cnt = 0;
    //find how much left
    for(i = 0;i < 81;i++){
        if(good[i]){
            cnt++;
        }
    }

    //cout << "Eligable Cases:\n";
    //for(i = 0;i < 81;i++){
    //    if(!good[i]) continue;
    //
    //    for(j = 0;j < 5;j++){
    //        cout << cases[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    //cout << "Build19\n(You should not see this)" << endl;
    cout << cnt << endl;

    //i wrote my comments in englis because theres no chinese input methods lol XD
    return 0;
}