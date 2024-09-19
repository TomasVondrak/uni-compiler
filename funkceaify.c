void rule_application(int left, int center, int right, int *res) {
    if (left == 1) {
        if (center == 1) {
            if (right == 1) {
                *(res) = 0;
            } else {
                *(res) = 1;
            }
        } else {
            if (right == 1) {
                *(res) = 1;
            } else {
                *(res) = 0;
            }
        }
    } else {
        if (center == 1) {
            if (right == 1) {
                *(res) = 1;
            } else {
                *(res) = 1;
            }
        } else {
            if (right == 1) {
                *(res) = 1;
            } else {
                *(res) = 0;
            }
        }
    }
    return;
}

int main() {
    int res;
    int *pointer_to_res = &res;
    int i;
    int j;
    int k;
    int idx;
    int jdx;
    int kdx;
    char print;
    int left = 0;
    int center = 0;
    int right = 1;
    rule_application(left, center, right, pointer_to_res);
    if (res == 1) {
        print = '1';
    } else {
        print = '0';
    }
    putchar(':');
    putchar(print);
    putchar(10);
    return 0;
}
