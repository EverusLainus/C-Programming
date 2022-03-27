                                                                    
#include <stdio.h>
#include <stdlib.h>


int isInRange(int coord, int offset, int size) 
{
  if (coord>=offset && (coord < (offset+size)))                          
    {return 1;
    }
  else{
                                                                                       
  return 0;
}
}


int isAtBorder(int coord, int offset, int size) 
{
  if(coord==offset || coord == (offset+size)-1){
    return 1;
   
  }                                                      
  else{                                                                       
  return 0;
}
}
int max(a,b)
{
    if(a<b){
        return b;
    }
    else{
        return a;
    }
}

void squares(int size1, int x_offset, int y_offset, int size2) {
    int x=0;
    int y=0;
    int w;
    int h;
                                     
  w= max(size1,(x_offset+size2));                                      
h= max(size1,(y_offset+size2));
                                                   
    for (y=0; y<h;y++){
                     //printf("y=%d and h=%d \n",y,h);                                 
for (x=0; x<w;x++){  
  //printf("x=%d and w=%d \n",x,w); 

                    /* int s=isInRange( x,  x_offset, size2);
                       int t =isAtBorder( y,  y_offset, size2);
                       int u = isInRange( y,  y_offset,  size2);
                       int v =isAtBorder( x,  x_offset,  size2);
                       printf("s=%d \n",s);
                       printf("t=%d\n",t);
                       printf("u=%d \n",u);
                       printf("v=%d \n",v);*/

 if( ( (isInRange( x,  x_offset, size2)==1) && (isAtBorder( y,  y_offset, size2)==1 ))|| ( (isInRange( y,  y_offset,  size2)==1) && (isAtBorder( x,  x_offset,  size2)==1)) )  
                     
                     {
                         printf("*");
                     }
                   else
                     {
                      if(((x<size1) &&( y==0 || y==(size1-1))) || ((y<size1) &&( x==0 || x==(size1-1))))
                        {
                         printf("#");
                        }
                      else{
                           printf(" ");
                      }
                     }
}
printf("\n");
    }
}

int main()
{
  int a;
  int b;
  int c;
  int d;
  
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  squares(a,b,c,d);
  return 0;
}
   /* int p=isInRange( x,  x_offset,  size2); 
    int q=isAtBorder( y,  y_offset,  size2);
     int r=isInRange( y,  y_offset,  size2);
     int s=isAtBorder( x,  x_offset,  size2);*/
                                                 