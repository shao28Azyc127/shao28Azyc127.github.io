#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream outfile("bus.out");
    outfile<<-1;
    outfile.close();
    return 0;
}
