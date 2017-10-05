#include <stdio.h>

typedef struct StudentRec
{
        long int ID;
        char name[20];
} Student;
 
void printStudent(Student* s)
{
        printf("\n ID : %ld \n Name: %s \n\n", s->ID, s->name);
        return;
}
 
void readStudent(Student* s)
{
        printf("Enter ID: ");
        scanf("%ld", &s->ID);
        printf("Enter name: ");
        scanf("%19s", &s->name);
        return;
}
int main()
{
  Student *temp = NULL;
 
  readStudent(temp);    /* line 27 */
  printStudent(temp);
 
  return 1;
}

