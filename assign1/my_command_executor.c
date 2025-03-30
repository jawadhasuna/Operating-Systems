#include<unistd.h> //used for fork a child and execlp
#include<stdio.h>//used for printing
#include<sys/types.h>//used for pid_t data type
#include<sys/wait.h>//used for wait func
#include<time.h>//used for logging time
void log_history(int argc, char* argv[]) //func to log time in jawad history file
{  FILE* file = fopen("jawadhistory.log", "a");//open and appends file
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    fprintf(file, "%02d-%02d-%d:%02d:%02d:%02d ",t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,t->tm_hour,
    t->tm_min, t->tm_sec); //print in file
        for (int i=0;i<argc;i++)
          {   
             fprintf(file, "%s ", argv[i]);//loop to print all arguments
          }
    fprintf(file, "\n");//to go next line
    fclose(file);//close file after appending
}
int main(int argc,char*argv[])//take command line parameters
{
log_history(argc, argv);//call func to log
pid_t pid;//create var
  for(int i=1;i<argc;i++)
  {
   pid=fork();//loop to fork argc times
    if(pid==0)//go to child process
     {
     execlp(argv[i],argv[i],NULL);//with execlp u call files using string to run another program
    }
     else
    {
    wait(NULL);//parent process wait for child to finish
     }
}
return 0;
}
