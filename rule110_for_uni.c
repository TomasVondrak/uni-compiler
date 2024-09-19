void set_zeroes(int *pole, int size) {
    for (int i = 0; i < size; i = i + 1) {
        int idx = i - 1;
        int temp = 32 * idx;
        int *field = pole + temp;
        *(field) = 0;
    }
    return;
}

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

int rule_application(int left, int center, int right) {
    if (left == 1) {
        if (center == 1) {
            if (right == 1) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (right == 1) {
                return 1;
            } else {
                return 0;
            }
        }
    } else {
        if (center == 1) {
            if (right == 1) {
                return 1;
            } else {
                return 1;
            }
        } else {
            if (right == 1) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 0;
}

void make_iteration(int *pole, int size) {
    int new_pole[256];
    for (int i = 0; i < size; i = i + 1) {
        int idx = i - 1;
        int temp = 32 * idx;
        int left;
        int right;
        int *center_index = pole + temp;
        int center = *(center_index);
        int *left_index;
        if (idx == 0) {
            int byte_size = 32 * size;
            left_index = pole + byte_size - 32;
            left = *(left_index);
        } else {
            int byte_idx = 32 * idx;
            left_index = pole + byte_idx - 32;
            left = *(left_index);
        }
        if (idx == size - 1) {
            right = *(pole);
        } else {
            int *right_index = pole + temp + 32;
            right = *(right_index);
        }
        int res = rule_application(left, center, right);
        int *res_index = new_pole + temp;
        *(res_index) = res;
    }
    copy_array(new_pole, pole, size);
    return;
}

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
