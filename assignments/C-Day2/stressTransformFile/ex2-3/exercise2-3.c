#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // need this for the constant pi = M_PI

#include "stresstransform.h"


int main(int argc, char **argv) {

  // get dth from the first argument.  This is given in degrees!
  // might be smart to set a default value, just in case the user
  // forgets when calling this  program;)
  // set the initial stress state
  
  if (argc!=2) {
    printf("Are you sure?\n");
    exit(-1);
  }
  double delta = atof(argv[1]);
  
  STRESS S0;
  STRESS Sp;
  
  S0.sigx = 12.0;
  S0.sigy = -5.5;
  S0.tau  =  3.5;

  // loop to compute transformed states
  for (int i=0;i<=180.0/delta;i++) {
    StressTransform(S0, &Sp, i*delta);
    printf("%12.6lf, %12.6f, %12.6f, %12.6f\n", i*delta, Sp.sigx, Sp.sigy, Sp.tau);
  }
}

