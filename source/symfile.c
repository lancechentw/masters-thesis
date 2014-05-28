#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "s2e.h"

int main(int argc, char** argv) {
    char* filenamestr;
    unsigned int symbolic_start = 0;
    unsigned int symbolic_offset = 0;

    if (argc == 2) {
        s2e_message("Target: the whole file");
        filenamestr = argv[1];
    }
    else if (argc == 4) {
        s2e_message("Target: partial");
        filenamestr = argv[1];
        symbolic_start = atoi(argv[2]);
        symbolic_offset = atoi(argv[3]);
    }
    else {
        s2e_warning("Wrong arguments");
        exit(1);
    }

    int file = open(filenamestr, 2, 0600);
    if (file < 0) {
        s2e_warning("file open failed");
        exit(1);
    }

    struct stat buffer;
    int status = fstat(file, &buffer);

    if (argc == 2) {
        symbolic_start = 0;
        symbolic_offset = buffer.st_size;
    }

    char* addr = mmap(0, buffer.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);

    char* content = (char*)malloc(buffer.st_size);
    memcpy(content, addr, buffer.st_size);

    if (addr == (char*)MAP_FAILED) {
        s2e_warning("mmap failed");
        s2e_warning(strerror(errno));
        exit(1);
    }

    s2e_make_concolic(addr + symbolic_start, symbolic_offset, "symfile");

    close(file);
    return 0;
}
