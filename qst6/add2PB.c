#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> '

void add2PB(char *firstName, char *lastName, char *phone) 
{ 
    FILE *fp = fopen("phonebook.txt", "a");
    if (fp == NULL) 
    { 
        perror("Error opening file"); exit(EXIT_FAILURE);
         }
          if (lastName != NULL)
           {
             fprintf(fp, "%s %s,%s\n", firstName, lastName, phone); 
             } 
             else { 
                fprintf(fp, "%s,%s\n", firstName, phone); 
                } 
                fclose(fp); 
                }
int main(int argc, char *argv[]) { 
       if (argc < 3 || argc > 4) 
     { 
        fprintf(stderr, "Usage: %s <first_name> [<last_name>] <phone>\n", argv[0]);
        exit(EXIT_FAILURE); 
    }
     if (argc == 4) 
     { 
        //If last name is provided 
        add2PB(argv[1], argv[2], argv[3]); 
        } 

        else {
             // If last name is not provided 
             add2PB(argv[1], NULL, argv[2]); 
            } return 0; 
            
    }