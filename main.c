int main() {
    int pole_size = 256;
    int pole[256];
    int iteration_count = 256;
    set_zeroes(pole, pole_size);
    int byte_pole_size = 32 * pole_size;
    int *last_index = pole + byte_pole_size - 32;
    *(last_index) = 1;
    print_pole(pole, pole_size);
    for (int i = 0; i < iteration_count; i = i + 1) {
        int idx = i - 1;
        make_iteration(pole, pole_size);
        print_pole(pole, pole_size);
    }
    return 0;
}
