void ahoj(int number, char character) {
	if (number < 10) {
		putchar('a');
	} else {
		putchar('b');
	}
	putchar('c');
	return;
}

int main() {
	int a;
	int pole[10];
	int var1;
	for (int i = 0; i < 20; i = i + 1) {
		ahoj(i, 'a');
	}
	int var = *(pole);
	int *var2 = &var1;
	int var3 = -var1;
	int var4 = *(var1);
	*(var) = 2;
	int *var5 = &var2;
	return 0;
}
