
//struct "Structure"  play ground with C language
//It's the beginning

#include <stdio.h>
#include <stdlib.h>

#define MAX_L 100

void readString( char *str){
  int i = 0;
  char ch;
  while((ch = getchar()) != '\n' && ch != EOF){
    str[i++] = ch;
    if(i > MAX_L - 1) break;
  }
  str[i] = '\0';
}

struct Book{
  char name[MAX_L];
  size_t pages;
  char author[MAX_L];
  char genre[MAX_L];
};

struct Book createBook(struct Book *b1){
  
  printf("Enter the book name:\n");
  fflush(stdout);
  readString(b1->name); //we can do samething with fgets also
  
  printf("Enter the pages book contains:\n");
  fflush(stdout);
  scanf("%zu", &b1->pages);
  getchar();

  printf("Enter the author's name: ");
  fflush(stdout);
  readString(b1->author);

  printf("Enter the genre: ");
  fflush(stdout);
  readString(b1->genre);

  return *b1;
  // we don't have to return it because we are using pointer so anything change here also affect the original
  //for that we have to make function void 
}

int main(){
  size_t numBook;
  printf("How many books you wanna make?\n");
  fflush(stdout);
  scanf("%zu", &numBook);
  getchar(); //for to consume newline
  struct Book *Books = malloc(numBook * sizeof(struct Book));
  if(Books == NULL){
    printf("Memory allocation for Books failed!\n");
    return 1;
  }
  for(size_t i = 0; i < numBook; i++){
    createBook(&Books[i]);
  }

  printf("\nBooks Details:\n");
  for(size_t i = 0; i < numBook; i++){
     size_t indexBook = i + 1;
     printf("Detail of %zu Book\n", indexBook);
     printf("Book Name: %s\n", Books[i].name);
     printf("Pages: %zu\n", Books[i].pages);
     printf("Author: %s\n", Books[i].author);
     printf("Genre: %s\n", Books[i].genre);
   }

  free(Books);
  return 0;
}
