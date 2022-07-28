#include<iostream>
using namespace std;

char M[3][3]; int i , j;

void fill_matrix()
{
    for(i = 0; i<3; i++)
    {
        for(j = 0; j<3; j++)
        {
           cout << "M[" << i << "][" << j << "]=";
		   cin >> M[i][j];
        }
    }
}

void print_matrix()
{
    for(i=0; i<3; i++)
    {
        for(j = 0; j<3; j++)
        {
            cout<<M[i][j]<<" ";
        }
    }

}

int main()
{
    fill_matrix();
    print_matrix();
    return 0;
}