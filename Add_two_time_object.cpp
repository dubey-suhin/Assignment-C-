#include <iostream>
#include <iomanip> // For setw and setfill

using namespace std;

class TIME {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor initializing time to 00:00:00
    TIME() : hours(0), minutes(0), seconds(0) {}

    // Parameterized constructor initializing to specific values
    TIME(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Member function to display time in HH:MM:SS format
    void display() const {
        cout << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << endl;
    }

    // Member function to add two TIME objects
    TIME add(const TIME &t) const {
        int totalSeconds = seconds + t.seconds;
        int totalMinutes = minutes + t.minutes + totalSeconds / 60;
        int totalHours = hours + t.hours + totalMinutes / 60;

        totalSeconds %= 60;
        totalMinutes %= 60;
        totalHours %= 24; // Assuming time is within a 24-hour format

        return TIME(totalHours, totalMinutes, totalSeconds);
    }
};

int main() {
    // Creating two TIME objects with specific times
    TIME t1(10, 45, 30);
    TIME t2(2, 20, 45);

    // Displaying the times
    cout << "Time 1: ";
    t1.display();

    cout << "Time 2: ";
    t2.display();

    // Adding two TIME objects
    TIME t3 = t1.add(t2);

    // Displaying the result
    cout << "Sum of Time 1 and Time 2: ";
    t3.display();

    return 0;
}
