#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n) {
        vector<int> cards(5);

        for (int i = 0; i < 5; ++i) {
            cin >> cards[i];
        }

        sort(cards.begin(), cards.end()); // Ordena las cartas iniciales

        bool found = false;
        for (int i = 1; i <= 52; ++i) {
            if (find(cards.begin(), cards.end(), i) == cards.end()) {
                // La carta i no está en las cartas iniciales
                vector<int> permuted = cards;
                permuted.push_back(i);
                sort(permuted.begin(), permuted.end()); // Ordena las 6 cartas

                bool valid = true;
                for (int j = 0; j < 5; ++j) {
                    if (permuted[j + 1] - permuted[j] != 1) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    found = true;
                    cout << i << "\n";
                    break;
                }
            }
        }

        if (!found) {
            cout << -1 << "\n"; // No se encontró ninguna solución
        }
    }

    return 0;
}
