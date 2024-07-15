#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include "StringCalculator.h"

std::string replaceDelimiters(const std::string& input, const std::string& delimiters) {
    std::string modifiedInput = input;
    std::replace_if(modifiedInput.begin(), modifiedInput.end(), [&](char c) {
        return c == '\n' || delimiters.find(c) != std::string::npos;
    }, ',');
    return modifiedInput;
}
