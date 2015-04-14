
#ifndef DATATYPES_H
#define DATATYPES_H

class ufix
{
public:
  ufix(int intW, int fracW);
  ufix operator=(const unsigned int value);
  ufix operator=(const ufix &other);
  ufix operator+(const ufix &other) const;
  ufix operator*(const ufix &other) const;
  double asDouble(void) const;
  unsigned int fixedValue(void) const;

private:
  unsigned int intValue(void) const;
  unsigned int fracValue(void) const;

  int intWidth;
  int fracWidth;

  unsigned long int mValue;
};


#endif

