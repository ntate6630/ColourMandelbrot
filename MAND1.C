#include <stdio.h>

#define ASCII_ESC 27 

int left_edge = -420;
int right_edge = 300;
int top_edge = 300;
int bottom_edge = -300;
long x_step = 7;
long y_step = 15;
long y0;
long x0;
long x_x;
long y_y;
long x;
long y;
int i;
char the_char;
int max_iter = 200;

int main(void)
{
     y0 = top_edge;
     while(y0 > bottom_edge){
          x0 = left_edge;
          while(x0 < right_edge){
               y = 0;
               x = 0;
               the_char = ' '; 
               i = 0;
               while(i < max_iter){
                    x_x = (x * x) / 200;   
                    y_y = (y * y) / 200;
                    if(x_x + y_y > 800)
                    {
                         the_char = '0' + i;
                         if(i == 1)
                              printf("%c[34m", ASCII_ESC);
                         
                         if(i == 2)
                              printf("%c[31m", ASCII_ESC);
                         
                         if(i == 3)
                              printf("%c[35m", ASCII_ESC);

                         if(i > 3 && i < 5)
                              printf("%c[36m", ASCII_ESC);                          

                         if(i > 5 && i < 9 )
                              printf("%c[33m", ASCII_ESC);

                              
                         if(i > 9)
                         {
                              printf("%c[37m", ASCII_ESC);
                              the_char = '@';
                         }
                         i = max_iter;
                    }
                    y = x * y / 100 + y0;
                    x = x_x - y_y + x0;
                    i = i + 1;
               }
               putchar(the_char);
               x0 = x0 +x_step;
          }
          printf("\n");
          y0 = y0 - y_step;
     }
     printf("%c[37m", ASCII_ESC);
}             
     
 