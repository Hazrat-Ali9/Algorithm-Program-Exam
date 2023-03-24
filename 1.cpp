 #include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < n; i++) {
        adj_list[i].reserve(n);
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x != 0) {
                adj_list[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (int j : adj_list[i]) {
            cout << " " << j;
        }
        cout << endl;
    }
    return 0;
}


