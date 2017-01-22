#include <cstdio>
#include <cstdlib>

int cmp (const void *a, const void *b) {
    int arg1 = *static_cast<const int *>(a);
    int arg2 = *static_cast<const int *>(b);
    
    if (arg1 > arg2) return -1;
    if (arg1 < arg2) return 1;
    return 0;
}

int main(int argc, char const *argv[]) {
    int nc = 0, np = 0, *coupon, *product;
    scanf("%d", &nc);
    coupon = new int [nc];
    for (int i = 0; i < nc; i++) {
        scanf("%d", &coupon[i]);
    }
    scanf("%d", &np);
    product = new int [np];
    for (int i = 0; i < np; i++) {
        scanf("%d", &product[i]);
    }
    qsort(coupon, nc, sizeof(coupon[0]), cmp);
    qsort(product, np, sizeof(product[0]), cmp);
    
    int i = 0, j = 0, result = 0, e = nc - 1, r = np - 1;
    while (coupon[i] > 0 && product[j] > 0 && i < nc && j < np) {
        result += coupon[i] * product[j];
        i++; j++;
    }
    
    
    while (e >= i && r >= j && coupon[e] * product[r] > 0) {
        result += coupon[e] * product[r];
        e--; r--;
    }
    
    printf("%d\n", result);
    delete [] product;
    delete [] coupon;
    return 0;
}