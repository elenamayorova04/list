#ifndef __LIST_H__
#define __LIST_H__

#include "tlistnode.h"

template <class T>
class TList
{
protected:
  TListNode<T>* begin;
  TListNode<T>* end;
  int count;
public:
  TList();
  TList(const TList<T>& p);
  TList(TList<T>&& p);
  ~TList();

  void pushBegin(T* a);
  void pushEnd(T* a);

  void deleteBegin();
  void deleteEnd();
	
	TListNode<T> getBegin();
  TListNode<T> getEnd();

  void clear();

  TList<T>& operator = (const TList<T>& p);
  TList<T>& operator = (const TList<T>&& p);
};

#endif

template<class T>
TList<T>::TList()
{
	begin = nullptr;
	end = nullptr;
	count = 0;
}

template<class T>
TList<T>::TList(const TList<T>& p)
{
	count = p.count;
	if (p.begin = nullptr)
	{
		begin = nullptr;
		end = nullptr;
	}
	else
	{
		begin = new TListNode<T>*[p.begin];
		TListNode<T>* tmpcopy = begin;
		TListNode<T>* tmp = p.begin;
		while (tmp->getNext() != p.begin)
		{
			TListNode<T>* temp = new TListNode<T>();
			temp->setPrev(tmpcopy);
			temp->setData(new T(*tmp->getNext()->getData()));
			tmpcopy->setNext(temp);
			tmpcopy = tmpcopy->getNext();
			tmp = tmp->getNext();
		}
		end = new TListNode<T>(begin, tmpcopy);
		new T(*tmp->getNext()->getData());
		begin->setPrev(end);
	}
}

template<class T>
TList<T>::TList(TList<T>&& p)
{
	begin = p.begin;
	end = p.end;
	count = p.count;
	p.begin = nullptr;
	p.end = nullptr;
	p.count = 0;
}

template<class T>
TList<T>::~TList()
{
	begin = nullptr;
	end = nullptr;
	count = 0;
}

template<class T>
void TList<T>::pushBegin(T* a)
{
	TListNode<T>* a = new TListNode(begin, end, a);
	begin = a;
	end->setNext(begin);
	count++;
}

template<class T>
void TList<T>::pushEnd(T* a)
{
	TListNode<T>* a = new TListNode(begin, end, a);
	end = a;
	begin->setPrev(end);
	count++;
}

template<class T>
void TList<T>::deleteBegin()
{
	TListNode<T>* a = begin;
	end->setNext(begin->getNext());
	begin = begin->getNext();
	begin->setPrev(end);
	count--;
	delete a;
}

template<class T>
void TList<T>::deleteEnd()
{
	TListNode<T>* a = end;
	begin->setPrev(end->getPrev());
	end = end->getPrev();
	end->setNext(begin);
	count--;
	delete a;
}

//template<class T>
//TListIterator<T> TList<T>::getBegin()
//{
//	return TListIterator<T>(*this, begin);
//}

//template<class T>
//TListIterator<T> TList<T>::getEnd()
//{
//	return TListIterator<T>(*this, nullptr);
//}

template<class T>
void TList<T>::clear()
{
	for (int i = 0; i < count; i++)
	{
		deleteBegin();
	}
	begin = nullptr;
	end = nullptr;
}

template<class T>
TList<T>& TList<T>::operator = (const TList<T>& p)
{
	if (&p == this)
		return this;
	TList<T>::TList(p);
	return *this;
}

template<class T>
TList<T>& TList<T>::operator = (const TList<T>&& p)
{
	if (p == this)
		return this;
	clear();
	TList<T>::TList(p);
	return *this;
}