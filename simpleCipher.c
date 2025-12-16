# include <stdio.h>
# include <ctype.h>
# include <string.h>

void swapSection(char* i, char * p1, char * p2) {
    char tmp = '0';
    while (p1 != p2) {
        tmp = toupper(*p1);
        *p1 = toupper(*p2);
        *p2 = tmp;
        p1++;
        if (p1 == p2) { break; }
        p2--;
    }
    tmp = toupper(*p1);
    *p1 = toupper(*p2);
    *p2 = tmp;
}

void encode(char * message) {
    char * i = message;
    char * start = message;
    char * p1 = message;
    char * p2 = message;

    while (*i != '\0') {
        if (!isalpha(*i)){
            if (*i=='_') {
                *i = ' ';
            }
            if (p1 != i) {
                p2 = i;
                p2--;
                swapSection(i, p1, p2);
            }
            p1 = i;
            p1++;
        }
        i++;
    }
    if (p1 != i) {
        p2 = i;
        p2--;
        swapSection(i, p1, p2);
    }
}

void main() {
    int q = 0;
    char m[100];
    char * pm = m;

    for (q==0; q>=0; q++) {
        if (q==0) {
            printf("Enter a message (use underscores for spaces, type 'quit' to exit): ");
        } else { 
            printf("Enter another message (or type 'quit' to exit):"); 
        }
        scanf("%s", pm);
        if (strcmp("quit", m) == 0) {
            q = -1;
            break;
        }
        encode(m);
        printf("\nEncoded message: %s \n\n", pm);
    }
}