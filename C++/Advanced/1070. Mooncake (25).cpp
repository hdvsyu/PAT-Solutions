//
//  1070.cpp
//  A
//
//  Created by JoyHwong on 16/8/10.
//  Copyright © 2016年 JoyHwong. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

struct Mooncake {
    double memory;
    double sale;
    double price;
};

bool cmp(Mooncake a, Mooncake b) {
    return a.price > b.price;
}

int main() {
    int n = 0, d = 0;
    scanf("%d %d", &n, &d);
    
    Mooncake *mooncakes = new Mooncake[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &mooncakes[i].memory);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%lf", &mooncakes[i].sale);
        mooncakes[i].price = mooncakes[i].sale / mooncakes[i].memory;
    }
    
    sort(mooncakes, mooncakes + n, cmp);
    
    double total = 0;
    for (int i = 0; i < n; i++) {
        if (d - mooncakes[i].memory >= 0) {
            total += mooncakes[i].sale;
            d -= mooncakes[i].memory;
        } else {
            total += mooncakes[i].price * d;
            break;
        }
    }
    
    printf("%.2f", total);
}