#include "../config.h"
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  struct Data;
  Data* data;

 public:
  Iterator(const std::vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const std::vector<int>& nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    if (!has_peeked) {
      peek_element = Iterator::next();
      has_peeked = true;
    }

    return peek_element;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    if (!has_peeked) {
      return Iterator::next();
    }
    has_peeked = false;
    return peek_element;
  }

  bool hasNext() const { return has_peeked || Iterator::hasNext(); }

 private:
  int peek_element;
  bool has_peeked;
};
