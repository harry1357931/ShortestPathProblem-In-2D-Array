/** ShortestPathProblem -- Without Using Memo Array  
 *  ShortestPathProblemWithoutMemo.cpp
 *     
 *  Fall, 2011
 *
 *  Problem: Shortest Path Problem
 *    Given an m x n matrix of integers, this program computes the minimal path from left to right
 *    across the matrix. This path will start from anywhere in column 1 and consists of a sequence 
 *    of steps terminating in column n.
 *  
 *  For More Description & Example of Shortest Path Problem:
 *     Check File: 'ShortestPathProblem_Description.pdf'
 *      
 *  Input Format: The input format is NOT same as specified in 'ShortestPathProblem_Description.pdf' 
 *      Actually, for now this program accepts NO INPUT, However, the input m x n matrix is represented
 *      by 2-D integer array 'air', so check for 2-D array 'air' in this program and change it if you want
 *      to output of the program on different Inputs. Don't change the dimensions of array, as i didn't
 *      optimize this program yet for different dimensions, but you can change the values in that array, 
 *      that will definitely work
 *
 *  OutPut Format:
 *      The output format is same as specified in file 'ShortestPathProblem_Description.pdf'.
 *      Two lines will be outputted for matrix (2D array) 'air'. The FIRST line will represent the 
 *      path in the matrix (2D array 'air'), this path will consist of n integers as there will
 *      be n columns in that matrix, and SECOND line will represent the cost of minimal path.   
 *
 * @param air Kind of Matrix (or 2D Input array)  
 * @Compiler version on which Program is Last Run before uploading to Github: Dev-C++ 5.4.1, Date: 1st July, 2013   
 * @author Gurpreet Singh
 */
 
#include<iostream>
#include <cstdlib>
using namespace std;
int air[5][6]={{3,4,1,2,8,6},{6,1,8,2,7,4},{5,9,3,9,9,5},{8,4,1,3,2,6},{3,7,2,8,6,4} };
int row123[7]= {4,0,1,2,3,4,0};
// or use Zeros at Column ends
int Min(int a, int b, int c){
  if(a<=b&&a<=c)
       return a;
  else if(b<=a&&b<=c)
       return b;   
  else
     return c;           
  };

int MinSum(int row, int col) {              // Recursive function
     int M3;                               // Minimum of three numbers
     if(col==0)                        // Base case 
          return air[row][col];           
     
     if(row==0)     
        M3= air[row][col] + Min( MinSum(4,col-1), MinSum(row, col-1), MinSum(row+1, col-1) );
     else if(row==4)
        M3=  air[row][col] + Min( MinSum(row-1,col-1), MinSum(row, col-1), MinSum(0, col-1) );
     else
        M3= air[row][col] + Min( MinSum(row-1, col-1), MinSum(row, col-1), MinSum(row+1, col-1) );
     
     return M3;
  
  };// MinSum
// Shortest Path Function
void SPath(int Svalue, int row, int col){   // need to modify this function
     int MiniP, rowA=0;     // Minimum of three numbers
     int r1, r2, r3;
     if(col==0)                      // Base case 
        {  cout<<row+1<<" ";
           return;           
        }
     MiniP= Svalue-air[row][col];
     
     // To find the three rows in previous columns 
     for(int i=1; i<=5; i++) {
         if(row==row123[i]){
            r1= row123[i-1];
            r2= row123[i];
            r3= row123[i+1];
           break;               
       }// if loop ends
    }// for loop ends   
    
     // To get the new row for Next Call 
     if(MiniP==MinSum(r1,col-1))
          rowA= r1;   
     else if(MiniP==MinSum(r2, col-1))
          rowA= r2 ;  
     else if(MiniP==MinSum(r3, col-1))
          rowA= r3;                          
      
         
     SPath(MiniP , rowA, col-1);           
     cout<<row+1<<" ";
   };  

int main(){
    int row, col, Save[5], miniS=1000, alpharow;
    for(int i=0;i<5;i++) {             //Traversing through the last column and finding the minimum sum
       Save[i]= MinSum(i,5);           // Shift this stuff to recursive function     
       if(miniS>=Save[i]){
           miniS= Save[i];
           alpharow=i; 
        }// if loop ends here
     }
    SPath(miniS , alpharow, 5); 
    cout<<endl<<miniS;               // miniS contains the final smallest cost function value   
    system("pause");           // alpharow contains is row at column 5, where smallest cost function lives
    return 0;
 }
