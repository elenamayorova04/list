#ifndef __NODE_H__
#define __NODE_H__

template <class T>
class TListNode
{
protected:
  TListNode<T>* next;
  TListNode<T>* prev;
  T* data;
public:
  TListNode();
  TListNode(TListNode<T>* n, TListNode<T>* p, T* d);
  TListNode(const TListNode<T> &p);
  TListNode(const TListNode<T> &&p);
  ~TListNode();
  
  TListNode<T>* getNext();
  TListNode<T>* getPrev();
  T* getData();
  
  void setNext(TListNode<T>* n);
  void setPrev(TListNode<T>* p);
  void setData(T* d);

  TListNode<T>& operator = (const TListNode<T>& p);
};

#endif


template<class T>
TListNode<T>::TListNode()
{
  next = nullptr;
  prev = nullptr;
  data = nullptr;
}

template<class T>
TListNode<T>::TListNode(TListNode<T>* n, TListNode<T>* p, T* d)
{
  next = n;
  prev = p;
  data = d;
}

template<class T>
TListNode<T>::TListNode(const TListNode<T>& p)
{
  next = p.next;
  prev = p.prev;
  data = p.data;
}

template<class T>
TListNode<T>::TListNode(const TListNode<T>&& p)
{
  next = p.next;
  prev = p.prev;
  data = p.data;

  p.next = nullptr;
  p.prev = nullptr;
  p.data = nullptr;
}

template<class T>
TListNode<T>::~TListNode()
{
  next = nullptr;
  prev = nullptr;
  data = nullptr;
}


template<class T>
TListNode<T>* TListNode<T>::getNext()
{
  return next;
}

template<class T>
TListNode<T>* TListNode<T>::getPrev()
{
  return prev;
}

template<class T>
T* TListNode<T>::getData()
{
  return data;
}

template<class T>
void TListNode<T>::setNext(TListNode<T>* n)
{
  next = n;
}

template<class T>
void TListNode<T>::setPrev(TListNode<T>* p)
{
  prev = p;
}

template<class T>
void TListNode<T>::setData(T* d)
{
  data = d;
}

template <class T>
TListNode<T>& TListNode<T>::operator = (const TListNode<T>& p)
{
  next = p.next;
  prev = p.prev;
  data = p.data;

  return *this;
}