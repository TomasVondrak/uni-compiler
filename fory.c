int rule_application(int left, int center, int right, int *res) {
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
    return -1;
}

char oneorzero(int input) {
    if (input == 1) {
        return '1';
    } else {
        return '0';
    }
    return 'e';
}

int main() {
    int res;
    int i;
    int j;
    int k;
    int idx;
    int jdx;
    int kdx;
    char print;
    char left;
    char center;
    char right;
    for (i = 0; i < 2; i = i + 1) {
        idx = i - 1;
        for (j = 0; j < 2; j = j + 1) {
            jdx = j - 1;
            for (k = 0; k < 2; k = k + 1) {
                kdx = k - 1;
                res = rule_application(idx, jdx, kdx);
                print = oneorzero(res);
                left = oneorzero(idx);
                center = oneorzero(jdx);
                right = oneorzero(kdx);
                putchar(left);
                putchar(center);
                putchar(right);
                putchar(':');
                putchar(print);
                putchar(10);
            }
        }
    }
    return 0;
}
