#ifdef CONFIG_H
#include "../config.h"
#endif

typedef vector<NestedInteger>::const_iterator it_type;

class NestedIterator {
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    begins.push(nestedList.begin());
    ends.push(nestedList.end());
  }

  int next() { return (begins.top()++)->getInteger(); }

  bool hasNext() {
    while (!begins.empty()) {
      if (begins.top() == ends.top()) {
        begins.pop();
        ends.pop();
        continue;
      }

      auto x = begins.top();
      if (x->isInteger()) {
        return true;
      }

      begins.top()++;
      begins.push(x->getList().begin());
      ends.push(x->getList().end());
    }
    return false;
  }

private:
  stack<it_type> begins, ends;
};
