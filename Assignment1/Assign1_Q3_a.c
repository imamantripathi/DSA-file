
// Question 3. Create a structure/class for a group of 50 students holding data for their Regn no., Name, Branch, CGPA
// a) Call linear search function to display data of student with a particular Regn no.
// b) Call bubble sort function to arrange data of students according to Regn
// c) Apply binary search on the above output (part b) to display data of a student with a particular Regn no.
// d) Use and modify Insertion sort logic to arrange data of students in descending order of CGPA .1

#include <stdio.h>
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

int rn= 0; int k =0;
printf("Enter Regn number to search student record:\n");
scanf("%d",&rn);

for(i=0;i<n;i++)
{
if(s[i].regn==rn)
{
k=i;//for finding position of student

printf("\n Record found at position no %d \n",k+1);
printf("\tName:%s\n ",s[k].name);
printf("\t Regn number: %d\n",s[k].regn);
printf("\tBranch:%s\n ",s[k].branch);
printf("\t CGPA: %.1f\n\n",s[k].cgpa);
}
}
return 0;
}