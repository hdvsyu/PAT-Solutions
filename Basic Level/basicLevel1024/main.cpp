#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

// 将输入以.和E划分为三部分
string* parse(string in) {
    string *s = new string[3];
    
    int i = 0;
    while (in[i] != '.') {
        s[0] += in[i++];
    }
    i++;
    
    while (in[i] != 'E') {
        s[1] += in[i++];
    }
    i++;
    
    while (i < in.size()) {
        s[2] += in[i++];
    }
    return s;
}

// 把一个字符串转化为数值
int parseInt(string s) {
    int num = 0;
    for (int i = 1; i < s.size(); i++) {
        num = num * 10 + s[i] - '0';
    }
    
    if (s[0] == '-') {
        num = -num;
    }
    return num;
}

int main() {
    string in;
    cin >> in;
    string *sci = parse(in);
    
    int eff = parseInt(sci[0]);
    int pow = parseInt(sci[2]);
    
    if (pow >= 0) {
        //如果指数大于等于零，则小数点要向右边移动
        printf("%d", eff);
        
        // 如果第二部分的字符的长度小于指数的数值，则没有小数点
        bool havePoint = true;
        if (sci[1].length() <= pow) {
            havePoint = false;
        }
        
        // 输出
        int i = 0;
        for (i = 0; i < sci[1].length() && pow != 0; i++, pow--) {
            putchar(sci[1][i]);
        }
        
        if (havePoint) {
            printf(".");
            for (; i < sci[1].length(); i++) {
                putchar(sci[1][i]);
            }
        }
        
        while (pow != 0) {
            printf("0");
            pow--;
        }
        
    } else {
        //如果指数小于零，则小数点要向左边移动
        if (eff < 0) {
            printf("-");
            eff = -eff;
        }
        
        // 输出
        printf("0.");
        for (int i = 1; i < abs(pow); i++) {
            printf("0");
        }
        printf("%d", eff);
        cout << sci[1];
    }
    return 0;
}
