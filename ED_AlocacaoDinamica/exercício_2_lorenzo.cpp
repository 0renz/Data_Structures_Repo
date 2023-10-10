#include <iostream>
#include <ctime>
using namespace std;

main()
{
    srand(time(NULL));

    int *A = new int[5];

    for(int i = 0; i < 5; i++)
    {
        cout << i << endl;

        cout << "&A[i]: " << &A[i] << endl;
        cout << "A[i]: " << A[i] << endl;
        cout << "A+i: " << A+i << endl;
        cout << "*(A+i): " << *(A+i) << endl;
        cout << endl;
    }
}
