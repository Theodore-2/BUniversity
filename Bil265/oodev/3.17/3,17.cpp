#include <iostream>
#include <string>
using namespace std;

class HealthProfile {
private:
    string firstName;
    string lastName;
    string gender;
    int birthDay;
    int birthMonth;
    int birthYear;
    double height;
    double weight; 

public:
    
    HealthProfile(string fName, string lName, string gen, int day, int month, int year, double h, double w)
        : firstName(fName), lastName(lName), gender(gen), birthDay(day), birthMonth(month), birthYear(year), height(h), weight(w) {}

    
    int getAge(int currentYear) const {
        return currentYear - birthYear;
    }

    
    int getMaxHeartRate(int currentYear) const {
        return 220 - getAge(currentYear);
    }


    void displayTargetHeartRateRange(int currentYear) const {

        int maxHeartRate = getMaxHeartRate(currentYear);
        double lowerBound = maxHeartRate * 0.5; 
        double upperBound = maxHeartRate * 0.85; 
        cout << "Target heart rate range: " << lowerBound << " - " << upperBound << " beats per minute." << endl;
    }


    double getBMI() const {
        return weight / (height * height);
    }


    void displayBMICategory() const {
        double bmi = getBMI();
        cout << "Your BMI is: " << bmi << endl;
        if (bmi < 18.5) {
            cout << "Category: Underweight" << endl;
        } else if (bmi >= 18.5 && bmi < 24.9) {
            cout << "Category: Normal weight" << endl;
        } else if (bmi >= 25 && bmi < 29.9) {
            cout << "Category: Overweight" << endl;
        } else {
            cout << "Category: Obesity" << endl;
        }
    }
};

int main() {

    string firstName, lastName, gender;
    int birthDay, birthMonth, birthYear;
    double height, weight;

    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Enter your gender: ";
    cin >> gender;
    cout << "Enter your birth day (day month year): ";
    cin >> birthDay >> birthMonth >> birthYear;
    cout << "Enter your height in meters: ";
    cin >> height;
    cout << "Enter your weight in kg: ";
    cin >> weight;

    
    HealthProfile profile(firstName, lastName, gender, birthDay, birthMonth, birthYear, height, weight);

    int currentYear;
    cout << "Enter the current year: ";
    cin >> currentYear;

    
    cout << "Age: " << profile.getAge(currentYear) << " years" << endl;
    cout << "Maximum heart rate: " << profile.getMaxHeartRate(currentYear) << " beats per minute" << endl;
    
	profile.displayTargetHeartRateRange(currentYear);
    profile.displayBMICategory();

    return 0;
}

