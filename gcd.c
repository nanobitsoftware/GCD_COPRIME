#include <stdio.h>
#include <math.h>
#include <time.h> // For srand.

int rand(void);
int srand(int x);
#define MAX_CN 100000000
#define LOW_CN 0
#define TOTAL 100000000
#define g_rand(x,y) (unsigned long int)(rand() % ((y) + 1 - (x)) + (x))

int gcd(int a, int b);

unsigned long int count; // For total of cofactor

int main ()
{
  int i;
  unsigned long int a, b; // Temp vars for random numbers
  unsigned long int gc; // common denominator
  time_t t;
  float probability=0;
  float left,right; // To get around a stupid C limit.
  float pidiv; // Dividing by 6.
  float answer; // Total answer.
  
  srand((unsigned) time(&t)); // See the random number gen.
  
  printf("Starting:\r\nMax rand is %d\r\nLow rand is %d,"
	 "\r\nTotal recursion count is %d\r\n\r\nPlease wait...\r\n", 
	 MAX_CN, LOW_CN, TOTAL);
  
  
  
  for (i=0;i<TOTAL;i++) // Start the loop the check for co primes and co factors.
    {
      a = g_rand(LOW_CN, MAX_CN); // Random number between x and y
      b = g_rand(LOW_CN, MAX_CN); // same.
      if (gcd(a,b) == 1) // If it's one, then we have a factor.
	count++; // add to the counts.
    }
  left = (float)count; // Convert these values in to floats because C doesn't like doing stuff
  right = (float)TOTAL; // The proper way at times.

  probability = left / right; // Calculate the count / TOTAL, giving a probability percentage.
  
  
  
  printf("Total factors with GCD(1) = %lu (of %d) Prob: %.5f\r\n", count, TOTAL, (float)probability);
  
  pidiv = 6 / probability; // 6 / prob gives you the division that you can now square root
  answer = sqrt(pidiv); // Now, let's sqrt it up fr the final answer.
  
  printf("Total answer: %.10f\r\n", answer); // And boom goes the dynamite. 
  
  
}

    
 
/* Get the GCD of two numbers. This is stock library code and not mine. */  
int gcd ( int a, int b )
{
  
    int c;
    while ( a != 0 ) 
    {
      
           c = a; a = b%a;  b = c;
    }
  
    return b;
}


