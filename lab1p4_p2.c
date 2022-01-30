#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int Count(char str1[], int n){
    int wordCount = 0;
    for(int i = 0; i < n; i++){
        if(str1[i] == ' ' && str1[i+1] != ' '){
            wordCount++;
        }
    }
    return wordCount;
}

int main()
{
    int size = 100;
    char str1[size];
    char newString[20][20]; 
    int i,j,k,ctr,cnt;

    FILE *in_file  = fopen("in.txt", "r"); // read only 
    FILE *out_file = fopen("out_improved.txt", "w");
    if (in_file == NULL || out_file == NULL){
        printf("Cannot open file \n");
        exit(0);
    }
    while (fgets(str1, size, in_file))
        //printf("%s\n", str1);

    fclose(in_file);
    // printf(" Input  a string : ");
    // fgets(str1, sizeof str1, stdin);    
 
    j=0; ctr=0;
    for(i=0;i<=(strlen(str1));i++){
        if(isalpha(str1[i]) == 0){
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, initialize index to 0
        }else{
            newString[ctr][j]=str1[i];
            j++;
        }
    }

    fprintf(out_file, "duplicated words are :\n");
    
    cnt = 0;
    for(i = 0; i < ctr; i++){
        for(j = 0; j < ctr; j++){
            if(strcmp(newString[i], newString[j]) == 0){
                cnt++;
            }
        }
        if(cnt > 1){
            fprintf(out_file, "%s\n", newString[i]);
        }
        cnt = 0;
    }

    int word = Count(str1, size);
    fprintf(out_file, "number of words:%d", word);
    fclose(out_file);
    return 0;
}