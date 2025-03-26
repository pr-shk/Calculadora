#ifndef MESSAGES_H
#define MESSAGES_H
#include <string>

struct Messages {
    const std::string enter_numbers; //1
    const std::string example; //2
    //const std::string press_enter;
    const std::string numbers_only; //3
    const std::string continue_operation; //4
    const std::string invalid_option; //5
    const std::string new_operation; //6
    const std::string program_finished; //7
    const std::string invalid_operator; //8
    const std::string division_zero; //9
    const std::string partial_result; //10
    const std::string final_result; //11
    const std::string enter_operator; //12
    const std::string choose_language; //13
};

extern const Messages EN;  // Inglês
extern const Messages PT;  // Português
extern const Messages ES;  // Espanhol

#endif