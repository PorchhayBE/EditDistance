// Copyright[2022] <PorchhayBe>

/**
 * EDistance.cpp - DNA Alignment
 * 
 * Date: 04/5/2022
 * 
 */

#pragma once

#include <algorithm>
#include <fstream>
#include <string>

class EDistance {
 private:
    int ** arr;
    int sizeA, sizeB;
    std::string A, B;
 public:
    EDistance(std::string a, std::string b);
    static int penalty(char a, char b);
    static int min(int a, int b, int c);
    int optDistance();
    std::string alignment();
    ~EDistance();
};
