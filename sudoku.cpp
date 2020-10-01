#include<iostream>
#include<cmath>
using namespace std;
bool issafetoput(int mat[9][9],int i,int j,int n,int number)
{
    for(int k=0;k<n;k++)
    {
        if(mat[i][k]==number || mat[k][j]==number)
        {
            return false;
        }
    }

    n=sqrt(n);

     int starti=(i/n)*n;
     int startj=(j/n)*n;

     for(int k=starti;k<starti+n;k++)
     {
         for(int l=startj;l<startj+n;l++)
         {
             if(mat[k][l]==number)
                return false;
         }
     }

     return true;
}
int sudokusolver(int mat[9][9],int n,int i,int j)
{
    if(i==n)
    {
      cout<<"\n\n"<<"Solution is :- \n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<mat[i][j]<<" ";
        cout<<endl;
        }
        return 1;
    }

    if(j==n)
    {
        return sudokusolver(mat,n,i+1,0);
    }

    if(mat[i][j]!=0)
    {
        return sudokusolver(mat,n,i,j+1);
    }

    for(int number=1;number<=n;number++)
    {
        if(issafetoput(mat,i,j,n,number))
        {
            mat[i][j]=number;
            bool ispossible=sudokusolver(mat,n,i,j+1);
            if(ispossible)
            {
                return true;
            }
            mat[i][j]=0;
        }
    }
    return 0;
}
void input(int a[][9],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cin>>a[i][j];
    }
}
bool check(int sol[][9])
{
    int sum1=0,sum2=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            sum1=0,sum2=0;

            for(int k=0;k<9;k++)
            {
                sum1=sum1+sol[k][j];
                sum2=sum2+sol[i][k];
            }
        }

        if( sum1!=45 || sum2!=45)
            return false;
    }
    return true;

}
int main()
{
    int mat[9][9]={{0}},ques[9][9]={{0}},sol[9][9]={{0}};
    char choice,c;
    cout<<"1.Solve Sudoku \n";
    cout<<"2.Check the Solution \n";
    cout<<"3.Exit sudoku \n";
    cout<<"Enter the choice : ";
    choice=cin.get();
       switch(choice)
       {
       case '1':
        cout<<"\n"<<"Enter the Question :- \n";
        input(mat,9,9);
        if(!sudokusolver(mat,9,0,0))
        cout<<"\n"<<"Solution not possible !!! \n";
        break;

       case '2':
           cout<<"\nEnter the solution :- \n";
           input(sol,9,9);
           if(check(sol))
              cout<<"\nSolution is correct !!! \n";
           else
           {
               cout<<"\nSolution is not correct !!! \n";
               cout<<"Want to know correct solution(Y/N) : ";
               cin>>c;
               if(c=='y' || c=='Y')
               {
                    cout<<"\n"<<"Enter the Question :- \n";
                    input(mat,9,9);
                    if(!sudokusolver(mat,9,0,0))
                    cout<<"\n"<<"Solution not possible !!! \n";
               }
           }
        break;

       case '3':
        return 0;
        break;

       default:
        cout<<"Invalid Choice ";
       }
    return 0;
}

/*
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
*/

/*
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
*/


