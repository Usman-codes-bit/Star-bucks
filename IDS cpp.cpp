#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> failedAttempts;
    int n;

    cout << "===== Intrusion Detection System (IDS) =====" << endl;
    cout << "Enter number of login records: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string ip, status;

        cout << "\nRecord " << i << endl;
        cout << "IP Address: ";
        cin >> ip;

        cout << "Login Status (SUCCESS/FAILED): ";
        cin >> status;

        if (status == "FAILED") {
            failedAttempts[ip]++;
        }
    }

    cout << "\n========== IDS REPORT ==========" << endl;

    bool intrusionFound = false;

    for (auto entry : failedAttempts) {
        if (entry.second >= 3) {
            cout << "ALERT! Possible Intrusion Detected" << endl;
            cout << "IP Address: " << entry.first << endl;
            cout << "Failed Attempts: " << entry.second << endl;
            cout << "-------------------------------" << endl;
            intrusionFound = true;
        }
    }

    if (!intrusionFound) {
        cout << "No suspicious activity detected." << endl;
    }

    return 0;
}
