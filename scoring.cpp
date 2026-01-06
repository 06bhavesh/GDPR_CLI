#include "scoring.h"


AssessmentResult calculateRisk(const int answers[8]) {
    AssessmentResult result{};
    int score = 0;
    if (answers[0] == 0) score += 4;
    if (answers[1] == 0) score += 2;
    bool highRiskAI = (answers[2] == 1);
    if (highRiskAI && answers[3] == 0) score += 4;
    if (answers[4] == 0) score += 2;
    if (answers[5] == 0) score += 2;

    int aiRisk = answers[6] * answers[7];
    if (aiRisk >= 6) score += 3;
    else if (aiRisk >= 3) score += 1;

    result.totalScore = score;
    if (score <= 3) result.category = "Low";
    else if (score <= 6) result.category = "Medium";
    else result.category = "High";

    return result;
}
