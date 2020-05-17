#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <curses.h>
FILE * out_stream=(FILE*)0;
FILE* in_stream=(FILE*)0;
char detect_key(FILE*in){
  char peek=-1;
  int count=0,check;
  struct termios oldsett,newsett;
  check=tcgetattr(fileno(in),&oldsett);
  if(check==-1)
    printf("there has been an error in detect_key termios struct no 1\n");
  newsett=oldsett;
  newsett.c_cc[VMIN]=0;
  check=tcsetattr(fileno(in),TCSANOW,&newsett);
  if(check==-1)
    printf("there has been an error in detect_key termios struct no 2\n");
  count=read(fileno(in),&peek,1);
  check=tcsetattr(fileno(in),TCSANOW,&oldsett);
  if(check==-1)
    printf("there has been an error in detect_key termios struct no 3\n");
  if(count==1 && peek !='\n' && peek !='\r')
    return peek;
  else
    return -1;
}
int char_to_term(char ch){
  if(out_stream)
    putc(ch,out_stream);
  return 0;
}
int char_to_term2(char ch){
  if(in_stream)
    putc(ch,in_stream);
  return 0;
}
int main(int argc,char* argv[]){
  if(!isatty(fileno(stdout)))
    printf("you are not in terminal!\n");
  FILE* input=fopen("/dev/tty","rw");
  FILE* output=fopen("/dev/tty","w");
  if(!input || !output)
    printf("unable to open ttys!");
  out_stream=output;
  in_stream=input;
  struct termios old_set;
  struct termios new_set;
  int warn=0;
  int row=0, coll=0;
  char * cursor, *clear;
  char myc=-1;
  //tputs(clear,1,char_to_term2);
  setupterm(NULL,fileno(output),(int*)0);
  clear=tigetstr("clear");
  tputs(clear,1,char_to_term);
  fprintf(output,"%s\n",argv[1]);
  tcgetattr(fileno(input),&old_set);
  new_set=old_set;
  new_set.c_lflag&=~ECHO;
  new_set.c_lflag&=~ICANON;
  new_set.c_cc[VMIN]=1;
  new_set.c_cc[VTIME]=0;
  tcsetattr(fileno(input),TCSANOW,&new_set);
  while(warn==0){
    cursor=tigetstr("cup");
    tputs(tparm(cursor,row,coll),1,char_to_term);
    myc=detect_key(input);
    if(myc!=-1)
      {
	warn=1;
	tcsetattr(fileno(input),TCSANOW,&old_set);
	fprintf(output,"you 've chosen %c!!\n",argv[1][coll]);
      }
    coll++;
    coll=coll%strlen(argv[1]);
  } 
  exit (0);
}
