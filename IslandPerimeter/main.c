#include <stdio.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) 
{
      int i,j;
      int num = 0;
      int count = 0;
      for(i=0;i<gridRowSize;i++)
      {   
          for(j=0;j<gridColSize;j++)
          {
              if(grid[i][j] == 1)
              {
                  num++;   
                  if((j!=0)&&(grid[i][j-1] == 1)) 
                      count++; 
                  if((j!=gridColSize-1)&&(grid[i][j+1] == 1)) 
                      count++; 
                  if((i!=0)&&(grid[i-1][j] == 1)) 
                      count++; 
                  if((i!=gridRowSize-1)&&(grid[i+1][j] == 1)) 
                      count++; 
              }
          }
      }   
  return num*4-count;
}

int main(int argc, char *argv[])
{
	int i = 0;
    int result;
    int **grid;
    grid = (int **)malloc(4*sizeof(int *));
    for(i=0;i<4;i++)
    {
        grid[i] = (int *)malloc(4*sizeof(int));
    }
    
    grid[0][0] = 0; 
    grid[0][1] = 1; 
    grid[0][2] = 0; 
    grid[0][3] = 0; 
    
    grid[1][0] = 1; 
    grid[1][1] = 1; 
    grid[1][2] = 1; 
    grid[1][3] = 0; 
    
    grid[2][0] = 0; 
    grid[2][1] = 1; 
    grid[2][2] = 0; 
    grid[2][3] = 0; 
    
    grid[3][0] = 1; 
    grid[3][1] = 1; 
    grid[3][2] = 0; 
    grid[3][3] = 0; 
    result = islandPerimeter(grid, 4, 4);
    printf("%d\n", result);
}
