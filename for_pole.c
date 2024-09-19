int main() {
    char pole[10];
    char size = 10;
    char res;
    char *zero = 0;
    char *current = pole + zero;
    char i = 1;
    char idx = 0;
    char *eight = 8;
    //for (i = 0; i < size; i = i + 1) {
        idx = i - 1;
        *(current) = 'a' + idx;
        res = *(current);
        putchar(res);
        current = current + eight;
    //}
    current = pole + zero;
    //for (i = 0; i < size; i = i + 1) {
        res = *(current);
        putchar(res);
        current = current + eight;
    //}
    putchar(10);
    return 0;
}
