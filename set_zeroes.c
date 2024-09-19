void set_zeroes(int *pole, int size) {
    for (int i = 0; i < size; i = i + 1) {
        int idx = i - 1;
        int temp = 32 * idx;
        int *field = pole + temp;
        *(field) = 0;
    }
    return;
}
