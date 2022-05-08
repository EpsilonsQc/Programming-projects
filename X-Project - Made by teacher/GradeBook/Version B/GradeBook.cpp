#include "GradeBook.h"
#include <string>

int GradeBook::a = 0;

GradeBook::GradeBook(const std::string& name, const std::array<int, NB_STUDENTS>& gradesArray) :
    name(name), 
    grades(gradesArray) 
{
}

// function to set the course name
void GradeBook::setCourseName(const std::string& name)
{
    this->name = name; // store the course name
}

// function to retrieve the course name
const std::string& GradeBook::getCourseName() const
{
    return name;
}

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
    // call getCourseName to get the name of this GradeBook's course
    std::cout << "Welcome to the grade book for\n" << getCourseName()
        << "!" << std::endl;
}

// perform various operations on the data (none modify the data)
void GradeBook::processGrades() const
{
    outputGrades(); // output grades array

    // call function getAverage to calculate the average grade
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "\nClass average is " << getAverage() << std::endl;

    // call functions getMinimum and getMaximum
    std::cout << "Lowest grade is " << getMinimum()
        << "\nHighest grade is " << getMaximum() << std::endl;

    outputBarChart(); // display grade distribution chart
}

// find minimum grade
int GradeBook::getMinimum() const
{
    int lowGrade{ 100 }; // assume lowest grade is 100

    // loop through grades array
    for (int grade : grades)
    {
        // if current grade lower than lowGrade, assign it to lowGrade
        if (grade < lowGrade)
        {
            lowGrade = grade; // new lowest grade
        }
    }

    return lowGrade; // return lowest grade
}

// find maximum grade
int GradeBook::getMaximum() const
{
    int highGrade{ 0 }; // assume highest grade is 0

    // loop through grades array
    for (int grade : grades)
    {
        // if current grade higher than highGrade, assign it to highGrade
        if (grade > highGrade)
        {
            highGrade = grade; // new highest grade
        }
    }

    return highGrade; // return highest grade
}

// determine average grade for test
double GradeBook::getAverage() const
{
    int total{ 0 }; // initialize total

    // sum grades in array
    for (int grade : grades)
    {
        total += grade;
    }

    // return average of grades
    return static_cast<double>(total) / grades.size();
}

// output bar chart displaying grade distribution
void GradeBook::outputBarChart() const
{
    std::cout << "\nGrade distribution:" << std::endl;

    // stores frequency of grades in each range of 10 grades
    const size_t frequencySize{ 11 };
    std::array<unsigned int, frequencySize> frequency{}; // init to 0s

    // for each grade, increment the appropriate frequency
    for (int grade : grades)
    {
        ++frequency[grade / 10];
    }

    // for each grade frequency, print bar in chart
    for (size_t count{ 0 }; count < frequencySize; ++count)
    {
        // output bar labels ("0-9:", ..., "90-99:", "100:")
        if (0 == count)
        {
            std::cout << "  0-9: ";
        }
        else if (10 == count)
        {
            std::cout << "  100: ";
        }
        else
        {
            std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
        }

        // print bar of asterisks
        for (unsigned int stars{ 0 }; stars < frequency[count]; ++stars)
        {
            std::cout << '*';
        }

        std::cout << std::endl; // start a new line of output
    }
}

// output the contents of the grades array
void GradeBook::outputGrades() const
{
    std::cout << "\nThe grades are:\n\n";

    // output each student's grade
    for (size_t i{ 0 }; i < grades.size(); ++i)
    {
        std::cout << "Student " << std::setw(2) << i + 1 << ": "
            << std::setw(3) << grades[i] << std::endl;
    }

    //int i = 1;
    //for (int grade : grades)
    //{
    //    std::cout << "Student " << std::setw(2) << i++ << ": "
    //        << std::setw(3) << grade << std::endl;
    //}
}