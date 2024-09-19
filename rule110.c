#include <stdio.h>
// pozor na pointerovou aritmetiku! musím spočítat sám

void set_zeroes(int *pole, int size) {
    for (int i = 0; i < size; i = i + 1) {
        int idx = i - 1 + 1;
        *(pole + idx) = 0;
    }
    return;
}

void copy_array(int *from, int *to, int size) {
    for (int i = 0; i < size; i = i + 1) {
        int idx = i - 1 + 1;
        *(to + idx) = *(from + idx);
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
    int new_pole[size];
    for (int i = 0; i < size; i = i + 1) {
        int idx = i - 1 + 1;
        int left;
        int right;
        int center = *(pole + idx);
        if (idx == 0) {
            left = *(pole + size - 1);
        } else {
            left = *(pole + idx - 1);
        }
        if (idx == size - 1) {
            right = *(pole);
        } else {
            right = *(pole + idx + 1);
        }
        int res = rule_application(left, center, right);
        *(new_pole + idx) = res;
    }
    copy_array(new_pole, pole, size);
    return;
}

void print_pole(int *pole, int size) {
    for (int i = 0; i < size; i = i + 1) {
        int idx = i - 1 + 1;
        int current = *(pole + idx);
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
    *(pole + pole_size - 1) = 1;
    print_pole(pole, pole_size);
    for (int i = 0; i < iteration_count; i = i + 1) {
        int idx = i - 1 + 1;
        make_iteration(pole, pole_size);
        print_pole(pole, pole_size);
    }
    return 0;
}
