#ifndef VECTOR_H
#define VECTOR_H

//Compilatorn accepterar inte en class template som .cpp fil så vi får definera den här
template<typename T>
class Vector
{
private:
	T* items;
	int capacity;
	int capacityIncrement;
	int nrOfItems;
	void expand();
public:
	Vector(int capacity = 10, int capacityIncrement = 5);
	virtual ~Vector();
	//*copy - konstruktor
	//* tilldelningsoperator
	void addLast(T item);
	void addFirst(T item);
	void addAt(int index, T item)throw(...);
	T getFirst() const throw(...);
	T getLast() const throw(...);
	T getAt(int index) const throw(...);
	T removeFirst() throw(...);
	T removeLast() throw(...);
	T removeAt(int index) throw(...);
	void removeBetween(int start, int end) throw(...);
	//void clear();
	//+operatorn
	T operator[](int index)const throw(...);
};

template<typename T>
void Vector<T>::expand()
{
	this->capacity += this->capacityIncrement;
	T* temp = new T[this->capacity];
	for (int i = 0; i < this->nrOfItems; i++)
	{
		temp[i] = this->items[i];
	}
	delete[] this->items;
	this->items = temp;
}

template<typename T>
Vector<T>::Vector(int capacity, int capacityIncrement)
{
	this->nrOfItems = 0;
	this->capacity = capacity;
	this->capacityIncrement = capacityIncrement;
	this->items = new T[this->capacity];
}

template<typename T>
Vector<T>::~Vector()
{

}

template<typename T>
void Vector<T>::addLast(T item)
{
	if (this->capacity == this->nrOfItems)
	{
		this->expand();
	}
	this->items[nrOfItems ++] = item;
}

template<typename T>
void addFirst(T item)
{
	if (this->capacity == this->nrOfItems)
	{
		this->expand();
	}//ska sätta items i rättording eller bara flytta items[0]till sista platsen. nedan har jag valt att ordning inte spelar roll
	this->items[this->nrOfItems++] = this->items[0];
	this->items[0] = item;
}

template<typename T>
void addAt(int index, T item)throw(...)
{
	if (index<0 || index>this->nrOfItems)//Exeption Handling, undantagshantering
	{
		throw "Index is not allowed!";
	}
	if (this->capacity == this->nrOfItems)
	{
		this->expand();
	}
	this->items[this->nrOfItems++] = this->items[index];
	this->items[index] = item;
}

//template<typename T>
//T getFirst() const throw(...)
//{
//
//}
//
//template<typename T>
//T getLast() const throw(...)
//{
//
//}
//
//template<typename T>
//T getAt(int index) const throw(...)
//{
//
//}
//
//template<typename T>
//T removeFirst() throw(...)
//{
//
//}
//
//template<typename T>
//T removeLast() throw(...)
//{
//
//}
//
//template<typename T>
//void removeBetween(int start, int end) throw(...)
//{
//
//}
//
//template<typename T>
//T operator[](int index)const throw(...)
//{
//
//}



#endif // !VECTOR_H

