void print_line (int length) {
    for (int i = 0; i < length; i = i + 1) {
        putchar('#');
    }
    putchar(10);
    return;
}

int main() {
    int length = 10;
    int heigth = 10;
    for (int i = 0; i < heigth; i = i + 1) {
        print_line(length);
    }
    return 0;
}
