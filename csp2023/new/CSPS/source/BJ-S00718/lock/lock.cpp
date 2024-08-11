#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("lock.in",  "r", stdin);
    freopen("lock.out", "w", stdout);

    int m, ans = 0;
    cin >> m;
    int states[m][5];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < 5; j++){
            cin >> states[i][j];
        }
    }

    int turn1 = 45, turn2 = 36;
    int turn_diff_count = 0;
    bool diff_k[5];
    for(int i = 0; i < 5; i++){
        diff_k[i] = 0;
    }
    vector<pair<int, pair<int, int>>> turn_diff_poss;

    for(int i = 0; i < m; i++){
        for(int j = i; j < m; j++){
            for(int k = 0; k < 5; k++){
                if(states[i][k] != states[j][k] && diff_k[k] == 0){
                    turn_diff_count++;
                    diff_k[k] = 1;
                    turn_diff_poss.push_back({states[i][k] - states[j][k], {i, j}});
                }
            }
        }
    }

    if(turn_diff_count == 1) turn1 = 10;
    else if(turn_diff_count >= 2) turn1 = 0;

    if(turn_diff_count %2 == 1) turn2 = 0;
    else if(turn_diff_count > 2) turn2 = 0;
    else if(turn_diff_count == 2){
        if(abs(turn_diff_poss[0].second.first - turn_diff_poss[0].second.second) != 1) turn2 = 0;
        if(abs(turn_diff_poss[1].second.first - turn_diff_poss[1].second.second) != 1) turn2 = 0;
        if(turn_diff_poss[0].first != turn_diff_poss[1].first) turn2 = 0;
    }

    ans = turn1 + turn2;
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}