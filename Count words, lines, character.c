/*Write a c Prgram that behave likes a shell which display the command prompt 'myshell$'.It accept the command,tokenize the command line and execute it by creating the child process.Also implement the additional command ;count as
'myshell$' count c filename:It will dispaly the no.of characters in given file
'myshell$' count w filename:It will dispaly the no.of words in given file
'myshell$' count l filename:It will dispaly the no.of lines in given file
*/

#include<stdio.h>
#include<string.h>
int count(char fname[],char option);
int main(int argc,char *argv[])
{
  char fname[20];
  char option;
  if(argc != 4)
  {
    printf("Invalid No of argument");
  }
  option=*argv[2];
  strcpy(fname,argv[3]);
  count(fname,option);
}
int count(char fname[],char option)
{
  long ccnt,wcnt,lcnt;
  FILE *fp;
  long lflag,wflag;
  int ch;
  fp=fopen(fname,"r");
  if(fp==NULL)
  {
    printf("\n File does not exit");
  }
  ccnt=wcnt=lcnt=0;
  lflag=wflag=1;
  ch=fgetc(fp);
  while(ch!=EOF)
  {
    ccnt++;
    if(ch==' '||ch=='\t')
    {
      lflag=0;
      if(wflag==0)
      {
        wcnt++;
        wflag=1;
      }
    }
    else
    if(ch==10)
    {
      ccnt++;
      lcnt++;
      lflag=1;
      if(wflag==0)
      {
        wcnt++;
        wflag=1;
      }
     }
     else
     {
       wflag=0;
       lflag=0;
     }
     ch=fgetc(fp);
 }
 if(wflag==0)
   wcnt++;
 if(lflag==0)
   lcnt++;
   switch(option)
   {
     case 'c':printf("\n char count = %d\n",ccnt);
     		break;
      case 'w':printf("\n word count = %d\n",wcnt);
     		break;
      case 'l':printf("\n line count = %d\n",lcnt);
     		break;
    }
 }
