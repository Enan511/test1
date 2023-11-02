#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

void printProp(struct stat stats);

int main()
{
    char path[100];
    struct stat stats;

    printf("Source path for the file: ");
    scanf("%s", path);


    if (stat(path, &stats) == 0)
    {
        printProp(stats);
    }
    else
    {
        printf("Can't find the file.\n");
        printf("The file '%s' may not exist.\n", path);
    }

    return 0;
}



void printProp(struct stat stats)
{
    struct tm dt;
    printf("\nFile access: ");
    if (stats.st_mode & R_OK)
        printf("read ");
    if (stats.st_mode & W_OK)
        printf("write ");
    if (stats.st_mode & X_OK)
        printf("execute");

    printf("\nFile size: %d bytes.", stats.st_size);

    dt = *(gmtime(&stats.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900,
           dt.tm_hour, dt.tm_min, dt.tm_sec);

    dt = *(gmtime(&stats.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900,
           dt.tm_hour, dt.tm_min, dt.tm_sec);

}