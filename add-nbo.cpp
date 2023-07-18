#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: add-nbo <file1> <file2>\n");
        return 0;
    }

    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening file(s).\n");
        return 0;
    }

    uint32_t num1, num2;
    size_t read1 = fread(&num1, sizeof(uint32_t), 1, file1);
    size_t read2 = fread(&num2, sizeof(uint32_t), 1, file2);

    if (read1 != 1 || read2 != 1) {
        printf("Error reading file(s).\n");
        return 0;
    }

    num1 = ntohl(num1);
    num2 = ntohl(num2);

    fclose(file1);
    fclose(file2);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, num1 + num2, num1 + num2);

    return 0;
}

