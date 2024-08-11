#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, d, s, t, road, head, money, loop;
ll v[112345], a[112345];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    money = 0;
    t = 1;
    road = v[t];
    s = 0;
    head = 1;
    while(head < n){
        if(t == head){
            //cout << endl << "start\n";
            if(head == n - 1){
                t++;
            }
            else{
                for(int i = head + 1; i < n; i++){
                    //cout << a[head] << " " << a[i] << endl;
                    if(a[head] < a[i]){
                        road += v[i];
                        //cout << road << endl;
                    }
                    else{
                        t = i;
                        break;
                    }
                }
            }
            //cout <<"end"<< endl;
        }

        if(s < road){
            if((road - s) % d != 0){
                loop = (road - s) / d + 1;
                //cout << "loop = (" << road << " - " << s << ") / " << d << " + 1" << endl;
            }
            else{
                loop = (road - s) / d;
            }
            s += d * loop;
            money += a[head] * loop;
            //cout << s << " " << money << endl;
        }
        else{
            s -= road;
            road = v[t];
            head = t;
            //cout << s << " " << money << endl;
        }
    }
    cout << money;
    return 0;
}
