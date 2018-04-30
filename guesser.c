#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSIZE 128

int main(int argc, const *argv[])
{ 
  char *cmd = "echo Bob 123|./questioner";
  char buf[BUFSIZE];
  char line[128];
  FILE *f;
  
 
  if((f = popen(cmd, "r")) == NULL) {
    printf("Error opening pipe.");
    return -1;
  }
 
  while(fgets(buf, BUFSIZE, f) != NULL) {
    printf("%s", buf);
    sprintf(line, buf);
    if (strcmp(line, "What is your name?\n") == 0){
     printf("Bob\n");
    }
    else if (strcmp(line, "What is the magic number, Bob?\n") == 0){
      printf("123\n");
    }
    else if (strcmp(line, "SUCCESS\n") == 0){/*do nothing*/}
    else if (strcmp(line, "TO HIGH\n") == 0){/*do nothing*/}
    else if (strcmp(line, "TO LOW\n") == 0) {/*do nothing*/}
    else {
      printf("???\n");
      break;
    }
  }

  pclose(f);
  
  return 0;
}
