#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define CELL_COUNT 30000




int main(int argc, char** argv) {

    if(argc != 2) {
        printf("Usage: %s <brainfuck-source>\n", argv[0]);
        exit(-1);
    }


    // Read contents of file into memory
    int fd = open(argv[1], O_RDONLY);

    if(fd==-1) {
        printf("Something is wrong with the File!\n");
        exit(-1);
    }

    struct stat a;

    fstat(fd, &a);

    char* filestr = (char*)mmap(NULL, a.st_size, 
                        PROT_READ,
                        MAP_PRIVATE, fd, 0);

    close(fd);

    char cells[CELL_COUNT];

    for(int i=0; i<CELL_COUNT; ++i) {
        cells[i] = 0;
    }

    int curr_cell = 0;

    int jump_back = 0;

    int cell_tmp = 0;
    
    for(int i=0; i<a.st_size; i++) {
        switch(filestr[i]) {
            case '>':
                curr_cell += 1;
            break;
            case '<':
                curr_cell -= 1;
            break;
            case '+':
                cells[curr_cell] += 1;
            break;
            case '-':
                cells[curr_cell] -= 1;
            break;
            case '.':
                printf("%c", cells[curr_cell]);
            break;
            case ',':
                //Input, habe ich noch keinen Plan
            break;
            case '[':
                cell_tmp = curr_cell;
                jump_back = i+1;
            break;
            case ']':
                if(cells[cell_tmp]>0) {
                    i = jump_back-1;
                }
            break;
        }
    }
}