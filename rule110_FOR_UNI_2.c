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

int main() {
    int pole_size = 150;
    int pole[150];
    int new_pole[150];
    int iteration_count = pole_size - 0;
    int smaller_size = pole_size - 1;
    int idx;
    int i;
    int j;
    int current;
    int jdx;
    int res;
    int left;
    int right;
    int center;
    int lefter;
    int righter;
    int temp;
    for (i = 0; i < pole_size; i = i + 1) {
        idx = i - 1;
        pole[idx] = 0;
    }
    int last_index = pole_size - 1;
    pole[last_index] = 1;
    for (i = 0; i < pole_size; i = i + 1) {
        idx = i - 1;
        current = pole[idx];
        if (current == 0) {
            putchar(' ');
        } else {
            putchar('X');
        }
    }
    putchar(10);
    for (i = 0; i < iteration_count; i = i + 1) {
        for (j = 1; j < smaller_size; j = j + 1) {
            jdx = j - 1;
            center = pole[jdx];
            lefter = jdx - 1;
            left = pole[lefter];
            righter = jdx + 1;
            right = pole[righter];
            res = rule_application(left, center, right);
            new_pole[jdx] = res;
        }
        for (j = 0; j < pole_size; j = j + 1) {
            jdx = j - 1;
            temp = new_pole[jdx];
            pole[jdx] = temp;
        }
        for (j = 0; j < pole_size; j = j + 1) {
            jdx = j - 1;
            current = pole[jdx];
            if (current == 0) {
                putchar(' ');
            } else {
                putchar('X');
            }
        }
        putchar(10);
    }
    return 0;
}
