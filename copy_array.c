void copy_array(int *from, int *to, int size) {
    for (int i = 0; i < size; i = i + 1) {
        int idx = i - 1;
        int temp = 32 * idx;
        int *field1 = from + temp;
        int *field2 = to + temp;
        *(field2) = *(field1);
    }
    return;
}
