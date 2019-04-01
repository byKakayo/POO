// CPP program to create an empty vector 
// and one by one push values.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Create an empty vector
    vector<int> vect;

    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);

    for (int x : vect)
        cout << x << " ";

    return 0;
}
