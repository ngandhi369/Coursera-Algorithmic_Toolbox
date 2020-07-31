//5.modulo
#include <iostream>
using namespace std;

long long get_pisano_period(long long m)
{
    long long a = 0, b = 1;
    long long c = a + b;
    for (int i = 0; i < m * m; i++)
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            return i + 1;
    }//this fun gives the length of pisano period of m
}

long long get_fibonacci_huge(long long n, long long m)
{
    long long remainder = n % get_pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (int i = 1; i < remainder; i++)
    {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int main() {
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge(n, m) << endl;
}
