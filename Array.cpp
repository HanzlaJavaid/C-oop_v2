// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $
//
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Array.h"

// Default constructor: create an empty array.
Array::Array(void)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

//Modified constructor initializer lists so that each member variable is initialized on its own line.
  : data_(nullptr)
  , cur_size_(0) 
  , max_size_(0)
{
}

// Constructor with specified length.
Array::Array(size_t length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

//Modified constructor initializer lists so that each member variable is initialized on its own line.
  : cur_size_(length)
  , max_size_(length)
{
  if (length > 0)
    data_ = new char[length];
  else
    data_ = nullptr;
}

// Constructor with specified length and fill value.
Array::Array(size_t length, char fill)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

//Modified constructor initializer lists so that each member variable is initialized on its own line.
  : cur_size_(length)
  , max_size_(length)
{
  if (length > 0)
  {
    data_ = new char[length];
    for (size_t i = 0; i < length; ++i)
      data_[i] = fill;
  }
  else
    data_ = nullptr;
}

// Copy constructor.
Array::Array(const Array & arr)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

//Modified constructor initializer lists so that each member variable is initialized on its own line.
  : cur_size_(arr.cur_size_)
  , max_size_(arr.max_size_)
{
  if (max_size_ > 0)
  {
    data_ = new char[max_size_];
    for (size_t i = 0; i < cur_size_; ++i)
      data_[i] = arr.data_[i];
    // Note: remaining capacity is left uninitialized.
  }
  else
    data_ = nullptr;
}

// Destructor.
Array::~Array(void)
{
  delete [] data_;
}

// Assignment operator.
const Array & Array::operator=(const Array & rhs)
{  
  if (this != &rhs)
  {
    delete [] data_;
    cur_size_ = rhs.cur_size_;
    max_size_ = rhs.max_size_;

    if (max_size_ > 0)
    {
      data_ = new char[max_size_];
      for (size_t i = 0; i < cur_size_; ++i)
        data_[i] = rhs.data_[i];
    }
    else
      data_ = nullptr;
  }
  return *this;
}

// Non-const subscript operator.
char & Array::operator[](size_t index)
{
  if (index >= cur_size_)
    throw std::out_of_range("Array index out of range");
  return data_[index];
}

// Const subscript operator.
const char & Array::operator[](size_t index) const
{
  if (index >= cur_size_)
    throw std::out_of_range("Array index out of range");
  return data_[index];
}

// Get element at index.
char Array::get(size_t index) const
{
  if (index >= cur_size_)
    throw std::out_of_range("Array index out of range");
  return data_[index];
}

// Set element at index.
void Array::set(size_t index, char value)
{
  if (index >= cur_size_)
    throw std::out_of_range("Array index out of range");
  data_[index] = value;
}

// Resize the array to new_size.
void Array::resize(size_t new_size)
{
  if (new_size == cur_size_)
    return;

  char* new_data = nullptr;
  if (new_size > 0)
  {
    new_data = new char[new_size];
    // Copy the lesser of new_size and current size elements.
    size_t limit = (new_size < cur_size_) ? new_size : cur_size_;
    for (size_t i = 0; i < limit; ++i)
      new_data[i] = data_[i];
    // New elements (if any) remain uninitialized.
  }
  delete [] data_;
  data_ = new_data;
  cur_size_ = new_size;
  max_size_ = new_size;
}

// Shrink the array to reclaim unused space.
void Array::shrink(void)
{
  if (cur_size_ < max_size_)
  {
    if (cur_size_ == 0)
    {
      delete [] data_;
      data_ = nullptr;
      max_size_ = 0;
    }
    else
    {
      char* new_data = new char[cur_size_];
      for (size_t i = 0; i < cur_size_; ++i)
        new_data[i] = data_[i];
      delete [] data_;
      data_ = new_data;
      max_size_ = cur_size_;
    }
  }
}

// Find the first occurrence of ch (search from index 0).
int Array::find(char ch) const
{
  for (size_t i = 0; i < cur_size_; ++i)
  {
    if (data_[i] == ch)
      return static_cast<int>(i);
  }
  return -1;
}

// Find the first occurrence of ch starting at index start.
int Array::find(char ch, size_t start) const
{
  if (start >= cur_size_)
    throw std::out_of_range("Start index out of range in find()");
  for (size_t i = start; i < cur_size_; ++i)
  {
    if (data_[i] == ch)
      return static_cast<int>(i);
  }
  return -1;
}

// Equality operator.
bool Array::operator==(const Array & rhs) const
{
    // COMMENT Check for self comparison first.
  
    // Added a self-comparison check in the equality operator (operator==) to quickly handle cases where an object is compared with itself.

  if (this == &rhs)
    return true;  

  if (cur_size_ != rhs.cur_size_)
    return false;

  if (cur_size_ != rhs.cur_size_)
    return false;
  for (size_t i = 0; i < cur_size_; ++i)
  {
    if (data_[i] != rhs.data_[i])
      return false;
  }
  return true;
}

// Inequality operator.
bool Array::operator!=(const Array & rhs) const
{
  return !(*this == rhs);
}

// Fill the array with character ch.
void Array::fill(char ch)
{
  for (size_t i = 0; i < cur_size_; ++i)
    data_[i] = ch;
}

// Reverse the contents of the array.
void Array::reverse(void)
{
  for (size_t i = 0; i < cur_size_ / 2; ++i)
  {
    char temp = data_[i];
    data_[i] = data_[cur_size_ - 1 - i];
    data_[cur_size_ - 1 - i] = temp;
  }
}

// Return a slice from index begin to the end of the array.
Array Array::slice(size_t begin) const
{
  if (begin > cur_size_)
    throw std::out_of_range("Slice begin index out of range");
  size_t new_length = cur_size_ - begin;
  Array new_array(new_length);
  for (size_t i = 0; i < new_length; ++i)
    new_array.data_[i] = data_[begin + i];
  return new_array;
}

// Return a slice from index begin to index end (end not included).
Array Array::slice(size_t begin, size_t end) const
{
  if (begin > end || end > cur_size_)
    throw std::out_of_range("Invalid slice indices");
  size_t new_length = end - begin;
  Array new_array(new_length);
  for (size_t i = 0; i < new_length; ++i)
    new_array.data_[i] = data_[begin + i];
  return new_array;
}
