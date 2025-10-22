#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "../include/paths.h"

#define MAX_PATH_LENGTH 1024
#define MAX_PATHS 10

int main(int argc, char** argv) {
  // check to make sure that files were provided
  if (argc <= 1) { printf("No file provided.\n"); }
  
  // vars
  char *filename = argv[1];  
  char pwd_buff[MAX_PATH_LENGTH];
  char full_path[MAX_PATH_LENGTH] = ""; // init to an empty string to prep for strcat
  
  // check to make sure that the path exists
  if (!check_exists(filename)) {
    perror("stat");
    exit(EXIT_FAILURE);
  }
  
  // store the full path in a var and add it to the array of paths
  getcwd(pwd_buff, MAX_PATH_LENGTH);
  path_join(full_path, 2, pwd_buff, filename);
  
  printf("Full Path: %s\n", full_path);

  return 0;
}






