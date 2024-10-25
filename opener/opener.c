#include <stdio.h>
#include <string.h>

void display_Opener_Text() {
  FILE *OpenerTextFile = fopen("opener/opener.txt", "r");

  if (OpenerTextFile == NULL) {

    puts("Failed to open opener");
    return;
  }

  char buffer[128];
  while (fgets(buffer, sizeof(buffer), OpenerTextFile) != NULL) {

    printf("%s", buffer);
  }
  
  fclose(OpenerTextFile); 
}