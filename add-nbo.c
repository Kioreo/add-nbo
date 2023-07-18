#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>
#include <stdlib.h>

void usage() {
    printf("%s", "syntax : add-nbo <file1> <file2>");
    exit(-1);
}

int f_toNum(char* f) {
    FILE *file;
    uint32_t value;

    file = fopen(f, "rb");
    if (file == NULL) {
        printf("Couldn't open file.\n");
        exit(-1);
    }
    fread(&value, sizeof(unsigned int), 1, file);
    return ntohl(value);
}

int main(int argc, char* argv[]) {
    if(argc != 3){
        usage();
    }
    
    int f1 = f_toNum(argv[1]);
    int f2 = f_toNum(argv[2]);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", f1, f1, f2, f2, f1+f2, f1+f2);

    return 0;
}
