#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int food[100], plate[100], count = 0;
    int used[100] = {0};

    for (int i = 0; i < n; i++)
        cin >> food[i];
    for (int i = 0; i < m; i++)
        cin >> plate[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!used[j] && food[i] <= plate[j])
            {
                used[j] = 1;
                count++;
                break;
            }
        }
    }

    cout << count << "\n";
    return 0;
}
