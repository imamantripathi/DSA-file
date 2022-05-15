// Question 3. Create a structure/class for a group of 50 students holding data for their Regn no., Name, Branch, CGPA
// a) Call linear search function to display data of student with a particular Regn no.
// b) Call bubble sort function to arrange data of students according to Regn
// c) Apply binary search on the above output (part b) to display data of a student with a particular Regn no.
// d) Use and modify Insertion sort logic to arrange data of students in descending order of CGPA .1

#include <stdio.h>
void insertionSortDesc();
struct student
{
char name[50];
int regn;
float cgpa;
char branch[30];
} s[100];

int main()
{
int i,n;
struct student s[100];

printf("Enter total of students:\n");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("\n Enter information of student %d:\n",i+1);
printf("Enter name: ");
scanf("%s", s[i].name);
printf("Enter Branch: ");
scanf("%s", s[i].branch);
printf("Enter Regn number: ");
scanf("%d", &s[i].regn);



printf("Enter CGPA: ");
scanf("%f", &s[i].cgpa);
}
insertionSortDesc(s, n);

printf("Displaying Information:\n");
printf("\tName  \tBranch \tRegn_Number \tCGPA\n");
for(i=0;i<n;i++)
{
printf("\t%s \t%s \t%d \t\t%.1f \n",s[i].name,s[i].branch,s[i].regn,s[i].cgpa);
}

return 0;
}

void insertionSortDesc(struct student stud_list[100], int s)
{
    for (int step = 1; step < s; step++) {
    int key = stud_list[step].cgpa;
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key > stud_list[j].cgpa && j >= 0) {
      stud_list[j + 1].cgpa = stud_list[j].cgpa;
      --j;
    }
    stud_list[j + 1].cgpa = key;
  }
}