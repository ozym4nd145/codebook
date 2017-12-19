// Euler’s Totient function phi(n) is count of numbers in
// {1, 2, 3, …, n} whose GCD with n is 1.
// This code took less than 0.5s to calculate with MAX = 10^7
#define MAX 10000000

int phi[MAX];
bool pr[MAX];

void totient(){
  for(int i = 0; i < MAX; i++){
    phi[i] = i;
    pr[i] = true;
  }
  for(int i = 2; i < MAX; i++)
    if(pr[i]){
      for(int j = i; j < MAX; j+=i){
        pr[j] = false;
        phi[j] = phi[j] - (phi[j] / i);
      }
      pr[i] = true;
    }
}

int fi(int n) {          
  int result = n;          
  for(int i=2;i*i <= n;i++) {            
    if (n % i == 0) result -= result / i;            
    while (n % i == 0) n /= i;          
  }          
  if (n > 1) result -= result / n;          
  return result;        
}