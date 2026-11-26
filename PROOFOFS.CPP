# include<stdio.h>
#include<string.h>
#define MAX 20
struct Skill
{
  char name[50];
  int demonstrated;
};
struct Project
{
  char projectName[100];
  char description[300];
  struct Skill skills[MAX];
  int skillCount;
};

void analyseSkills (struct Project *p)
{
  int i;
  printf("\n--- SKILL ANALYSIS---\n");
  for (i=0; i<p->skillCount; i++)
  {
    printf("\nSkill: %s",p->skills[i].name);
    if(p->skills[i].demonstrated == 1)
    {
      printf("\nStatus: Evindence Supported\n");
    }
    else
    {
      printf("\nStatus: Insuffficient Evidence\n");
    }
  }
}

void generateChallenge(struct Project *p)
{
  int i;
  printf("\n--- PROOF CHALLENGES---\n");
  for(i=0;i<p->skillCount; i++)
  {
    if (p->skills[i].demonstrated == 0)
    {
      printf("\nChallenge for %s:\n",p->skills[i].name);
    }
  }
}

void displayProfile(struct Project p)
{
 int i;
 printf("\n======== PROOFOFSKILL========\n");
 printf("Project: %s\n", p.projectName);
 printf("Description: %s\n", p.description);
 printf("\nSKILL PROFILE\n");
 for (i=0; i,p.skillCount; i++)
 {
   printf("%D. %s -", i+1, p.skills[i].name);
   if(p.skills[i].demonstrated == 1)
   {
     printf("Demonstrated\n");
   }
   else
   {
     printf("Needs Evidence\n");
   }
 }
printf("\n========================\n");
}
int main()
{
 struct Project p;
 int i;
 printf("WELCOME TO PROOFOFSKILL\n");
 printf("\nEnter project name:");
 fgets(p.projectName, sizeof(p.projectName), stdin);

 p.description[strcspn(p.projectName,"\n")] ='\0';
 printf("\nHow many skills do you want to evaluate?");
 scanf("%d", &p.skillCount);
 if(p.skillCount < 1 || p.skillCount>MAX)
 {
   printf("Invalid skill count.\n");
   return 1;
 }
 for(i=0; i<p.skillCount; i++)
 {
   printf("\nEnter skill %d:", i+ 1);
   scanf(" %49[^\n]",p.skills[i].demonstrated);
   if(p.skills[i].demonstrated != 1)
   {
    printf("Invalid choice. Marking as not yet demonstrated.\n");
    p.skills[i].demonstrated = 0;
   }
 }
 analyseSkills(&p);
 generateChallenge(&p);
 displayProfile(p);
 return 0;
}