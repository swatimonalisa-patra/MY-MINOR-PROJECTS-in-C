#include <stdio.h>
#include <string.h>

int main()
{
    printf("\n\t\t************Welcome to My MINOR project 2************");
	printf("\n");
	printf("\t\t\tThis is some string functions");	
	printf("\n");
	printf("\t\t\tproject is done by SWATIMONALISA PATRA");
	printf("\n");
	printf("\t\t\tfrom oretes academy");
	printf("\n");
	int i=1;
	char operation;
	while(i)
   {
	options();
		printf("\t\t\t");
		operation = getch();
		
		switch(operation)
		{
			case '1': first_occurances();
				break;
				
			case '2': copy_characters();
				break;
			
			case '3':calculate_length_of_number();
			    break;
			    
			case '4':string_character_to_match();
			    break;
			
			case '5':string_pointed_by_another_string();
			    break;	    
			    default: printf("\n\t\tYou entered unavailable option");
		}
	}
	
}

void options()
{
	printf("\n");
	printf("\t\t\tEnter your choice of operation");
	printf("\n");
	printf("\t\t\tEnter 1 for first_occurances");
	printf("\n");
	printf("\t\t\tEnter 2 for copy_characters");
	printf("\n");
	printf("\t\t\tEnter 3 for calculate_length_of_number");
	printf("\n");
	printf("\t\t\tEnter 4 for string_character_to_match");
	printf("\n");
	printf("\t\t\tEnter 5 for string_pointed_by_another_string");
	printf("\n");
	printf("\t\t\tEnter d to display the menu again");
	printf("\n");
}

	
	//strchr//
	char *(strrchr)(const char *s, int c)
 {
     const char *last = NULL;
     if (c == '\0')
         return strchr(s, c);
    while ((s = strchr(s, c)) != NULL) 
	{
         last = s;
         s++;
     }
     return (char *) last;
 }
 /* memcpy */
 void *(memcpy)(void * s1, const void *  s2, size_t n)
 {
     char *dst = s1;
     const char *src = s2;
     while (n-- != 0)
         *dst++ = *src++;
     return s1;
 }
 /* strcspn */
 size_t (strcspn)(const char *s1, const char *s2)
 {
     const char *sc1;
     for (sc1 = s1; *sc1 != '\0'; sc1++)
         if (strchr(s2, *sc1) != NULL)
             return (sc1 - s1);
     return sc1 - s1;            
 }
  /* strpbrk */
 char *(strpbrk)(const char *s1, const char *s2)
 {
     const char *sc1;
     for (sc1 = s1; *sc1 != '\0'; sc1++)
         if (strchr(s2, *sc1) != NULL)
             return (char *)sc1;
     return NULL;                
 }
 /*strspn */
 size_t (strspn)(const char *s1, const char *s2)
 {
     const char *sc1;
     for (sc1 = s1; *sc1 != '\0'; sc1++)
         if (strchr(s2, *sc1) == NULL)
             return (sc1 - s1);
     return sc1 - s1;           
 }
