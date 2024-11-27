#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Station {
    string name;
    string frequency;
};

class StationManager {
private:
    vector<Station> Stations;

public:
    // Create Adding a new Station /////////////////////////////////////////
    void addStation(const string& name, const string& frequency) {
        Stations.push_back({name, frequency});
        cout << "\n----------------------------------" << endl;
        cout << "Radio Station added successfully!" << endl;
        cout << "----------------------------------\n" << endl;
    }

    // Read Displaying all Stations /////////////////////////////////////////////////
    void displayStations() const {
        cout << "\n----------------------------------" << endl;
        if (Stations.empty()) {
            cout << "No Radio Station available." << endl;
        } else {
            cout << "Radio Station List:" << endl;
            for (size_t i = 0; i < Stations.size(); ++i) {
                cout << i + 1 << ". Name: " << Stations[i].name 
                     << ", frequency: " << Stations[i].frequency << endl;
            }
        }
        cout << "----------------------------------\n" << endl;
    }

    // Update Modify an existing Stations /////////////////////////////////////////////
    void updateStation(int index, const string& newName, const string& newfrequency) {
        if (index < 1 || index > Stations.size()) {
            cout << "\n----------------------------------" << endl;
            cout << "Invalid Radio Staion index!" << endl;
            cout << "----------------------------------\n" << endl;
            return;
        }
        Stations[index - 1].name = newName;
        Stations[index - 1].frequency = newfrequency ;
        cout << "\n----------------------------------" << endl;
        cout << "Radio Station updated successfully!" << endl;
        cout << "----------------------------------\n" << endl;
    }

    // Delete Remove a Staion //////////////////////////////////////////////////
    void deleteStation(int index) {
        if (index < 1 || index > Stations.size()) {
            cout << "\n----------------------------------" << endl;
            cout << "Invalid Station index!" << endl;
            cout << "----------------------------------\n" << endl;
            return;
        }
        Stations.erase(Stations.begin() + index - 1);
        cout << "\n----------------------------------" << endl;
        cout << "Radio Station deleted successfully!" << endl;
        cout << "----------------------------------\n" << endl;
    }

    // Display the menu and process user input /////////////////////////////////////////////////
    void menu() {
        int choice;
        do {
            cout << "\n==============================" << endl;
            cout << "Radio Stations Management System Menu" << endl;
            cout << "==============================" << endl;
            cout << "1. Add Station" << endl;
            cout << "2. Display Stations" << endl;
            cout << "3. Update Station" << endl;
            cout << "4. Delete Station" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();  // To clear the input buffer

            switch (choice) {
                case 1: {
                    string name, frequency;
                    cout << "\nEnter name of Station: ";
                    getline(cin, name);
                    cout << "Enter Station frequency: ";
                    getline(cin, frequency);
                    addStation(name, frequency);
                    break;
                }
                case 2:
                    displayStations();
                    break;
                case 3: {
                    int index;
                    string newName, newfrequency;
                    cout << "\nEnter Station Number to update: ";
                    cin >> index;
                    cin.ignore();  // To clear the input buffer
                    cout << "Enter new Station name: ";
                    getline(cin, newName);
                    cout << "Enter new Station frequency: ";
                    getline(cin, newfrequency);
                    updateStation(index, newName, newfrequency);
                    break;
                }
                case 4: {
                    int index;
                    cout << "\nEnter Station number to delete: ";
                    cin >> index;
                    deleteStation(index);
                    break;
                }
                case 5:
                    cout << "\nExiting..." << endl
                         << "Thank you for using radio Stations Management System" << endl;
                    break;
                default:
                    cout << "\nInvalid choice! Please try again." << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    StationManager manager;
    manager.menu();
    return 0;
}