#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
typedef int type;
class ArrayList{
private:
enum {max=20};
type a[max];
int length;
public:
ArrayList();
int getlength(){return length;};
type getvalueat(int id);
int Find(type target);
bool isempty() const;
bool isfull() const;
bool Insert(int id,type target);
bool Insert(type target);
bool Delete(type target);
};
#endif
