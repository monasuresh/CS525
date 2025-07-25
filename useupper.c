#include<unistd.h>

#include<stdio.h>

#include<stdlib.h>



int main(int argc, char* argv[]) {

   char *filename;

   

   if (argc != 2) {

      fprintf(stderr, "usage: useupper file\n");

      exit(1);

   }

   

   filename = argv[1];

   

   //use execl to call upper

   if (!freopen(filename, "r", stdin)) {

      fprintf(stderr, "could not redirect stdin from file %s\n", filename);

      exit(2);

   }

   

   execl("./upper", "upper", 0, NULL);



   //if there is no error, the following lines are not executed

   perror("could not execl ./upper");

   exit(3);

}
