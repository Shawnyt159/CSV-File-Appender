#include <stdio.h> 
#include <time.h>
#include <unistd.h>

void Append_To_End_Of_File(FILE *origional, FILE *second_file, FILE *new_file);

int main(int argc, char* argv[]){
    clock_t begin = clock();
    
    // opening the origional file. 
    char* origional_file = argv[1];
    char* second_file_name = argv[2];
    char* new_file_name = argv[3];
    if(access(origional_file, F_OK) == 0){
        FILE *fp = fopen(origional_file, "r");
        FILE *second_file = fopen(second_file_name, "r");
        FILE *new_file = fopen(new_file_name, "w");

        //File could not open.
        if(second_file == NULL){
            printf("Error opening %s", second_file_name);
        }
        
        //File was opened, and now appending. 
        Append_To_End_Of_File(fp, second_file, new_file);

    }
    else{
        printf("Origional file does not exist.");
    }

    // End of program prints time.
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);
    return 0;
}

void Append_To_End_Of_File(FILE *origional, FILE *second_file, FILE *new_file){
    while(1){
        char character = fgetc(origional);
        if(character == EOF){
            break;
        }
        fprintf(new_file, "%c", character);
    }
    while(1){
        char character = fgetc(second_file);
        if(character == EOF){
            break;
        }
        fprintf(new_file, "%c", character);
    }
}