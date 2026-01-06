#ifndef QUESTIONS_H
#define QUESTIONS_H
#include <string>

struct Question {
    int id;
    std::string text;
    int weight;
};

extern Question questions[8];

#endif
