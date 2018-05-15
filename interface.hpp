#pragma once
#include <mutex>

class Interface
{
private:
	bool active = true;
	int* count = NULL;
	mutex* lockData = NULL;

protected:
	virtual void destructor();

	void destroy();

public:
	Interface();
	Interface(const Interface &p);

	virtual ~Interface();

	void operator =(const Interface &p);
};
