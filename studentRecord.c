
//Define a struct Student with fields name, rollNumber, marks (array of 3 subjects), and average.
//Write a program to input details for 5 students, calculate their average marks, and print the student with the highest average.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void readString(char *str){
  int i = 0;
  char ch;
  while((ch = getchar()) != '\n' && ch != EOF){
    str[i++] = ch;
    if(i > MAX_LENGTH - 1) break;
  }
  str[i] = '\0';
}

struct Subjects{
  char name[MAX_LENGTH];
  size_t marks;
};

struct Student{
  char name[MAX_LENGTH];
  size_t rollNumber;
  struct Subjects *subject;
  size_t numOfSub;
  float average;
};

void createSubject(struct Subjects *sub){
  printf("Name of subject:\n");
  fflush(stdout);
  readString(sub->name);

  printf("Enter the marks get by student in %s:\n", sub->name);
  fflush(stdout);
  scanf("%zu", &sub->marks);
  getchar();
}

void createStudent(struct Student *s){
  
  printf("Name:\n");
  fflush(stdout);
  readString(s->name);

  printf("Roll_number:\n");
  fflush(stdout);
  scanf("%zu", &s->rollNumber);
  getchar();
  
  printf("How many subject student have?\n");
  fflush(stdout);
  scanf("%zu", &s->numOfSub); 
  getchar();

   s->subject = malloc(s->numOfSub * sizeof(struct Subjects));
  if(s->subject == NULL){
    printf("Memory allocation for subject failed!\n");
    return;
  }
  for(size_t i = 0; i < s->numOfSub; i++){
    size_t index = i + 1; 
    printf("Enter the detail for %zu subject:\n", index);
    fflush(stdout);
    createSubject(&s->subject[i]);
  }
  
  size_t totalMarks = 0;
  for(size_t i = 0; i < s->numOfSub; i++){
     totalMarks += s->subject[i].marks;   
  }
  s->average =(float)(totalMarks)/(s->numOfSub); 
}

int main(){
  size_t numOfStd;
  printf("How many students details you wanna insert?\n");
  fflush(stdout);
  scanf("%zu", &numOfStd);
  getchar();
  struct Student *st = malloc(numOfStd * sizeof(struct Student));
  if(st == NULL){
    printf("Memory allocation for students failed!\n");
    return 1;
  }
  for( size_t i = 0; i < numOfStd; i++){
    size_t index = i + 1; 
    printf("Enter the detail for %zu student:\n", index);
    fflush(stdout);
    createStudent(&st[i]);
  }
  //for to print the detail of each students
  printf("Here is the details of Students you just filled:\n");
  float highest = 0;
  char bestStudent[MAX_LENGTH];
  for( size_t i = 0; i < numOfStd; i++){
    size_t index = i + 1; 
    printf("Detail for %zu student", index);
    printf("Name: %s\n", st[i].name);
    printf("Roll_Number: %zu\n", st[i].rollNumber);
    for(size_t j = 0; j < st[i].numOfSub ; j++){
      printf("Subject: %s = %zu. \n", st[i].subject[j].name, st[i].subject[j].marks);
    }
    if(i == 0 || highest < st[i].average){
      highest = st[i].average;
      size_t len = strlen(st[i].name);
      strncpy(bestStudent, st[i].name , len);
      bestStudent[len] = '\0';
    } 
  }
  printf("The best student is %s with best average %.02f\n", bestStudent, highest);
  
  for(size_t i = 0; i < numOfStd; i++) {
     free(st[i].subject); // Free the dynamically allocated memory for subject
    }
  free(st);
  return 0;
}
