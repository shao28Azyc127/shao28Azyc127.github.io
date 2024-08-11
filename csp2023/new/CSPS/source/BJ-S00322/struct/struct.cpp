#include<iostream>
#include<cstdio>
#include<map>
#define MAXL 101

using namespace std;



char t[MAXL][11] = {"byte", "short", "int", "long"};
map m;
int tn = 4;
int n;
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int k, addr;
    char s[11];
    char t[11], n[11];
    int op;//W(TAT)W
    /*
     *    #                            #    #
     *   #      ########              #      #
     *  #             #       #####  ##  #########
     *########       #         # #  # #     ##
     *  #  #   ###########      #     #   #######
     *   ##         #          # #    #     ##
     *  #  #        #                 #   #######            ###     ###     ###
     * #    #     # #                 #     ##              #####   #####   #####
     *             #                  # ############         ###     ###     ###
     *
     */

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> s >> k;
            for (int j = 1; j < k; j++)
                cin >> t >> n;
            break;
        case 2:
            cin >> t >> n;
            break;
        case 3:
            cin >> s;
            break;
        case 4:
            cin >> addr;
            break;
        }
    }

    return 0;
}
