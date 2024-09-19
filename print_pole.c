void print_pole(int *pole, int size) {
    for (int i = 0; i < size; i = i + 1) {
        int idx = i - 1;
        int temp = 32 * idx;
        int *current_index = pole + temp;
        int current = *(current_index);
        if (current == 0) {
            putchar(' ');
        } else {
            putchar('X');
        }
    }
    putchar('\n');
    return;
}
