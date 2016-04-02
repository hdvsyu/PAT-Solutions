
#include <iostream>  
#include <stdio.h>  
using namespace std;  
  
int main()  
{  
    int n;  
    cin >> n; 
  
    double num;
    double sum = 0.0;  
    for(int i=0; i<n; i++){  
        scanf("%lf",&num);  
        sum += num*(i+1)*(n-i);  
  
    }  

    printf("%.2f",sum);  
    return 0;  
}  
