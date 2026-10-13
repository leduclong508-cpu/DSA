#include<stdio.h>
#include<string.h>

#define  MAX_NOTES 100
#define MAX_TITLE 50
#define MAX_CONTENT 500
#define FILE_NAME "notes.dat"

typedef struct {
    int id;
    char title[MAX_TITLE];
    char content[MAX_CONTENT];
}
Note;

Note notes[MAX_NOTES];
int note_count = 0;
int next_id = 1;

void clear_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void remove_newline(char *str){
    str[strcspn(str, "\n")] = '\0';
}

void load_notes(){
    FILE *file = fopen(FILE_NAME, "rb");
    if(file){
        
    }
}