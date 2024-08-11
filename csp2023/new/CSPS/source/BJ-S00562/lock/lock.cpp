# include<iostream>
# include<algorithm>
# include<cmath>
# include<map>
# define endl "\n"
# define int long long
using namespace std;
int n, a[6][6];
int sub(int a, int b) {
    if(a>=b) return a-b;
    else return a+10-b;
}
bool check(int x, int y) {
    if(sub(a[2][x], a[1][x])==sub(a[2][y], a[1][y])) return true;
}
signed main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    if(n==1) {
        cout << 81 << endl;
        return 0;
    } else if(n==2) {
        cin >> a[1][1] >> a[1][2] >> a[1][3] >> a[1][4] >> a[1][5];
        cin >> a[2][1] >> a[2][2] >> a[2][3] >> a[2][4] >> a[2][5];
        bool s1=(a[1][1]==a[2][1]), s2=(a[1][2]==a[2][2]), s3=(a[1][3]==a[2][3]), s4=(a[1][4]==a[2][4]), s5=(a[1][5]==a[2][5]);
        int t=s1+s2+s3+s4+s5;
        if(t==0) cout << 0 << endl;
        else if(t==1) {
            if(s2==true || s4==true) cout << 0 << endl;
            else if(s1==true) {
                if(sub(a[2][2], a[1][2])==sub(a[2][3], a[1][3]) && sub(a[2][4], a[1][4])==sub(a[2][5], a[1][5])) cout << 2 << endl;
                else cout << 0 << endl;
            } else if(s3==true) {
                if(sub(a[2][2], a[1][2])==sub(a[2][1], a[1][1]) && sub(a[2][4], a[1][4])==sub(a[2][5], a[1][5])) cout << 2 << endl;
                else cout << 0 << endl;
            } else if(s5==true) {
                if(sub(a[2][2], a[1][2])==sub(a[2][1], a[1][1]) && sub(a[2][4], a[1][4])==sub(a[2][3], a[1][3])) cout << 2 << endl;
                else cout << 0 << endl;
            }
        } else if(t==2) {
            if(s2==true && s4==true) cout << 0 << endl;
            else if(s1==true && s2==true) {
                if(check(3, 4) || check(4, 5)) cout << 2 << endl;
                else cout << 0 << endl;
            } else if(s1==true && s3==true) {
                if(check(4, 5)) cout << 2 << endl;
                else cout << 0 << endl;
            } else if(s1==true && s4==true) {
                if(check(2, 3)) cout << 2 << endl;
                else cout << 0 << endl;
            } else if(s1==true && s5==true) {
                if(check(2, 3) || check(3, 4)) cout << 2 << endl;
                else cout << 0 << endl;
            } else if(s2==true && s5==true) {
                if(check(3, 4)) cout << 2 << endl;
                else cout << 0 << endl;
            } else if(s2==true && s3==true) {
                if(check(4, 5)) cout << 2 << endl;
                else cout << 0 << endl;
            } else if(s3==true && s4==true) {
                if(check(1, 2)) cout << 2 << endl;
                else cout << 0 << endl;
            } else if(s4==true && s5==true) {
                if(check(1, 2) || check(2, 3)) cout << 2 << endl;
                else cout << 0 << endl;
            }
        } else if(t==3) {
            if(s2!=true && s4!=true) {
                if(check(2, 4)) cout << 2 << endl;
                else cout << 10 << endl;
            } else if(s1!=true && s2!=true) {
                if(check(1, 2)) cout << 2 << endl;
                else cout << 10 << endl;
            } else if(s1!=true && s3!=true) {
                if(check(1, 3)) cout << 2 << endl;
                else cout << 10 << endl;
            } else if(s1!=true && s4!=true) {
                if(check(1, 4)) cout << 2 << endl;
                else cout << 10 << endl;
            } else if(s1!=true && s5!=true) {
                if(check(1, 5)) cout << 2 << endl;
                else cout << 10 << endl;
            } else if(s2!=true && s5!=true) {
                if(check(2, 5)) cout << 2 << endl;
                else cout << 10 << endl;
            } else if(s2!=true && s3!=true) {
                if(check(2, 3)) cout << 2 << endl;
                else cout << 10 << endl;
            } else if(s3!=true && s4!=true) {
                if(check(3, 4)) cout << 2 << endl;
                else cout << 10 << endl;
            } else if(s4!=true && s5!=true) {
                if(check(4, 5)) cout << 2 << endl;
                else cout << 10 << endl;
            }

        }
    } else {
        bool v, w, x, y, z;
        int nv=0, nw=0, nx=0, ny=0, nz=0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=5; j++) {
                cin >> a[j][i];
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
            int s1=(a[i][1]==a[j][1]), s2=(a[i][2]==a[j][2]), s3=(a[i][3]==a[j][3]), s4=(a[i][4]==a[j][4]), s5=(a[i][5]==a[j][5]);
            if(s1+s2+s3+s4+s5==1) {
                if(s1==true) v=true;
                if(s2==true) w=true;
                if(s3==true) x=true;
                if(s4==true) y=true;
                if(s5==true) z=true;
                if(s1==false) nv+=2;
                if(s2==false) nw+=2;
                if(s3==false) nx+=2;
                if(s4==false) ny+=2;
                if(s5==false) nz+=2;
            } else {
                if(s1==true) v=true;
                if(s2==true) w=true;
                if(s3==true) x=true;
                if(s4==true) y=true;
                if(s5==true) z=true;
                if(s1==false) nv+=1;
                if(s2==false) nw+=1;
                if(s3==false) nx+=1;
                if(s4==false) ny+=1;
                if(s5==false) nz+=1;

                }
            }
        }
        int ans=1;
        if(!v) ans*=(10-nv);
        if(!w) ans*=(10-nw);
        if(!x) ans*=(10-nx);
        if(!y) ans*=(10-ny);
        if(!z) ans*=(10-nz);
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
1 2 3 4 6
1 3 3 4 5
1 4 3 4 5
2 2 3 4 5
*/
