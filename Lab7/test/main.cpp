#include <string>
#include <initializer_list>
#include <iostream>

using namespace std;

template<typename T>
class MyMap
{
private:
	struct Node
	{
		string key;
		T value;
		Node *next, *prev;
	};
	Node *head, *tail;
	class iterator
	{
		friend class MyMap;
	private:
		Node *nodePtr;
		iterator(Node *newPtr) : nodePtr(newPtr) {}
	public:
		iterator() : nodePtr(nullptr) {}

		bool operator!=(const iterator& itr) const
		{
			return nodePtr != itr.nodePtr;
		}

		string operator*() const
		{
		    string ret;
		    ret = ret + (nodePtr->key);
		    ret = ret + " ";
		    ret = ret + (to_string(nodePtr->value));
			return ret;
		}

		iterator operator++()
		{
			nodePtr = nodePtr->next;
			return *this;
		}
	};
public:
	iterator begin() const
	{
		return iterator(head);
	}

	iterator end() const
	{
		return nullptr;
	}
	MyMap();
	MyMap(initializer_list<pair<const char*,T>> a)
	{
	    head = tail = nullptr;
	    for(auto it : a)
        {
            add(it.first,it.second);
        }
	}
	operator int();
	bool operator()(const char* k);
	void add(const char* k, const T& item);
	void del(const char* k);
	friend MyMap<T> operator&(MyMap<T> &a, MyMap<T> &b)
	{
		MyMap<T> ret;
		Node* it = a.head;
		while (it != NULL)
		{
			ret.add(it->key.c_str(), it->value);
			it = it->next;
		}
		it = b.head;
		while (it != NULL)
		{
			if (a(it->key.c_str()) && !(a[it->key.c_str()] > b[it->key.c_str()]))ret.add(it->key.c_str(), b[it->key.c_str()]);
			else if (a(it->key.c_str()) && a[it->key.c_str()] > b[it->key.c_str()])ret.add(it->key.c_str(), a[it->key.c_str()]);
			else ret.add(it->key.c_str(), it->value);
			it = it->next;
		}
		return ret;
	}
	friend MyMap<T> operator|(MyMap<T> &a, MyMap<T> &b)
	{
		MyMap<T> ret;
		Node* it = a.head;
		while (it != NULL)
		{
			if (b(it->key.c_str()))
			{
				if (a[it->key.c_str()] > b[it->key.c_str()])ret.add(it->key.c_str(), it->value);
				else ret.add(it->key.c_str(), b[it->key.c_str()]);
			}
			it = it->next;
		}
		return ret;
	}
	T& operator[](const char* k);
};

template<typename T>
bool MyMap<T>::operator()(const char* k)
{
	Node* it = head;
	while (it != NULL)
		if (it->key == k)return true;
		else it = it->next;
	return false;
}

template<typename T>
void MyMap<T>::add(const char* k, const T& item)
{
	if (!head)
	{
		head = tail = new Node;
		head->value = item;
		head->key = k;
		head->next = head->prev = nullptr;
		return;
	}
	Node* it = head;
	while (it != NULL)
		if (it->key == k)
		{
			it->value = item;
			return;
		}
		else it = it->next;
	tail->next = new Node;
	tail->next->prev = tail;
	tail->next->next = nullptr;
	tail->next->value = item;
	tail->next->key = k;
	tail = tail->next;
}

template<typename T>
void MyMap<T>::del(const char* k)
{
	if (!head)return;
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
	}
	Node* it = head;
	while (it != NULL)
		if (it->key == k)
		{
			if (it == head)
			{
				head = head->next;
				delete head->prev;
				head->prev = nullptr;
				return;
			}
			else if (it == tail)
			{
				tail = tail->prev;
				delete tail->next;
				tail->next = nullptr;
				return;
			}
			else
			{
				it->prev->next = it->next;
				delete it;
				return;
			}
		}
		else it = it->next;
}

template<typename T>
T& MyMap<T>::operator[](const char* k)
{
	Node* it = head;
	while (it != NULL)
		if (it->key == k)return it->value;
		else it = it->next;
	tail->next = new Node;
	tail->next->prev = tail;
	tail->next->next = nullptr;
	tail->next->value = 0;
	tail->next->key = k;
	tail = tail->next;
	return tail->value;
}

template<typename T>
MyMap<T>::operator int()
{
	int ret = 0;
	Node* it = head;
	while (it != NULL)
	{
		ret++;
		it = it->next;
	}
	return ret;
}

template<typename T>
MyMap<T>::MyMap()
{
	head = nullptr;
}

class Point
{
private:
	int x, y;
public:
	Point() : x(0), y(0) {}
	Point(int x1, int y1) : x(x1), y(y1) {}
	Point(int) : x(0), y(0) {}
	friend bool operator>(const Point& p1, const Point& p2)
	{
		if (p1.x > p2.x && p1.y > p2.y)return true;
		return false;
	}
	friend string to_string(const Point& p)
	{
        string ret;
        ret = ret + to_string(p.x);
        ret = ret + " ";
        ret = ret + to_string(p.y);
        return ret;
	}
};

int main()
{
	cout << "Tipul int:" << endl;
	MyMap<int> m{ {"andrei",3},{"ion",5} };
	m.add("ana", 5);
	m["mihai"] = 3;
	cout << m["mihai"] << endl;
	for (auto chei : m)
		cout << chei << endl;
	m.del("andrei");
	cout << std::boolalpha << m("andrei") << endl;
	cout << int(m) << endl;
	MyMap<int> m2 = { {"ion",4} }, m3;
	m3 = m & m2;
	for (auto chei : m3)
		cout << chei << endl;
	m3 = m3 | m2;
	for (auto chei : m3)
		cout << chei << endl;
	cout << "Tipul Point:" << endl;
	Point p1(1, 1), p2(2, 2);
	MyMap<Point> m4 = { {"vasile", p1} }, m5;
	m4.add("maria", p2);
	Point p3(3, 3), p4(4, 4);
	m5.add("vasile", p3);
	m5.add("maria", p4);
	m4 = m5 & m4;
	for (auto chei : m4)
		cout << chei << endl;
	return 0;
}
