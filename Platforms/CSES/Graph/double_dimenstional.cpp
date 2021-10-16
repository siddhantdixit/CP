#include<bits/stdc++.h>
 using namespace std;

void func(int **arr, int row, int col)
{
   for (int i=0; i<row; i++)
   {
      for(int j=0 ; j<col; j++)
      {
        cout<<arr[i][j]<<" ";
      }
      printf("\n");
   }
}

int main()
{
  int row, colum;
  cin>>row>>colum;
  int** arr = new int*[row];

  for(int i=0; i<row; i++)
  {
     arr[i] = new int[colum];
  }

  for(int i=0; i<row; i++)
  {
      for(int j=0; j<colum; j++)
      {
         cin>>arr[i][j];
      }
  }
  func(arr, row, colum);

  return 0;
}