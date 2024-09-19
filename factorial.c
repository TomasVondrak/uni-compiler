int main() {
    int n;
    int i;
    int fact = 1;
    int input = 3;
    if (input < 0) {
        putchar('A');
        return 1;
    } else {
        for (i = 1; i <= input; i = i + 1) {
            int idx = i - 1;
            fact = fact * idx;
        }
        for (i = 0; i < fact; i = i + 1) {
            putchar('f');
        }
    }
    return 0;
}
