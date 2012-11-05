
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct wordcount { char lastword[32]; int count; };

static char *sentences[] = {
    "test test test", 
    "one lazy fox jumped over the tree or whatever supercalifragilisticexfialidocious"
};

void count_words(char *str, struct wordcount *s)
{
    int i, n = 0;
    char *lastspace = str;

    for(i = 0; i < strlen(str); ++i) {
        if (str[i] == 0x20) {
            ++n;
            lastspace = &str[i];
        }
    }
    
    if (strlen(str))
        ++n;


    s->count = n;
    strncpy(s->lastword, lastspace, strlen(lastspace) + 1);
}

int main(int argc, char **argv)
{
   int i;

   for (i = 0; i < sizeof(sentences) / sizeof(*sentences); i++) {
       struct wordcount wc;

       count_words(sentences[i], &wc);

       printf("sentence: \"%s\", last word \"%s\", wordcount %d\n",
                sentences[i], wc.lastword, wc.count);
   }

   return 0;
}


