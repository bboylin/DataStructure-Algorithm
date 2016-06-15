#ifndef STACK_H_
#define STACK_H_
typedef int type;
class mystack{
private:
enum{max=10};
type items[max];
int top;
public:
mystack();
bool isempty() const;
bool isfull() const;
bool pop(type&);
bool push(type);
int length() const;
type getvalueat(int);
int getmax() const {return max;};
};
#endif
