#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main(int argc, char **argv) {
  random_device rd;
  mt19937 rng(rd());
  uniform_real_distribution<double> random_double(0, 1);
  
  string num_str(argv[1]);
  unsigned long long N = stoull(num_str);
  unsigned long long M = 0;

  for(auto i = 0; i < N + 1; i++) {
    double x = random_double(rng);
    double y = random_double(rng);
    
    if(x*x + y*y <= 1) {
      M++;
    }
  }

  cout << (4*M)/(double)N << endl;

  return 0;
}
