/* Show the CGI (Common Gateway Interface) environment variables */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Print a basic HTTP header. */

static void print_http_header (const char * content_type)
{
    printf ("Content-Type: %s\n\n", content_type);
    printf("<link rel='stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css' integrity='sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z' crossorigin='anonymous'>");
}

void print_file(FILE *f){
    int c;
    if (f){
        while((c = getc(f)) != EOF)
            putchar(c);
        fclose(f);
    }
}
 
int main (){
    print_http_header ("text/html");
   
    FILE* table = fopen("/usr/lib/cgi-bin/Source/table.html", "r");
    print_file(table);

    char *content = getenv("CONTENT_LENGTH");

    if(content)
    {
        int len = atoi(content);
        char input[len + 1];

        printf("<p> lengte: %s </p>",content);
        fgets(input,sizeof(input), stdin);
        printf("<p> input data string: %s </p>", input);

        char *ptr = strtok(input,"&=");
        ptr = strtok(NULL,"&=");
        char *data = ptr;
        ptr = strtok(NULL,"&=");
        ptr = strtok(NULL,"&=");
        char *data2 = ptr;
        ptr = strtok(NULL,"&=");
        ptr = strtok(NULL,"&=");
        char *data3 = ptr;


        system("truncate -s-2 /var/www/html/data.json");

        FILE *json = fopen("/var/www/html/data.json", "a");
        fprintf(json, ",\n\t{\n\t\t\"data\": \"%s\",\n\t\t\"data2\": \"%s\",\n\t\t\"data3\": \"%s\"\n\t}\n]",data,data2,data3);

    }
    
    return 0;
}