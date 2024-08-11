

#include <cmath>
#include <fstream>

using namespace std;

int _res;
int _num;

int main () {

  ifstream inFile("apple.in");
  ofstream outFile("apple.out");
  
  inFile >> _num;
  int i = 0;
  while (_num > 0) {
    i++;
    if (_num % 3 == 1)
      if (_res == 0)
	_res = i;
    _num -= ceil(1.0*_num/3);
  }

  outFile << i << " " << _res;

  inFile.close();
  outFile.close();
  
  return 0;
}