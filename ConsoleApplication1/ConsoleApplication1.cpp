// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

class Main {

    int main()
    {
        string inp;
        cout << "Hello World!\n";

        Scroll("Input:");
        cin >> inp;
        Scroll(inp);
    }

    /// <summary>
    /// For making strings print one character at a time
    /// </summary>
    /// <param name="msg">The string that will be printed.<para>does not work with the "value: {0}",var method, use "value: "+var</para></param>
    /// <param name="scrollTime">Time between each character being printed in thousands of a second.</param>
    /// <param name="finishTime">Time after the string is finished in thousands of a second.</param>
    /// <param name="lineBreak">How many times \n is sent AFTER msg</param>
    /// <param name="tabs">How many times \t is sent BEFORE msg</param>
    void Scroll(string msg, int scrollTime = 30, int finishTime = 1000, int lineBreak = 1, int tabs = 1) {
        for (int i = 0; i < tabs; i++) {
            //write tabs
        }

        for (int i = 0; i < msg.length(); i++) {
            this_thread::sleep_for(std::chrono::milliseconds(200));
            cout << msg[i];
        }

        for (int i = 0; i < lineBreak; i++) {
            //write newline
        }
        this_thread::sleep_for(std::chrono::milliseconds(finishTime));
    }
};