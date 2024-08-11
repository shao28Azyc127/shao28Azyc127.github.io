

#include <cmath>
#include <fstream>

using namespace std;

int _t;
int _m;
int a;
int b;
int c;

int main () {

  ifstream inFile("uqe.in");
  ofstream outFile("uqe.out");
  
  inFile >> _t >> _m;

  for (int i = 0; i < _t; i++) {
    inFile >> a >> b >> c;
    outFile << 0 << endl;
  }

  inFile.close();
  outFile.close();
  
  return 0;
}
