
//Short hand if else
#include <stdio.h>

int main() {
  int time = 20;
  (time < 21) ? printf("Good day.") : printf("Good evening.");
  return 0;
}
/*
above code is exactly same as
#include <stdio.h>

int main() {
  int time = 20;
  if (time < 18) {
    printf("Good day.");
  } else {
    printf("Good evening.");
  }
  return 0;
}
*/