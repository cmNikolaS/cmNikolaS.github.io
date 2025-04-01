#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> T(N);
    for (int i = 0; i < N; cin >> T[i++]); 

    vector<int> P(N - 1);
    for (int i = 0; i < N - 1; cin >> P[i++]);

    if (N <2) 
    {
        cout << T[0] << endl;
        return 0;
    }

    vector<long long> n(N, 0);
    n[0] = T[0];
    n[1] = min(T[0] + T[1], P[0]);

    for (int i = 2; i < N; i++)
        n[i] = min(n[i - 1] + T[i], n[i - 2] + P[i - 1]);

    cout << n[N - 1] << endl;
    return 0;
}
