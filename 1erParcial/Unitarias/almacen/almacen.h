#include <vector>

template<class T>
class Almacen
{
private:
	std::vector<T> v; 
	
public:
	Almacen(int size)
	{
		//v.resize(5);
		v.reserve(size);
	}
	void add(T e){v.push_back(e);}
	void deleteAt(int index){v.erase(v.begin()+index);}
	bool isEmpty(){return v.size()==0;}
	int getCapacity(){return v.capacity();}
	int getSize(){return v.size();}
	
};