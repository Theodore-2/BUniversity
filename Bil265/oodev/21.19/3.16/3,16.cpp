#include <iostream>
using namespace std;

class TargetHeartRateCalculator {
private:
    int age; 
    int restingHeartRate; 

public:
    
    TargetHeartRateCalculator(int userAge, int userRestingHeartRate) {
        age = userAge;
        restingHeartRate = userRestingHeartRate;
    }

  
    int getMaxHeartRate() const {
        return 220 - age;
    }

   
    void displayTargetHeartRateRange() const {
        int maxHeartRate = getMaxHeartRate();
        double lowerBound = maxHeartRate * 0.5; 
        double upperBound = maxHeartRate * 0.85; 
        cout << "Target heart rate range: " << lowerBound << " - " << upperBound << " beats per minute." << endl;
    }
};

int main() {
    int age, restingHeartRate;

   
    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your resting heart rate: ";
    cin >> restingHeartRate;

    
    TargetHeartRateCalculator calculator(age, restingHeartRate);

   
    cout << "Maximum heart rate: " << calculator.getMaxHeartRate() << " beats per minute." << endl;
    calculator.displayTargetHeartRateRange();

    return 0;
}

