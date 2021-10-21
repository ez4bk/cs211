#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//Function declerations
bool is_prime(int n);

int main(int argc, char* argv[]) {
  int number = atoi(argv[1]);
  int num = number;
  //bool isPrime = is_prime(number);
  //int biggestPrime;
  
  for (int i=2; i<=num; i++){
    if (is_prime(num-i-i)&&is_prime(i)){
      printf("%d = %d + %d + %d", num, i, i, num-i-i);
      break;
    }
  }
  
}

bool is_prime(int n){
  if (n<2){
    return false;
  }

  for (int i=2; i<=sqrt(n); i++){
    if((n%i)==0){
      return false;
    }
  }
  return true;
}
