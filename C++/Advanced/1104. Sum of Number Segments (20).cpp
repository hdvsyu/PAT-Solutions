#include <cstdio>
using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    double num = 0, sum = 0.0;
    for(int i=0; i<n; i++){
        scanf("%lf",&num);
        sum += num*(i+1)*(n-i);
        
    }
    
    printf("%.2f",sum);
    return 0;
}
