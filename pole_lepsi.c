int main() {
    char pole[10];
    char res;
    char *eight = 1;
    char *sixteen = 2;
    char i = 20;
    if (i > 16) {
        *(pole) = 'a';
        char *pole_1 = pole + eight;
        *(pole_1) = 'b';
        char *pole_2 = pole + sixteen;
        *(pole_2) = 'c';
    }
    res = *(pole);
    putchar(res);
    putchar(10);
    return 0;
}
