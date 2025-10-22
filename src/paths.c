#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>
#include <stdarg.h>
#include "../include/paths.h"


#ifndef MAX_PATH_LENGTH
#define MAX_PATH_LENGTH 10
#endif


#ifndef MAX_PATHS
#define MAX_PATHS 1024
#endif

void path_join(char buffer[MAX_PATH_LENGTH], int num_paths, ...) {
  va_list paths; // variable length array of args
  va_start(paths, num_paths); // init va_list 
  int curr_len; // concat all string paths
  struct stat statbuf;

  for (int i=0; i<num_paths; i++) {
    char *current_word = va_arg(paths, char*);
    curr_len = strlen(current_word);
    char cleaned_word[curr_len];
    remove_trailing_slashes(current_word, cleaned_word);
    strcat(buffer, cleaned_word);
    if (i != num_paths-1) { strcat(buffer, "/"); }
  }

  if (stat(buffer, &statbuf) == -1) {
    printf("Path %s not found.\n", buffer);
    perror("stat");
  }
  
  // add a training backslash if the path points to a directory
  if (S_ISDIR(statbuf.st_mode)) {
    strcat(buffer, "/");
  }
}




void remove_trailing_slashes(char *input_string, char *output_string) {
  int len_input = strlen(input_string);
  int i = len_input-1;

  while (input_string[i] == '/' || input_string[i] == '\\') {
    i--;
  }
  
  strncpy(output_string, input_string, i+1);
  output_string[i+1] = '\0';
}




bool check_exists(char *path) {
  struct stat file_info;
  if (stat(path, &file_info) == -1){
    return false;
  }
  
  return true;
}
