#include "interface.hpp"

Interface::Interface()
{
	count = new int;
	*count = 1;

	lockData = new mutex;
};

Interface::Interface(const Interface &p)
{
	count = p.count;
	lockData = p.lockData;

	lockData->lock();
	(*count)++;
	lockData->unlock();
}

Interface::~Interface()
{
	destroy();
}

void Interface::destructor() {};

void Interface::destroy()
{
	if (!active) return;
	active = false;

	int currentCount;


	lockData->lock();

	(*count)--;
	currentCount = *count;

	lockData->unlock();

	if (currentCount < 0) cout << "Fatal error! count < 0" << endl;

	if (currentCount <= 0)
	{
		destructor();

		delete lockData;
		delete count;
	}
}

void Interface::operator =(const Interface &p)
{
	p.lockData->lock();
	(*p.count)++;
	p.lockData->unlock();

	destroy();

	lockData = p.lockData;

	count = p.count;
	active = true;
}
