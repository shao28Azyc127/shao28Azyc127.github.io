#include<bits/stdc++.h>
using namespace std;
int T, M;
int q[5005][4]={0};

int gcd(int a, int b){
    int maxnum = max(a, b);
    int minnum = min(a, b);

    for (int i=minnum; i>=1; i--){
        if (minnum%i == 0 && maxnum%i == 0){
            return i;
        }
    }
    return 1;
}

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    scanf("%d%d", &T, &M);
    for (int i=1; i<=T; i++){
        scanf("%d%d%d", &q[i][1], &q[i][2], &q[i][3]);
    }
    for (int i=1; i<=T; i++){
        int a = q[i][1];
        int b = q[i][2];
        int c = q[i][3];

        int derta = b*b-4*a*c;
        if (derta < 0){
            printf("NO\n");
            break;
        }
        if (derta == 0){
            int fm = (-2)*a;
            int fz = b;
            bool symbol = false;

            if (fz == 0){
                printf("0\n");
                break;
            }

            if (fm > 0 && fz > 0){
                symbol = true;
            }
            else if (fm < 0 && fz < 0){
                symbol = true;
            }

            fm = abs(fm);
            fz = abs(fz);
            int gcd_fs = gcd(fm, fz);
            fm = fm/gcd_fs;
            fz = fz/gcd_fs;

            if (fm == 1){
                if (symbol == true){
                    printf("%d\n", fz);
                    break;
                }
                else{
                    printf("%d\n", (-1)*fz);
                    break;
                }
            }

            if (symbol == false){
                printf("-");
            }
            printf("%d/%d\n", fz, fm);
        }

        if (derta > 0){
            int fm = 2*a;
            int fz_yl = (-1)*b;
            int fz_wl_w = derta;
            int fz_wl = sqrt(fz_wl_w);

            if (fz_wl*fz_wl == fz_wl_w){
                int fz_1 = fz_yl+fz_wl;
                int fz_2 = fz_yl-fz_wl;
                double ans1 = fz_1*1.0/fm;
                double ans2 = fz_2*1.0/fm;

                if (ans1 >= ans2){
                    bool symbol = false;
                    if (fz_1 > 0 && fm > 0){
                        symbol = true;
                    }
                    if (fz_1 < 0 && fm < 0){
                        symbol = true;
                    }


                    fm = abs(fm);
                    int fz = abs(fz_1);
                    int gcd_fs = gcd(fm, fz);
                    fm = fm/gcd_fs;
                    fz = fz/gcd_fs;

                    if (fm == 1){
                        if (symbol == true){
                            printf("%d\n", fz);
                            break;
                        }
                        else{
                            printf("%d\n", (-1)*fz);
                            break;
                        }
                    }

                    if (symbol == false){
                        printf("-");
                    }
                    printf("%d/%d\n", fz, fm);
                }
                else{
                    bool symbol = false;
                    if (fz_2 > 0 && fm > 0){
                        symbol = true;
                    }
                    if (fz_2 < 0 && fm < 0){
                        symbol = true;
                    }

                    fm = abs(fm);
                    int fz = abs(fz_2);
                    int gcd_fs = gcd(fm, fz);
                    fm = fm/gcd_fs;
                    fz = fz/gcd_fs;

                    if (fm == 1){
                        if (symbol == true){
                            printf("%d\n", fz);
                            break;
                        }
                        else{
                            printf("%d\n", (-1)*fz);
                            break;
                        }
                    }

                    if (symbol == false){
                        printf("-");
                    }
                    printf("%d/%d\n", fz, fm);
                }
            }
            else{
                    /*
                int fm = 2*a;
                int fz_yl = (-1)*b;
                int fz_wl_w = derta;
                int fz_wl = sqrt(fz_wl_w);
                */

                bool symbol = false;
                if (fz_yl > 0 && fm > 0){
                    symbol = true;
                }
                if (fz_yl < 0 && fm < 0){
                    symbol = true;
                }


                fm = abs(fm);
                int fz = abs(fz_yl);
                int gcd_fs = gcd(fm, fz);
                fm = fm/gcd_fs;
                fz = fz/gcd_fs;

                if (fm == 1){
                    if (symbol == true){
                        printf("%d\n", fz);
                        break;
                    }
                    else{
                        printf("%d\n", (-1)*fz);
                        break;
                    }
                }

                if (symbol == false){
                    printf("-");
                }
                printf("%d/%d+", fz, fm);

                symbol = false;
                if (fm > 0){
                    symbol = true;
                }

                fm = abs(fm);
                fz = abs(fz_wl);
                gcd_fs = gcd(fm, fz);
                fm = fm/gcd_fs;
                fz = fz/gcd_fs;

                if (fm == 1){
                    if (symbol == false){
                        printf("-");
                    }
                    printf("%d", fz);
                    break;
                }
                else{
                    if (symbol == false){
                        printf("-");
                    }
                    if (fz == 1){
                        printf("sqrt(%d)/%d", derta, fm);
                        break;
                    }
                    else{
                        printf("%d*sqrt(%d)/%d", fz, derta, fm);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
