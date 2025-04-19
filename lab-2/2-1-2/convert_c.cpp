#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_case(char* a){
    for (int i = 0; true; i++){
        char character = a[i];
        int ascii_num = int(character);

        if (character == '\0'){
            break;
        }
        else if (ascii_num >= 97){
            a[i] = char(ascii_num - 32);
        }
        else{
            a[i] = char(ascii_num + 32);
        }
    }
}

int main(){
    char input[100];

    while (true){
        char *input;       
        input = (char *)malloc(1024 * sizeof(char));
        scanf("%s", input);
        input = (char *)realloc(input, strlen(input) + 1); 

        for (int i = 0; true; i++){
            if (i == 0 && strcmp(input, "exit") == 0){
                return 0;
            }
            int ascii_num = int(input[i]);
            if (input[i] == '\0'){
                break;
            }
            else if (ascii_num < 65 || ascii_num > 122 || (ascii_num > 90 && ascii_num < 65)){
                printf("Error: Wrong input!\n");
                return 0;
            }
        }

        convert_case(input); 
        printf("%s\n", input);
    }

    return 0;
}
