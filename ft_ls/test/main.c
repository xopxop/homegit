#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

struct tm *foo;
struct stat attrib;

int main() {
   stat("file.txt", &attrib);
   foo = gmtime(&(attrib.st_mtime));
   printf("Year: %d\n", foo->tm_year);
   printf("Month: %d\n", foo->tm_mon);
   printf("Day: %d\n", foo->tm_mday);
   printf("Hour: %d\n", foo->tm_hour);
   printf("Minute: %d\n", foo->tm_min);
   return 0;
}
