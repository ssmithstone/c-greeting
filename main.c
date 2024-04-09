#include <stdio.h>
#include <time.h>

void print_greeting(int argc, char *const *argv);

void print_current_time();

int main(int argc , char ** argv) {

    print_current_time();
    print_greeting(argc, argv);
    return 0;
}

void print_current_time() {
    time_t now; // create var to store time in
    time(&now); // store the time into the address of now, example of function that accepts pointer to modify value. (non-pure function)
    printf("The computer thinks it's : %ld\n" , now); // prints the (number of seconds )epoc time since 1/1/1970
    printf("Formatted time : %s\n" , ctime(&now)); // default formatted time.

}

void print_greeting(int argc, char *const *argv) {
    if(argc < 2){
        const char * name = "Joe Blogs";
        printf("Hello, %s\n" , name );
    }
    else {
        printf("Hello, %s\n" , argv[1]);
    }
}
