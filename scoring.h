#ifndef SCORING_H
#define SCORING_H
#include <string>

struct AssessmentResult {
    int totalScore;
    std::string category;
};

AssessmentResult calculateRisk(const int answers[8]);

#endif
