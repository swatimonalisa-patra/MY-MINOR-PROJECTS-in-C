//student database Management//
//My Minor Project 3//
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
void gotoxy(short col,short row);

int main()
{
	FILE *fp, *ft;
	char another, choice;
	
	struct student
	{
		char name[20];
		int age;
		float per;
	};
	struct student s;
	char studentname[40];
	long int rec_size;
	
	fp=fopen("studentDBMS.DAT","r");
	if(fp==NULL)
	{
	  fp=fopen("studentDBMS.DAT","a");
	  if(fp==NULL)
	  {
		puts("can not open file");
		exit(1);
	  }
    }
rec_size=sizeof(s);
while(1)
{
	system ("cls");
	gotoxy (30,10);
	printf ("1.Add Records");
	gotoxy (30,12);
	printf ("2.List Records");
	gotoxy (30,14);
	printf ("3.Modify Records");
	gotoxy (30,16);
	printf ("4.Delete Records");
	gotoxy (30,16);
	printf ("0.Exit");
	gotoxy (30,20);
	printf ("Enter Your Choice:");
	fflush (stdin);
	choice=getche();
	switch(choice)
	{
		case '1':
			fseek(fp,0,SEEK_END);
			another='Y';
			while(another=='Y'|| another=='y')
			{
				printf("Enter name, age & percentge of student :");
				scanf("%s %d %f,s.name, &s.age, &s.per");
				fwrite(&s,rec_size,1,fp);
				printf("\nAdd another record(Y/N) ");
				fflush(stdin);
				getche();
			}
			break;
			
		case '2':
			rewind(fp);
			while(fread(&s , rec_size, 1, fp) == 1)
			    printf("\n%s %d %f",s.name, s.age, s.per);
			    
			printf("\n type 'q' or 'Q' to return to main menu: ");
			char q;
			q=getche();
			if (q=='Q'||q=='q') 
			   break; 
			   
		case '3':
		    another='Y';
			while(another=='Y'|| another=='y')	
			{
				printf("\nEnter name of student to modify");
				scanf("%s",studentname);
				rewind(fp);
				while(fread(&s ,rec_size, 1, fp)==1)
				{
					if(strcmp(s.name, studentname)==0)
					{
						printf("\nEnter new name, age & per");
						scanf("%s %d %f",s.name ,&s.age, &s.per );
						fseek(fp,-rec_size,SEEK_CUR);
						fwrite(&s,rec_size,1,fp);
						break;
					}
				}
				printf("\nModify another Record (Y/N)");
				fflush(stdin);
				another = getche();
		    }  
			break;   
			    
		case '4':
		    another='Y';
			while(another=='Y'||another=='y')
			{
				printf("\nEnter name of student to delete");
				scanf("%s", studentname);
				ft=fopen("Tstudent.DAT","wb");
				rewind(fp);
				while(fread(&s, rec_size, 1, fp)==1)
				{
					if(strcmp(s.name,studentname)!=0)
					   fwrite(&s,rec_size,1,ft);
			    }
			    fclose(fp);
			    fclose(ft);
			    remove("studentDBMS.DAT");
			    rename("Tstudent.DAT","studentDBMS.DAT");
			    fp=fopen("studentDBMS.DAT","r");
			    printf("Delete Another Record (Y/N)");
			    fflush(stdin);
			    another=getche();
			    }
			    break;
			
		case '0':
		    fclose (fp);
			exit(0);				
	}
 }
  return 0;
}
