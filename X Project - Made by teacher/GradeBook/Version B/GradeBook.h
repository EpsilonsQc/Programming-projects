// Fig. 7.13: GradeBook.h
// Definition of class GradeBook that uses an array to store test grades.

#ifndef GRADEBOOK
#define GRADEBOOK


#include <string> 
#include <array>
#include <iostream> 
#include <iomanip>

class GradeBook 
{
public:
   static const size_t NB_STUDENTS = 10; 
   static int a;

   GradeBook(const std::string&, const std::array<int, NB_STUDENTS>&);

   void setCourseName(const std::string& name);
   const std::string& getCourseName() const;

   void displayMessage() const;
   void processGrades() const;

private:
	int getMinimum() const;
	int getMaximum() const;
	double getAverage() const;
	void outputBarChart() const;
	void outputGrades() const;

private:
   std::string name;
   std::array<int, NB_STUDENTS> grades;
};

#endif // !GRADEBOOK



/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
