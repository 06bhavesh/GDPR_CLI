#include <iostream>
#include <string>
#include <fstream>
#include "questions.h"
#include "scoring.h"

using namespace std;

bool hasAssessment = false;
int answers[8] = {0};

int main() {
    while(true) {
        cout << "\n*** GDPR/AI Risk Checker ***\n";
        cout << "1. Start GDPR Risk Assessment\n";
        cout << "2. View Previous Assessment\n";
        cout << "3. Export the report\n";
        cout << "4. Exit\n";
        cout << "Pick an option: ";
        int choice;
        cin >> choice;
        
        if (choice == 4) {
            cout << "Thanks! Hope you found it useful\n";
            break;
        }
        
        switch (choice) {
            case 1: {
                cout << "\nStarting the Assessment...\n";
                for (int i = 0; i < 8; ++i) {
                    cout << "\nQuestion " << (i + 1) << "/8:\n";
                    cout << questions[i].text << "\n";
                    if (i < 6) {
                        cout << "If Yes press 1, else 0: ";
                    } else {
                        cout << "Enter 1-3 (low-high): ";
                    }
                    cin >> answers[i];
                }
                hasAssessment = true;
                AssessmentResult result = calculateRisk(answers);
                cout << "Total score: " << result.totalScore << "\n";
                cout << "Risk Level: " << result.category << "\n";
                break;
            }
            case 2: {
                if (!hasAssessment) {
                    cout << "\nNo assessment yet. Run option 1 first.\n";
                    break;
                }
                cout << "\nPrevious assessment:\n";
                for (int i = 0; i < 8; ++i) {
                    cout << "Q" << (i+1) << ": " << questions[i].text << "\n";
                    cout << "Answer: " << answers[i] << "\n";
                }
                AssessmentResult result = calculateRisk(answers);
                cout << "\nSummary: Score = " << result.totalScore << " | Risk Level = " << result.category << "\n";
                break;
            }
            case 3: {
                if (!hasAssessment) {
                    cout << "\nNo assessment to export. Run option 1 first.\n";
                    break;
                }
                ofstream reportFile("gdpr_report.txt");
                if (!reportFile) {
                    cout << "Could not create file!\n";
                    break;
                }
                reportFile << "GDPR/AI Risk Assessment Report\n";
                reportFile << "Generated: " << __DATE__ << " " << __TIME__ << "\n\n";
                AssessmentResult result = calculateRisk(answers);
                reportFile << "FINAL RESULT:\n";
                reportFile << "Score: " << result.totalScore << "/12\n";
                reportFile << "Risk Level: " << result.category << "\n\n";
                reportFile << "DETAILED ANSWERS:\n";
                for (int i = 0; i < 8; ++i) {
                    reportFile << "Q" << (i+1) << ": " << questions[i].text << "\n";
                    reportFile << "Answer: " << answers[i] << "\n\n";
                }
                reportFile.close();
                cout << "Report saved as 'gdpr_report.txt'!\n";
                break;
            }
            default: 
                cout << "Invalid option. Use 1-4.\n";
        }
    }
    return 0;
}
