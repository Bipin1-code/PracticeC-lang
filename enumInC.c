

/*
  What is Enum?
  An enum short for enumeration is a user-defined data type that consists of a set of named interger constants. It allows you to create meaningful names for interger values, making your code more readable and maintainable.

  Key Characteristics of Enums:
  1. Named constants: Each enum value has a name and an associated integer value
  2. Type safety: Enums create a distinct type for the set of values.
  3. Default numbering: Values start from 0 and increment by 1 if not explicitly specified
  4. Readability: Makes code more self-documenting

  Enum syntax in C:
  enum enum_name{
  value1, value2, value3,
  //...
};
 */

#include <stdio.h>

//Define the enum and string mapping in one place
#define TRAFFIC_LIGHTS \
  X(RED, 1) \
  X(YELLOW, 2) \
  X(GREEN, 3)

//Generate the enum
#define X(name, value) name = value,
enum trafficLights {TRAFFIC_LIGHTS};
#undef X

//Generate the string array
#define X(name, value) [name] = #name,
const char* trafficLight[] = {TRAFFIC_LIGHTS};
#undef X

typedef enum Days{
  Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
} Days;

typedef enum StatusCodes{
  SUCCESS = 200,
  BAD_REQUEST = 400,
  UNAUTHORIZED = 401,
  NOT_FOUND = 404,
  INTERNAL_ERROR = 500
} StatusCodes;

typedef enum FilePermissions{
  Read = 1,
  Write = 2,
  Execute = 4
} FilePermissions;

void day_feel(enum Days feel){
  switch(feel){
  case Monday:
    printf("It is what it is!!\n");
    break;
  case Tuesday:
    printf("It's not a day!\n");
    break;
  case Wednesday:
    printf("Still 2 days to servive!\n");
    break;
  case Thursday:
    printf("Why it's takes too long!\n");
    break;
  case Friday:
    printf("I have to run asap!\n");
    break;
  case Saturday:
    printf("It's a day to live!\n");
    break;
  case Sunday:
    printf("Prepare your stuff and sleep.\n");
    break;
  default:
    printf("Not a day!!\n");
  }
}

int main(){
  
  Days today = Wednesday;
  StatusCodes response = SUCCESS;
  printf("Today is day number: %d\n", today);

  if(today == Wednesday){
    printf("Status: %d \n", response);
  }

  day_feel(today);
  day_feel(Saturday);

  int myPermissions = Read | Write;

  printf("My permissions: %d\n", myPermissions);

  if(myPermissions & Read){
    printf("Read permission granted\n");
  }
  if(myPermissions & Write){
    printf("Write permission granted.\n");
  }
  if(myPermissions & Execute){
    printf("Execute permission granted.\n");
  }else{
    printf("execute permission denied.\n");
  }

  enum trafficLights light = RED;
  printf("Light: %s (%d)\n", trafficLight[light], light);

  enum trafficLights lights[] = {YELLOW, GREEN};
  for(int i = 0; i < 2; i++){
    printf("Light %d: %s\n", lights[i], trafficLight[lights[i]]);
  } 
  return 0;
}
