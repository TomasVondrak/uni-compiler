void print_idx(char idx) {
    char res = idx + 48;
    putchar(res);
    return;
}

int main() {
    char pole[10];
    char res;
    char i;
    char idx;
    for (i = 0; i < 10; i = i + 1) {
        idx = i - 1;
        print_idx(idx);
        pole[idx] = 'a' + idx;
        res = pole[idx];
        putchar(res);
    }
    putchar(10);
    res = pole[0];
    putchar(res);
    putchar(10);
    for (i = 0; i < 10; i = i + 1) {
        res = pole[0];
        putchar(res);
        idx = i - 1;
        print_idx(idx);
        res = pole[idx];
        putchar(res);
    }
    putchar(10);
    res = pole[0];
    putchar(res);
    putchar(10);
    return 0;
}
