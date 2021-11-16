﻿// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class Lib {
public:
    /// <summary>
    /// For making strings print one character at a time
    /// </summary>
    /// <param name="msg">The string that will be printed.<para>does not work with the "value: {0}",var method, use "value: "+var</para></param>
    /// <param name="scrollTime">Time between each character being printed in thousands of a second.</param>
    /// <param name="finishTime">Time after the string is finished in thousands of a second.</param>
    /// <param name="lineBreak">How many times \n is sent AFTER msg</param>
    /// <param name="tabs">How many times \t is sent BEFORE msg</param>
    void Scroll(string msg, unsigned int scrollTime = 30, unsigned int finishTime = 1000, unsigned int lineBreak = 1, unsigned int tabs = 1) {
        for (unsigned int  i = 0; i < tabs; i++) {
            cout << "\t";
        }

        for (unsigned int i = 0; i < msg.length(); i++) {
            this_thread::sleep_for(std::chrono::milliseconds(scrollTime));
            cout << msg[i];
        }

        for (unsigned int  i = 0; i < lineBreak; i++) {
            cout << "\n";
        }
        this_thread::sleep_for(std::chrono::milliseconds(finishTime));
    }

    void BasicBox(string msg) {
        cout << "\t ";
        for (unsigned int i = 0; i < msg.length() + 1; i++)
        {
            Scroll("_", 2, 0, 0, 0);
        }
        Scroll("_\n\t| ", 2, 0, 0, 0);
        Scroll(msg, 5, 10, 0, 0);
        Scroll(" |\n\t|", 2, 0, 0, 0);
        for (unsigned int i = 0; i < msg.length() + 2; i++)
        {
            Scroll("_", 2, 0, 0, 0);
        }
        Scroll("|", 30, 1000, 1, 0);
    }
};

class DickingAbout {
Lib _Lib;
public:
    int AwfulTimeCalculator() {
#pragma region main shit that actually works good
        string name;
#pragma endregion

        //---------------
        tm then{};
        chrono::system_clock::time_point inpTime;
        cout << "enter\nyear month day\n";
        cin >> then.tm_year >> then.tm_mon >> then.tm_mday;

        //cc now contains the input date as a time_point

        //---------------------------

        auto today = std::chrono::system_clock::now();

        cout << "today: " << then.tm_year;

        std::chrono::duration<double> elapsed_years = (today - inpTime) / 31536000;

        std::cout << "\nelapsed time: " << elapsed_years.count() << "s\n";

        //----------------------------

        const auto p1 = std::chrono::system_clock::now();
        const auto p2 = p1 - std::chrono::hours(24);

        std::time_t today_time = std::chrono::system_clock::to_time_t(p1);

#pragma warning(disable:4996) //stops the ide complaining about ctime's depreciation
        std::cout << "today: " << std::ctime(&today_time);

        //cout << today_time - then;

        /*
        typedef std::chrono::high_resolution_clock Time;
        typedef std::chrono::hours h;
        typedef std::chrono::duration<float> fsec;
        auto t0 = Time::now();
        auto t1 = Time::now();
        fsec fs = t1 - t0;
        h d = std::chrono::duration_cast<h>(fs);
        std::cout << fs.count() << "h\n";
        std::cout << d.count() << "ms\n";
        */
    }

    int Pointers() {
        int foo = 2;            //make foo int
        int* bar = &foo;        //bar point to foo
        int** roe = &bar;       //roe points to bar which points to foo
        //you can stack infinitely
        //pointers only work on the same data type

        cout << foo << "\t" << *bar << "\t" << **roe << endl;
        //can all be used to reference what they point at
        cout << foo << "\t" << bar << "\t" << roe << endl;
        //this prints foo value, then foo's memory location, the bar's memory location

        //initialiser variables go in a stack (stack memory)
        //runtime variables are yeeted into random places (heap memory)
        //The 'new' keyword reserves some ram space, but doesn't name it, so we need pointers to reference it

        int* a = new int;   //reserves a location
        delete a;           //unreserves it again
        int* b = NULL;      //without assignment, pointers actually point at shit. set to null to be safe.


        /*
        char* myIntPointer; //create a pointer to an integer
        char myInt = 'a'; //create an integer variable​
        myIntPointer = &myInt; //direct pointer at integer​
        cout << "The value of myInt is : " << *myIntPointer; //print value through pointer
        */

        return 0;
    }
};

class DebugExcersises {
 Lib _Lib;
public:
    void DB8() {

        int secretNumber = rand() % 10; //random number from 1 to 9
        int guess = 0;
        int counter = 5;

        while (counter > 0) {

            cout << "\nEnter a guess (1-10) you have " << counter << " tries: ";
            cin >> guess;

            if (guess == secretNumber) {
                cout << "\nYOU WIN!";
                counter = 0;
            }
            else {
                cout << "\nWrong, try again...";
            }
            counter--;
        }

        if (guess != secretNumber) {
            cout << "\nYOU LOSE!";
        }
    }

    /// <summary>
    /// Dynamically adds contacts using pointers and structs
    /// </summary>
    void MemoryManagement23() {
        struct contact {
            int age;
            string name;
        };

        contact* a = NULL;
        char ans;

        _Lib.BasicBox("Create new contact? (y/n)");
        cin >> ans;

        if (ans == 'y') {
            a = new contact;
            _Lib.BasicBox("Name:");
            string name;
            cin >> name;
            a->name = name;

            _Lib.BasicBox("Age:");
            int age;
            cin >> age;
            a->age = age;
        }

    }

    /// <summary>
    /// A linked list
    /// </summary>
    void MemoryManagement26() {
    
        struct DataElement {
            DataElement* next;
            int value;
            DataElement* previous;
        };

        char ans;
        DataElement* _new = new DataElement;
        DataElement* head = _new;
        DataElement* last = _new;
        
        _Lib.BasicBox("input header value");
        cout << "> ";

        cin >> _new->value;
        _new->previous = NULL;

        _Lib.BasicBox("Create new Entry? (y/n)");
        cout << "> ";

        cin >> ans;

        bool firstflag = true;
        
        while (ans == 'y') {

            _new = new DataElement;

            if (firstflag) {

                head->next = _new;
                firstflag = false;
            }

            last->next = _new;
            _new->previous = last;

            _Lib.BasicBox("input new value");
            cout << "> ";

            cin >> _new->value;

            _Lib.BasicBox("Create new Entry? (y/n)");
            cout << "> ";

            cin >> ans;

            last = _new;
        }

        DataElement* output = head;
        cout << endl << output->value << endl;

        do {
            output = output->next;
            cout << output->value << endl;
        } while (output != last);

    }

};

int main()
{
    cout << "Hello World!\n";
    Lib _Lib;
    DickingAbout _DAB;
    DebugExcersises _Exer;

    //_DBE.DB8();
    //_DAB.Pointers();
    _Exer.MemoryManagement26();

        /*
        string inp;
        _Lib.Scroll("Input:");
        cin >> inp;
        _Lib.Scroll(inp);
        _Lib.BasicBox(inp);
        */
};