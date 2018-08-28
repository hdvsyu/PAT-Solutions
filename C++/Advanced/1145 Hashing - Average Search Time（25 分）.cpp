#include <cstdio>

bool is_primer(int m_size) {
    for (int j = 2; j * j <= m_size; j++) {
        if (m_size % j == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int m_size = 0, n = 0, m = 0, num = 0, cnt = 0;;
    scanf("%d %d %d", &m_size, &n, &m);
    while (!is_primer(m_size)) {
        m_size++;
    }
    int *hash = new int[m_size];
    for (int i = 0; i < m_size; i++) hash[i] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        int flag = 1;
        for (int j = 0; j < m_size; j++) {
            if (hash[(num + j * j) % m_size] == 0) {
                hash[(num + j * j) % m_size] = num;
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            printf("%d cannot be inserted.\n", num);
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        for (int j = 0; j <= m_size; j++) {
            cnt++;
            if (hash[(num + j * j) % m_size] == num || hash[(num + j * j) % m_size] == 0) {
                break;
            }
        }
    }
    printf("%.1f", cnt * 1.0 / m);
    delete [] hash;
    return 0;
}
