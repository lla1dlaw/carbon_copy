#ifndef _PATHS

#define _PATHS
#define MAX_PATH_LENGTH 1024
#define MAX_PATHS 10

bool check_exists(char *path);
void remove_trailing_slashes(char *input_string, char *output_string);
void path_join(char buffer[MAX_PATH_LENGTH], int num_paths, ...);

typedef struct node {
  char path[MAX_PATH_LENGTH];
  struct node *next;
} Node;


typedef struct {
  Node *start;
  Node *end;
  Node *current;
  Node paths[MAX_PATHS]; // stores all the Node pointers for interation purposes
} Paths;

#endif
