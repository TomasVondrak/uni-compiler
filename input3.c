void ahoj(int number, char character) {
	if (number < 10) {
		return;
	}
	// return; // pokud dam tohle, tak funguje -> musi končit return
}

void papa() {
	return;
}

int main() {
	for (int i = 0; i < 20; i = i + 1) {
		ahoj(i, 'a');
	}
	return 0;
}
