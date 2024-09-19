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
