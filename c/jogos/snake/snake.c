#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int main(int argc, char* argv[]){

 
    
    _cprintf("and the answer is 42 with a red background.");
   while (!kbhit()){
      printf("you have touched key.\n");
      Sleep(500);
   }

   int c = getch();
   putch(c);
 
   return 0;
}