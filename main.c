#include <stdio.h> 
#include <time.h>

void Append_To_End_Of_Origional_File(FILE *Origional, FILE *second_file);
void Write_To_Output_File(FILE *origional, FILE *second_file, FILE *new_file);

int main(int argc, char* argv[]){
    clock_t begin = clock();
    
    if(argc == 4){
        // opening the files.
        char* origional_file_name = argv[1];
        char* second_file_name = argv[2];
        char* new_file_name = argv[3];
        FILE *origional_file = fopen(origional_file_name, "r");
        FILE *second_file = fopen(second_file_name, "r");
        FILE *new_file = fopen(new_file_name, "w");

        //File could not open.
        if(origional_file == NULL){
            printf("Error opening %s", origional_file_name);
        }
        else if(second_file == NULL){
             printf("Error opening %s", second_file_name);
        }

        //Files were opened and now writing to the new file.
        Write_To_Output_File(origional_file, second_file, new_file);
    }
    else if(argc == 3){
        char* origional_file_name = argv[1];
        char* second_file_name = argv[2];

        // Opening the files.
        FILE *origional_file = fopen(origional_file_name, "a");
        FILE *second_file = fopen(second_file_name, "r");

        if(origional_file == NULL || second_file == NULL){
            printf("Error opening %s", origional_file_name);
        }
        else if(second_file == NULL){
            printf("Error opening %s", second_file_name);
        }

        //Files were oppened and now appening the second file to the origional file. 
        Append_To_End_Of_Origional_File(origional_file, second_file);
    }
    
    // End of program prints time.
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);
    return 0;
}

void Append_To_End_Of_Origional_File(FILE *origional_file, FILE *second_file){
    fprintf(origional_file, "%c", '\n');
    while(1){
        char character = fgetc(second_file);
        if(character == EOF){
            break;
        }
        fprintf(origional_file, "%c", character);
    }
}


void Write_To_Output_File(FILE *origional, FILE *second_file, FILE *new_file){
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