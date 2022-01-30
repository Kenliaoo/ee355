#include <stdio.h>
#include <stdlib.h>
int Count(char str[], int n){
    int wordCount = 1;
    for(int i = 0; i < n; i++){
        if(str[i] == ' ' && str[i+1] != ' '){
            wordCount++;
        }
    }
    return wordCount;
}

int main(){
    int size = 100;
    char str[size];
    FILE *in_file  = fopen("in.txt", "r"); // read only 
    FILE *out_file = fopen("out.txt", "w");
    if (in_file == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    while (fgets(str, size, in_file))
        //printf("%s\n", str);
    fclose(in_file);
    // printf("enter string:");
    // fgets(str, size, stdin);
    int word = Count(str, size);
    fprintf(out_file, "number of words:%d", word);
    fclose(out_file);
    return 0;
}