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
std::string parseDelimiters(const std::string& input) {
    std::string delimiters = ",";
    std::string numbersPart = input;

    if (input.substr(0, 2) == "//") {
        size_t newlinePos = input.find("\n");
        if (newlinePos != std::string::npos) {
            delimiters = input.substr(2, newlinePos - 2);
            numbersPart = input.substr(newlinePos + 1);
        }
    }
numbersPart = replaceDelimiters(numbersPart, delimiters);
    return numbersPart;
}

void checkForNegatives(const std::string& input) {
    std::stringstream ss(input);
    std::string segment;
    while (std::getline(ss, segment, ',')) {
        if (std::stoi(segment) < 0) {
            throw std::runtime_error("negatives not allowed");
        }
    }
}
