// Copyright[2022] <PorchhayBe>

/**
 * EDistance.cpp - DNA Alignment
 * 
 * Date: 04/5/2022
 * 
 */

#include "EDistance.h"
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

EDistance::EDistance(std::string a, std::string b) {
    // Default Constructor
    A = a;
    B = b;
    sizeA = a.size() + 1;
    sizeB = b.size() + 1;
    // Dynamic allocation array
    arr = new int* [sizeA];
    for (int i = 0; i < sizeA; i++) {
        arr[i] = new int[sizeB];
    }
}

EDistance::~EDistance() {
    // destructor
     for (int i = 0; i < sizeA; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}

int EDistance::penalty(char a, char b) {
    // return result of 2 char comparison
    if (a == b) {
        return 0;
    }
    return 1;
}

int EDistance::min(int a, int b, int c) {
    // using min function to get miminum of abc
    return std::min({a, b, c});
}

int EDistance::optDistance() {
    // Needleman–Wunsch algorithm
    for (int i = sizeA - 1; i >= 0; i--) {
        arr[i][sizeB - 1] = (sizeA - 1 - i) * 2;
    }
    for (int j = sizeB - 1; j >= 0; j--) {
        arr[sizeA - 1][j] = (sizeB - 1 - j) * 2;
    }
    for (int i = sizeA - 2; i >= 0; i--) {
        for (int j = sizeB - 2; j >= 0; j--) {
            int match = arr[i+1][j+1] + penalty(A[i], B[j]);
            int del = arr[i+1][j] + 2;
            int insert = arr[i][j+1] + 2;
            arr[i][j] = min(match, del, insert);
        }
    }
    return arr[0][0];
}

std::string EDistance::alignment() {
    std::string output = "";
    std::stringstream ss;
    int i = 0;
    int j = 0;
    // Needleman–Wunsch algorithm
    // Tracing route
    while ( i < sizeA - 1 || j < sizeB - 1 ) {
        int cost = penalty(A[i], B[j]);
        if ( i < sizeA  && j < sizeB  && arr[i][j] == arr[i+1][j+1] + cost ) {
            ss << output << A[i] << B[j] << cost;
            std::cout << A[i] << " " << B[j] << " " << cost << "\n";
            i++;
            j++;
        } else if ( i < sizeA && arr[i][j] == arr[i+1][j] + 2 ) {
            ss << output << A[i] << "-" << "2";
            std::cout << A[i] << " - " << "2" << "\n";
            i++;
        } else {
            ss << output << "-" << B[j] << "2";
            std::cout << "- " << B[j] << " " << "2" << "\n";
            j++;
        }
        ss >> output;
    }
    return output;
}
