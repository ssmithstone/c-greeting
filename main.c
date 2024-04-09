#include <stdio.h>

int main(int argc , char ** argv) {
    if(argc < 2){
        const char * name = "Joe Blogs";
        printf("Hello, %s\n" , name );
    }
    else {
        printf("Hello, %s\n" , argv[1]);
    }
    return 0;
}
