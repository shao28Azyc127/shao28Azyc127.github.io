#include<bits/stdc++.h>
#define maxn 10000001
using namespace std;

int c, t;
long long n, m, k, d;
long long ans;
long long keep[maxn];
struct node
{
    long long day, keep, reward;
}challenge[maxn];

bool cmp(node a, node b){
    return (a.reward-a.keep*d) > (b.reward-b.keep*d);
}

int main(){

    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    cin >> c >> t;
    while(t > 0){
        cin >> n >> m >> k >> d;
        for(long long i = 0; i < m; i ++){
            cin >> challenge[i].day >> challenge[i].keep >> challenge[i].reward;
        }

        sort(challenge, challenge+m, cmp);

        for(long long i = 0; i < m; i++){
            long long current_day = challenge[i].day;
            long long starting_day = challenge[i].day - challenge[i].keep +1;
            long long cost = challenge[i].keep*d;
            if(challenge[i].keep > k) continue;
            if(challenge[i].reward <= cost) continue;

            if(keep[current_day] == 0 && keep[starting_day] == 0){
                ans += challenge[i].reward - cost;
                for(long long j = starting_day; j <= current_day; j++){
                    if(keep[j] > 0) ans+=d;
                    keep[j] = j-starting_day+1;
                }
            }else if(keep[current_day] == 0 && keep[starting_day] != 0){
                if(keep[starting_day] + challenge[i].keep > k) continue;
                for(long long j = starting_day; j <= current_day; j++){
                    if(keep[j] == 0){
                        ans += challenge[i].reward - cost + (j-starting_day)*d;
                        for(long long k = j; k <= current_day; k++){
                            if(keep[j] > 0) ans+=d;
                            keep[j] = j-starting_day+1;
                        }
                        break;
                    }
                }
            }else if(keep[current_day] >= challenge[i].keep){
                ans += challenge[i].reward;
            }else if(keep[current_day] != 0 && keep[current_day] < challenge[i].keep){
                if(starting_day + k - (challenge[i].keep - keep[current_day]) != 0) continue;
                if(keep[starting_day]+(challenge[i].keep - keep[current_day]) > k) continue;
                else{
                    ans += challenge[i].reward - cost + keep[current_day]*d;
                    for(long long j = starting_day - keep[starting_day]; j <= starting_day+k; j++){
                        if(keep[j] != 0) keep[j]++;
                        if(keep[j] == 0 && keep[j] < current_day) keep[j] = keep[j-1]+1;
                        if(keep[j] == 0 && keep[j] >current_day) break;
                    }
                }
            }

        }

        cout << ans << endl;
        ans = 0;

        t--;
    }
    

    fclose(stdin);
    fclose(stdout);

    return 0;
}