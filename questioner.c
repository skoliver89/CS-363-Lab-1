#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const *argv[])
{
    FILE *fp;           //pointer to the file
    char line[256];     //where to store line data
    char *fileName;     //where to store file name
    char name[60];      //where to store inputed name
    int number = 12345; //where to store the magic number guessed
    int magicN = 0;     //where to store the int value of the stored magic number
    char words[10][10]; //where to store the words in a line
    int i, j, ctr;      //indexes used to find words
    
    
    fileName = "answers.txt";  //set the file name
    fp = fopen(fileName, "r"); //open the file
    
    printf("What is your name?\n");
    scanf("%s", name); //get user input for name
    printf("What is the magic number, %s?\n", name);
    scanf("%d", &number); //get user input for number
    
    if(fp == NULL) {
      printf("File Not Found: %s\n", fileName); //if file not found error out
      return -1; //Exit in error
    }
    
    while (fgets(line, sizeof(line), fp)) { //go line by line
      j = 0;  //index of where we are in the current word
      ctr= 0; //index of the current word
      //Word finder/spliter inspired by: https://www.w3resource.com/c-programming-exercises/string/c-string-exercise-31.php
      for(i=0;i<=(strlen(line));i++) {  //for each char in line
        if(line[i] == ' ' || line[i] == '\0') { //if the current char is null('\0') or a space
          words[ctr][j]='\0'; //assign the word as null ('\0')
          ctr++; //move to the next word
          j=0; //reset position in the word
        }
        else {  //if the char is not null
          words[ctr][j] = line[i]; //add the char to our current word in array of words
          j++; //move to the next char
        }
      }
      if (strcmp(name, words[0]) == 0) { //if we have the input name in the file
        magicN = atoi(words[1]);  //convert the stored number(word) to an int
        if (number == magicN) { //if the guessed number equals the stored number
          printf("SUCCESS\n");
        }
        else if (number > magicN) { //if the guessed number is greater-than the stored number
          printf("TOO HIGH\n");
        }
        else {  //else (if the guessed number is less-than the stored number)
          printf("TOO LOW\n");
        }
        fclose(fp); //close the file
        return 0; //Exit: OK
      }
    }
      
    printf("Name not Found.\n"); //scanned the whole answers file and didn't find the input name
    number = 12345; //return to defaul number value
    
    fclose(fp); //close the file
    
    return 0; //Exit: OK
}
