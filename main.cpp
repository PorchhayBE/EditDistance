// Copyright[2022] <PorchhayBe>

/**
 * main.cpp - DNA Alignment
 * 
 * Date: 04/5/2022
 * 
 */
#include <iostream>
#include <fstream>
#include <SFML/System.hpp>
#include "EDistance.h"

int main(int argc, char* argv[]) {
    // ifstream read from file
    std::ifstream textFile(argv[1]);
    std::string text1;
    std::string text2;
    // check if file is available
    if (!textFile.is_open()) {
        std::cout << "File does not exist\n";
        std::runtime_error("FileNotExist");
    }
    textFile >> text1;
    textFile >> text2;
    // Clock Time eslape
    sf::Clock clock;
    sf::Time t;
    EDistance a(text1, text2);
    int n = a.optDistance();
    // std::cout << "Edit distance = " << a.optDistance() << "\n";
    a.alignment();
    t = clock.getElapsedTime();
    std::cout << "Edit distance = " << n << "\n";
    std::cout << "Execution Time is " << t.asSeconds() << " seconds \n";
    return 0;
}
