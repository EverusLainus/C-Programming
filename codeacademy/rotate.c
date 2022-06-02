#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[3][3])
{
    for (int i=0; i<3;i++)
    {
        for (int j=0; j<3;j++)
        {
         char n_mat[3][3];
         char temp = matrix[2-j][i];
         n_mat[i][j]= temp;
         printf("%c", n_mat[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    char matrix[3][3]={{'a','1','2'},{'A','4','5'},{'6','7','8'}};
    rotate(matrix); 
    return 0;
}


/*
void rotate(char matrix[10][10])
{
    for (int i=0; i<10;i++)
    {
        for (int j=0; j<10;j++)
        {
         matrix[i][j]= matrix[9-j][i];
         printf("%c", matrix[i][j]);
        }
        printf("/n");
    }

}
*/