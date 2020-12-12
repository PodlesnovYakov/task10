#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 100
#include <locale.h>
int main()
{
    setlocale(LC_ALL,"Rus");
    char s[n],*s2,*lastworld;
    char s1[n] = "";
    char s3[n] = "";
    char s4[n] = "";
    int temp = 0;
    int i = 0;
    int count = 0;
    FILE *f1 = fopen("S1.txt","r");
    fgets(s,n,f1);
    fclose(f1);
    FILE *f2 = fopen("S2.txt","w");
    // удаление лишних пробелов
    s2 = strtok(s,". ");
    while (s2 != NULL)
    {
        strcat(s1,s2);
        strcat(s1," ");
        s2 = strtok(NULL,". ");
    }
    strcpy(s,s1);
    fputs(s,f2);
    fputs("\n",f2);
    // удаление последнего слова
    s2 = strtok(s,". ");
    while (s2 != NULL)
    {
        lastworld = s2;
        s2 = strtok(NULL,". ");

    }
    s2 = strtok(s1,". ");
    while (s2 != NULL)
    {
        if(strcmp(s2,lastworld )!= 0)
        {
            strcat(s3,s2);
            strcat(s3," ");
        }
        s2 = strtok(NULL,". ");

    }
    strcpy(s,s3);
    fputs(s,f2);
    fputs("\n",f2);

    //удвоение букв в слове
    s2 = strtok(s,". ");
    while (s2 != NULL)
    {
        while(i  < 2*strlen(s2))
        {
            if (count < 2)
            {
                s4[temp + i] = s2[i/2];
                i++;
                count++;
            }
            else
            {

                count = 1;
                s4[temp+i] = s2[i/2];
                i++;
            }
        }
        strcat(s4," ");
        s2 = strtok(NULL,". ");
        i = 0;
        count = 0;
        temp = strlen(s4);
    }
    strcpy(s,s4);
    fputs(s,f2);
    fclose(f2);
    return 0;
}




