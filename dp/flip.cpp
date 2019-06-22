#include <cstdio> 
#include <cstdlib> 
#include<time.h> 
  
// Driver program 
int main(void) 
{ 
    // This program will create same sequence of  
    // random numbers on every program run  
    srand(time(0));
    for(int i = 0; i<5; i++) 
        printf(" %d ", rand()%4); 
    return 0; 
}