int main() {

	FILE *originalFile; // 2 files, the original message and the encoded message

	unsigned int numChars, frequencies[NUM_CHARS];

	// Open the original file
	originalFile = fopen("test.txt", "r");

	// Read the file and determine the frequencies
	numChars = get_freq(originalFile, frequencies);
	printf("test");
	printf("ch: %c", numChars);
	fclose(originalFile);
	printf("test");

}
