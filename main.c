#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_greeting(int argc, char *const *argv);

void print_current_time(const time_t* now);

void print_current_time_using_formating_func(const time_t* now){
    struct tm *clock;
    clock = localtime(now);
    char time_string[64];
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", clock);
    printf("Date formatted using strftime %s\n" , time_string);
}

int main(int argc , char ** argv) {
    time_t now; // create var to store time in
    time(&now); // store the time into the address of now, example of function that accepts pointer to modify value. (non-pure function)

    print_current_time(&now);
    print_current_time_using_formating_func(&now);
    print_greeting(argc, argv);
    return 0;
}





void print_current_time(const time_t* now) {
    printf("The computer thinks it's : %ld\n" , *now); // prints the (number of seconds )epoc time since 1/1/1970
    printf("Formatted time : %s\n" , ctime(now)); // default formatted time.

    struct tm *clock;
    clock = localtime(now);
    puts("Time details:");
    printf(" Day of the year: %d\n", clock->tm_yday);
    printf(" Day of the week: %d\n", clock->tm_wday);
    printf("            year: %d\n", clock->tm_year+1900);
    printf("           month: %d\n", clock->tm_mon+1);
    printf("Day of the month: %d\n", clock->tm_mday);
    printf("            hour: %d\n", clock->tm_hour);
    printf("          minute: %d\n", clock->tm_min);
    printf("         seconds: %d\n", clock->tm_sec);


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
