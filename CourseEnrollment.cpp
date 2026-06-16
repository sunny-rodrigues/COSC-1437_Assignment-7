//
// Name: Sunny Rodrigues
// Date: June 16, 2026
// Course: COSC 1437 C++ Programming Fundamentals II
// Desc: Chapter 7 Lab - Student Course Enrollment System
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// PART 4: Namespace definition
namespace EnrollmentSystem
{
    // PART 1: Enum and variable declaration
    enum courseType
    {
        ENGLISH,
        MATH,
        HISTORY,
        CPP,
        BIOLOGY,
        ART
    } currentCourse;

    // PART 2: typedef aliases
    typedef int StudentID;
    typedef double CreditHours;

    // Function prototypes
    void printCourse(courseType c);
    courseType readCourse();
    double calcTuition(CreditHours credits);
    void printStudentInfo(string fullName, string email,
                          courseType course,
                          StudentID id,
                          CreditHours credits);
}

using namespace EnrollmentSystem;

// PART 1b: printCourse
void EnrollmentSystem::printCourse(courseType c)
{
    switch (c)
    {
        case ENGLISH:
            cout << "English Composition";
            break;
        case MATH:
            cout << "College Algebra";
            break;
        case HISTORY:
            cout << "U.S. History";
            break;
        case CPP:
            cout << "C++ Programming";
            break;
        case BIOLOGY:
            cout << "General Biology";
            break;
        case ART:
            cout << "Art Appreciation";
            break;
        default:
            cout << "Unknown Course";
    }
}

// PART 1c: readCourse
EnrollmentSystem::courseType EnrollmentSystem::readCourse()
{
    string input;

    cout << "Enter course (english/math/history/cpp/biology/art): ";
    cin >> input;

    if (input == "english")
        return ENGLISH;
    else if (input == "math")
        return MATH;
    else if (input == "history")
        return HISTORY;
    else if (input == "cpp")
        return CPP;
    else if (input == "biology")
        return BIOLOGY;
    else if (input == "art")
        return ART;
    else
    {
        cout << "Invalid course entered. Defaulting to English Composition.\n";
        return ENGLISH;
    }
}

// PART 2: calcTuition
double EnrollmentSystem::calcTuition(CreditHours credits)
{
    return credits * 150.00;
}

// PART 3b: printStudentInfo
void EnrollmentSystem::printStudentInfo(
    string fullName,
    string email,
    courseType course,
    StudentID id,
    CreditHours credits)
{
    cout << "\n--- Enrollment Summary ---\n";
    cout << "Student Name: " << fullName << endl;
    cout << "Student ID: " << id << endl;
    cout << "Email: " << email << endl;

    cout << "Course: ";
    printCourse(course);
    cout << endl;

    cout << fixed << setprecision(2);
    cout << "Credit Hours: " << credits << endl;
    cout << "Tuition: $" << calcTuition(credits) << endl;
}

int main()
{
    // Welcome Banner
    string line = "=====================================";
    string banner =
        line + "\nStudent Course Enrollment System\n" + line;

    cout << banner << endl;

    // PART 3: String operations
    string firstName, lastName, fullName;
    string emailUser, email;

    cout << "\nEnter first name: ";
    cin >> firstName;

    cout << "Enter last name: ";
    cin >> lastName;

    // Concatenation
    fullName = firstName + " " + lastName;
    cout << "\nFull Name: " << fullName << endl;

    // length()
    cout << "Number of characters: "
         << fullName.length() << endl;

    // find()
    size_t spacePos = fullName.find(' ');
    cout << "Space found at position: "
         << spacePos << endl;

    // substr()
    cout << "First name extracted: "
         << fullName.substr(0, spacePos)
         << endl;

    // at()
    cout << "First initial: "
         << fullName.at(0)
         << endl;

    cout << "\nEnter email username (e.g. jsmith): ";
    cin >> emailUser;

    // empty()
    if (emailUser.empty())
    {
        cout << "Email username cannot be empty.\n";
        emailUser = "student";
    }

    // insert()
    email = emailUser;
    email.insert(email.length(), "@sanjac.edu");
    cout << "After insert: "
         << email << endl;

    // replace()
    size_t pos = email.find("sanjac");
    if (pos != string::npos)
    {
        email.replace(pos, 6, "SanJac");
    }

    cout << "After replace: "
         << email << endl;

    // erase()
    email += "!";
    cout << "Before erase: "
         << email << endl;

    email.erase(email.length() - 1, 1);

    cout << "After erase: "
         << email << endl;

    // compare()
    string lastName2 = "Smith";

    int compareResult = lastName.compare(lastName2);

    if (compareResult < 0)
        cout << lastName
             << " comes before "
             << lastName2
             << " alphabetically.\n";
    else if (compareResult > 0)
        cout << lastName
             << " comes after "
             << lastName2
             << " alphabetically.\n";
    else
        cout << "The last names are the same.\n";

    // PART 1: Enum operations
    
   courseType selectedCourse = readCourse();

    cout << "You selected: ";
    printCourse(selectedCourse);
    cout << endl;

    // Assign MATH then advance by one
    currentCourse = MATH;

    cout << "\nStarting with: ";
    printCourse(currentCourse);
    cout << endl;

    currentCourse =
        static_cast<courseType>(
            static_cast<int>(currentCourse) + 1);

    cout << "After advancing by one: ";
    printCourse(currentCourse);
    cout << endl;

    // Advance chosen course if possible
    if (currentCourse != ART)
    {
        courseType nextCourse =
            static_cast<courseType>(
                static_cast<int>(currentCourse) + 1);

        cout << "Next course: ";
        printCourse(nextCourse);
        cout << endl;
    }

    // For loop through all courses
    cout << "\nAll Courses:\n";

    for (int i = ENGLISH; i <= ART; i++)
    {
        printCourse(static_cast<courseType>(i));
        cout << endl;
    }

    // Compare two courseType variables
    courseType c1 = HISTORY;
    courseType c2 = BIOLOGY;

    if (c1 < c2)
    {
        cout << "\n";
        printCourse(c2);
        cout << " comes later in the list than ";
        printCourse(c1);
        cout << "." << endl;
    }

    // PART 2: Tuition
    CreditHours hours;
    StudentID sid = 10045;

    cout << "\nEnter credit hours: ";
    cin >> hours;

    cout << fixed << setprecision(2);
    cout << "Tuition Cost: $"
         << calcTuition(hours)
         << endl;
         
    // Summary
    printStudentInfo(
        fullName,
        email,
        currentCourse,
        sid,
        hours);

    // PART 4 DEMO
    cout << "\nExample of scope resolution operator: ";
    EnrollmentSystem::printCourse(EnrollmentSystem::CPP);
    // Using full scope resolution to explicitly access
    // members from the EnrollmentSystem namespace.

    cout << endl;

    return 0;
}
