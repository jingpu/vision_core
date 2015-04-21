#include "datatypes.h"

int max(int a, int b)
{
  return(a > b ? a : b);
}

ufix::ufix(int intW, int fracW)
{
  if(intW + fracW > 32){
    // TODO: we're in trouble
  }
  intWidth = intW;
  fracWidth = fracW;
}

ufix ufix::operator=(const unsigned int value)
{
  mValue = value;
}

ufix ufix::operator=(const ufix &other)
{
  unsigned int maxVal = (1 << intWidth) >> 1; // TODO: better way?
  unsigned int intVal;
  unsigned int fracVal;

  intVal = other.intValue() % maxVal;

  if(intVal != other.intValue()){
    // TODO: flag this somehow
  }

  // Truncate the fractional part
  //fracVal;

  mValue = intVal << fracWidth + fracVal;
}

ufix ufix::operator+(const ufix &other) const
{
  ufix result(max(intWidth, other.intWidth) + 1,
              max(fracWidth, other.fracWidth));
  result = mValue + other.mValue;

  return result;
}

double ufix::asDouble() const
{
  return (double)mValue / (1 << fracWidth);
}

unsigned int ufix::fixedValue() const
{
  return mValue;
}

unsigned int ufix::intValue() const
{
  return mValue >> fracWidth;
}

/* Returns the fractional component of the number 
... TODO explain what this does
*/
unsigned int ufix::fracValue() const
{
  return mValue % (1 << fracWidth);
}

