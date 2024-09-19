int main() {
    char pole[10];
    char res;
    *(pole) = 'a';
    char *eight = 8;
    char *pole_1_idx = pole + eight;
    *(pole_1_idx) = 'b';
    char *pole_2_idx = pole_1_idx + eight;
    *(pole_2_idx) = 'c';
    res = *(pole);
    putchar(res);
    res = *(pole_1_idx);
    putchar(res);
    res = *(pole_2_idx);
    putchar(res);
    *(pole) = 'd';
    res = *(pole);
    putchar(res);
    putchar(10);
    return 0;
}
