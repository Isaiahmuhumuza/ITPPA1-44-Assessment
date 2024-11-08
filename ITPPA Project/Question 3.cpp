#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

void runQuestion3() {
	int score;
	double totalScores = 0;
	int* studentScore = new int[5];
	cout << "Enter scores for 5 Students" << endl;

	for  (int i = 0; i < 5; i++){
		cout << "Enter score for  Student " << i + 1 << " : " << endl;
		cin >> score;
		studentScore[i] = score;
		totalScores += score;
	}

	for (int i = 0; i < 5; i++) {
		cout << "\nStudent " << i + 1 << ": " << studentScore[i] << endl;
	}
	
	double average = totalScores / 5;
	int max = *max_element(studentScore, studentScore + 5);
	int min = *min_element(studentScore, studentScore + 5);

	cout << "\nAverage Score: " << average<< endl;
	cout << "Highest Score: " << max << endl;
	cout << "Lowest Score: " << min << endl;

}