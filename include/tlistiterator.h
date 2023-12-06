#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "tlist.h"
#include "tlistnode.h"

template <class T>
class TListIterator
{
protected:
  TList<T>& list;
  TListNode<T>* cur;
public:
  TListIterator(TList<T>& l, TListNode<T>* p);
  TListIterator(const TListIterator<T>& p);
  TListIterator(TListIterator<T>&& p);
  ~TListIterator();

  void pushAfter(T* a);
  void pushBefore(T* a);

  getBegin();
  getEnd();

  TListIterator<T>& operator = (const TListIterator<T>& p);
  TListIterator<T>& operator = (const TListIterator<T>&& p);

  TListIterator<T>& operator ++ ();
  TListIterator<T>& operator -- ();

  bool operator == (const TListIterator<T>& p);
  bool operator != (const TListIterator<T>& p);
};

#endif

template<class T>
TListIterator<T>::TListIterator(TList<T>& l, TListNode<T>* p)
{
  list = l;
  cur = p;
}

template<class T>
TListIterator<T>::TListIterator(const TListIterator<T>& p)
{
  list = p.list;
  cur = p.cur;
}

template<class T>
TListIterator<T>::TListIterator(TListIterator<T>&& p)
{
  list = p.list;
  cur = p.cur;
}

template<class T>
TListIterator<T>::~TListIterator()
{
  cur = nullptr;
}

template<class T>
void TListIterator<T>::pushAfter(T* a)
{
  TListNode<T>* node = new TListNode<T>(cur->getNext(), cur, a);
  cur->setNext(node);
  cur->getNext()->setPrev(node);
  list.count++;
}

template<class T>
void TListIterator<T>::pushBefore(T* a)
{
  TListNode<T>* node = new TListNode<T>(cur->getPrev(), cur, a);
  cur->setPrev(node);
  cur->getPrev()->setNext(node);
  list.count--;
}

template<class T>
TList<T>::getBegin()
{
  return TListIterator<T>(*this, begin);
}

template<class T>
TList<T>::getEnd()
{
  return TListIterator<T>(*this, end);
}

template<class T>
TListIterator<T>& TListIterator<T>::operator = (const TListIterator<T>& p)
{
  if (this != &p)
  {
    list = p.list;
    cur = p.cur;
    return *this;
  }
  else
    return *this;
}

template<class T>
TListIterator<T>& TListIterator<T>::operator = (const TListIterator<T>&& p)
{
  list = p.list;
  cur = p.cur;
  p.cur = nullptr;
  return *this;

}

template<class T>
TListIterator<T>& TListIterator<T>::operator ++ ()
{
  if (cur != nullptr)
  {
    cur = cur->getNext();
    if (cur == begin)
      cur = nullptr;
  }
  return *this;
}

template<class T>
TListIterator<T>& TListIterator<T>::operator -- ()
{
  if (cur != nullptr)
  {
    cur = cur->getPrev();
    if (cur == end)
      cur = begin;
  }
  return *this;
}

template<class T>
bool TListIterator<T>::operator == (const TListIterator<T>& p)
{
  if ((cur = p.cur) && (&list = &p.list))
    return true;
  else return false;
}

template<class T>
bool TListIterator<T>::operator != (const TListIterator<T>& p)
{
  return !(*this == p);
}