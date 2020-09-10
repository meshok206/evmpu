#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>

double seed = 1111.0;
double random_double() {
  double k = 16807.0;
  double m = 2147483647.0;
  double q;

  seed = k*seed;
  q = floor(seed/m);
  seed = seed - q*m;  

  return (seed/m);
}

int main(int argc, char **argv) {
  srand((long)time(NULL));
  seed = rand();
  char *end = (argv[1] + strlen(argv[1]));
  uint64_t N = strtoull(argv[1], &end, 10);  
  uint64_t M = 0;

  for(uint64_t i = 0; i < N + 1; i++) {
    double x = random_double();
    double y = random_double();
    
    if(x*x + y*y <= 1) {
      M++;
    }
  }

  printf("%lf\n", (4*M)/(double)N);

  return 0;
}
