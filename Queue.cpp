#include <iostream>

#include <string>

#include <queue>



using namespace std;



// Person class to store name and ticket number ||||||||||||||||||

class Person {

public: 

    string name;

    int ticket_number;



    // Constructor for the Person class |||||||||||||||||||||

    Person(string name, int ticket_number) : name(name), ticket_number(ticket_number) {}

};



// TicketQueue class to manage the queue of persons ||||||||||||||||||||||

class TicketQueue {

private:

    queue<Person> q;

    int next_ticket_number;



public: 

    // Constructor for the TicketQueue class ||||||||||||||||||||||||||

    TicketQueue() : next_ticket_number(1) {}



    // Enqueue a person |||||||||||||||||

    void enqueue(string name) {

        Person new_person(name, next_ticket_number++);

        q.push(new_person);

        cout << name << " has been added to the queue with ticket #00" << new_person.ticket_number << endl;

        cout << "Queue size: " << size() << endl;

    }



    // Dequeue a person (not used in the menu but kept in case of future need ||||||||||||||||

    void dequeue() {

        if (!q.empty()) {

            Person front_person = q.front();

            cout << front_person.name << " has received their ticket (Ticket No: " << front_person.ticket_number << ")" << endl;

            q.pop();

        } else {

            cout << "The queue is empty, no one to dequeue!" << endl;

        }

    }



    // Check if queue is empty ||||||||||||||||

    bool isEmpty() {

        return q.empty();

    }



    // Return the size of the queue |||||||||||||||||||

    int size() {

        return q.size();

    }



    // Peek at the next person in the queue |||||||||||

    void peek() {

        if (!q.empty()) {

            Person front_person = q.front();

            cout << "Next in line: " << front_person.name << " (Ticket No: " << front_person.ticket_number << ")" << endl;

        } else {

            cout << "The queue is empty!" << endl;

        }

    }



    // Find and return the position of a person in the queue based on their name ||||||||||||||||||||

    void position(string name) {

        queue<Person> temp_q = q;

        int position = 1;

        while (!temp_q.empty()) {

            Person current = temp_q.front();

            if (current.name == name) {

                cout << name << " is at position " << position << " in the queue." << endl;

                return;

            }

            temp_q.pop();

            position++;

        }

        cout << name << " is not in the queue." << endl;

    }

};



// Function display menu |||||||||||||||||||||||||||

void displayMenu() {

    cout << "\nWELCOME to Olivia Rodrigo's Concert Ticketing System!" << endl;

    cout << "1. Enqueue a person" << endl;

    cout << "2. Check your position in the queue" << endl;

    cout << "3. Exit" << endl;

    cout << "Choose an option: ";

}



int main() {

    TicketQueue tq;

    int choice;

    string name;



    do {

        displayMenu();

        cin >> choice;



        switch (choice) {

            case 1:

                // Enqueue a person |||||||||||||||||||||||||||

                cout << "Enter your name: ";

                cin >> name;

                tq.enqueue(name);

                break;



            case 2:

                // Check position in queue ||||||||||||||||||||||||||||||||||||||||||

                cout << "Enter your name to check your position: ";

                cin >> name;

                tq.position(name);

                break;



            case 3:

                // Exit ||||||||||

                cout << "Exiting system!\n";

                break;



            default:

                cout << "Please retry.\n";

                break;

        }

    } while (choice != 3);



    // tq.enqueue("alice");

    // tq.enqueue("bob");

    // tq.enqueue("Charlie");"



    return 0;

}
