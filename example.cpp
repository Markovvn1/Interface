#include "interface.hpp"

class MyConstInt : public Interface
{
private:
	int* data = NULL;

protected:
	void destructor()
	{
		if (data != NULL) delete data;
	}

public:
	MyConstInt() : Interface() {};

	MyConstInt(const int value) : Interface()
	{
		data = new int;
		*data = value;
	};

	int get()
	{
		return *data;
	}
};


int main()
{
	MyConstInt a;

	int n;
	cin >> n;

	if (n > 10)
	{
		MyConstInt b(6);
		a = b; // Сами данные не копируются (копируются только указатели, при этом сам объект не уничтожается)
	}
	else
	{
		MyConstInt b(7);
		a = b; // Сами данные не копируются (копируются только указатели, при этом сам объект не уничтожается)
	}

	cout << a.get() << endl;
}
