#include <stdio.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Usage: %s <file 1> <file 2>\n", argv[0]);
		return 0;
	}

	uint32_t first_file, second_file;
	FILE *file = fopen(argv[1], "r");
	fread(&first_file, sizeof(uint32_t), 1, file);
	fclose(file);

	file = fopen(argv[2], "r");
	fread(&second_file, sizeof(uint32_t), 1, file);
	fclose(file);

	first_file = htonl(first_file);
	second_file = htonl(second_file);

	printf ("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", first_file, first_file, second_file, second_file, first_file + second_file, first_file + second_file);
}
