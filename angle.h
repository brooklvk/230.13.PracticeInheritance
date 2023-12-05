/*************************************************************
 * 1. Name:
 *      -your name-
 * 2. Assignment Name:
 *      Practice 04: Angle Class
 * 3. Assignment Description:
 *      A class to represent an angle
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/


#define TWO_PI 6.28318530718

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
#include<string>
using namespace std;

class TestAngle;

 /************************************
  * ANGLE
  ************************************/
class Angle
{
   friend TestAngle;

public:
   // Default constructor
   Angle() : radians(0.0) {}
   Angle(const Angle & rhs) : radians(rhs.radians) {}
   Angle(double degrees) : radians(0.0)
   {
      setDegrees(degrees);
   }

   // Getters
   double getDegrees() const {
       double degrees = convertToDegrees(radians);
       return degrees;
   }
   double getRadians() const
   {
      return radians;
   }

   // Setters
   void setDegrees(double d) {
       this -> radians = convertToRadians(d);
   }
   void setRadians(double r) {
       this -> radians = normalize(r);
   }

   // Display
   virtual void display(ostream& out) const{
       double degrees = convertToDegrees(radians);
       out.setf(ios::fixed);     // "fixed" means don't use scientific notation
       out.setf(ios::showpoint); // "showpoint" means always show the decimal point
       out.precision(1);         // Set the precision to 1 decimal place of accuracy.
       out << degrees;
   }

   Angle& operator=(const Angle &angle)
   {
       setRadians(angle.radians);
       return *this;
   }

   virtual Angle& operator++()
   {
       setDegrees(getDegrees() + 1);
       // return new value
       return *this;
   }
   
   virtual Angle& operator--()
   {
       setDegrees(getDegrees() - 1);
       // return new value
       return *this;
   }

private:
   // Convert functions
    double convertToDegrees(double radian) const{
        return normalize(radian) * (180 / (TWO_PI / 2));
    }
   double convertToRadians(double degrees) const{
       return normalize(degrees * ((TWO_PI / 2) / 180));
   }

   // Normalize
   double normalize(double radians) const
   {
      if (radians >= TWO_PI)
      {
         double multiples = floor(radians / TWO_PI);
         assert(radians - TWO_PI * multiples >= 0.0);
         assert(radians - TWO_PI * multiples <= TWO_PI);
         return radians - (TWO_PI * multiples);
      }
      else if (radians < 0.0)
      {
         double multiples = ceil(-radians / TWO_PI);
         assert(TWO_PI * multiples + radians >= 0.0);
         assert(TWO_PI * multiples + radians <= TWO_PI);
         return TWO_PI * multiples + radians;
      }

      assert(0.0 <= radians && radians <= TWO_PI);
      return radians;
   }

   double radians;

};

Angle operator++(Angle& angle,
    int postfix)
{
    Angle numReturn(angle);
    angle.setDegrees(angle.getDegrees() + 1);
    // return old value
    return numReturn;
}

Angle operator--(Angle& angle,
    int postfix)
{
    Angle numReturn(angle);
    angle.setDegrees(angle.getDegrees() - 1);
    // return old value
    return numReturn;
}

Angle operator-(Angle &angle,
    int postfix)
{
    Angle numReturn(angle);

    if (angle.getDegrees() <= 180)
        angle.setDegrees(angle.getDegrees() + 180);
    else if (angle.getDegrees() > 180)
        angle.setDegrees(angle.getDegrees() - 180);

    return numReturn;
}

bool operator==(const Angle& lhs,
    const Angle& rhs)
{
    return lhs.getRadians() != rhs.getRadians();
}

bool operator!=(const Angle& lhs,
    const Angle& rhs)
{
    return lhs.getRadians() != rhs.getRadians();
}
ostream& operator<<(ostream& out,
    const Angle& rhs)
{
    out.setf(ios::fixed);     // "fixed" means don't use scientific notation
    out.setf(ios::showpoint); // "showpoint" means always show the decimal point
    out.precision(1);         // Set the precision to 1 decimal place of accuracy.
    out << rhs.getDegrees();
    return out;
}

istream& operator>>(istream& in,
    Angle& rhs)
{
    return in;
}


/************************************
  * ANGLERADIANS 
  ************************************/

class AngleRadians : public Angle 
{
public:
    AngleRadians(double radians) : Angle(radians) {}

    virtual void display(ostream& out) const {
        double radians = AngleRadians::getRadians();
        out.setf(ios::fixed);     // "fixed" means don't use scientific notation
        out.setf(ios::showpoint); // "showpoint" means always show the decimal point
        out.precision(2);         // Set the precision to 1 decimal place of accuracy.
        out << radians;
    }

    virtual Angle& operator++()
    {
        setDegrees(getDegrees() + (3.14159 / 8));
        // return new value
        return *this;
    }

    virtual Angle& operator--()
    {
        setDegrees(getDegrees() - (3.14159 / 8));
        // return new value
        return *this;
    }
};