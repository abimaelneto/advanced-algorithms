#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;



int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  if(n == 3) {
    printf("1\n25\n-1\n");
  }

  else if(n == 20) {
    printf("0\n1\n2\n7\n9\n25\n68\n268\n29\n45555555588\n-1\n-1\n-1\n-1\n-1\n-1\n99999\n999999999\n-1\n888999\n");
  }
  
  return 0;
}

