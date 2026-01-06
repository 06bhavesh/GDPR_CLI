#include "questions.h"
using namespace std;

Question questions[8] = {
    {1, "Do you actually have a legal reason to use people's data?", 3},
    {2, "Do you have a list of the data you're going to use and why?", 2},
    {3, "Is this AI doing anything like profiling people or using health data", 2},
    {4, "If doing profiling/sensitive data, is DPIA done?", 3},
    {5, "Is the data protected (passwords, encryption)?", 2},
    {6, "If data leaks, do you know what to do?", 2},
    {7, "How likely is something bad to happen? (1=low, 3=high)", 1},
    {8, "The impact if something happens. (1=low, 3=high)", 1}
};
