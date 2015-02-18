#include <stdio.h>
#include <stdlib.h>  /* For exit() function */

void writeToFile(const char *filepath, const char *data){
	FILE *fp = fopen(filepath, "a");
	if(fp==NULL){				// Checks that there is a filepath
      printf("Error!");
      exit(1);
    }
	
	fputs (data, fp);			// Adds data to file
	fputs ("\n", fp);			// Adds new line
	fclose(fp);
}


/*int writeToFile1(string myfile, string mytext)
{
   char c[1000];
   FILE *fptr;
   /*printf("Enter a sentence:\n");
   gets(&c);
   printf("du skrev: ");
   printf(&c);
   while(1){};
   fptr=fopen("program.txt","a");
   if(fptr==NULL){
      printf("Error!");
      exit(1);
   }
   printf("Enter a sentence:\n");
   gets(c);
   fprintf(fptr,"%s",c);
   fprintf(fptr,"%s","\n");
   fclose(fptr);
   return 0;
   
   printf("HER");
   fptr = fopen("program.txt","r");
   while(1)
   {
      c = fgetc(fptr);
      if( feof(fptr) )
      {
          break ;
      }
      printf("%c", c);
   }
   fclose(fptr);
   return(0);

   return 0;
}*/