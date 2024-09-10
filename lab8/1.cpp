#include <iostream>

class Counter
{
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};

class LimitedCounter : public Counter
{
public:
	LimitedCounter(int initial = 0, int upper_limit = 0);
	void inc() override;
	void dec() override;
	operator int() override;

private:
	int count;
	int limit;
};

LimitedCounter::LimitedCounter(int initial, int upper_limit) : count(initial), limit(upper_limit) {};

void LimitedCounter::inc()
{
	if (count < limit)
	{
		++count;
	}
}

void LimitedCounter::dec()
{
	if (count > 0)
	{
		--count;
	}
}

LimitedCounter::operator int()
{
	return count;
}

class OverflowCounter : public Counter
{
public:
	OverflowCounter(int initial = 0, int upper_limit = 0);
	void inc() override;
	void dec() override;
	operator int() override;

private:
	int count;
	int limit;
};

OverflowCounter::OverflowCounter(int initial, int upper_limit) : count(initial), limit(upper_limit) {};

void OverflowCounter::inc()
{
	if (count >= limit)
	{
		count = 0;
	} else
	{
		++count;
	}
}

void OverflowCounter::dec()
{
	if (count <= 0)
	{
		count = limit;
	} else
	{
		--count;
	}
}

OverflowCounter::operator int()
{
	return count;
}

void UseCounter(Counter& ctr, int num)
{
    if (num > 0)
	{
        for (int i = 0; i < num; ++i)
		{
            ctr.inc();
        }
    } else
	{
        for (int i = 0; i < -num; ++i)
		{
            ctr.dec();
        }
    }
}

int main(int argc, char** argv)
{
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	std::cout << oc << std::endl;
	UseCounter(oc, 5);
	std::cout << oc << std::endl; // should display zero
	UseCounter(oc, -1);
	std::cout << oc << std::endl; // should display 9
	oc.dec();
	std::cout << oc << std::endl; // should display 8

	std::cout << lc << std::endl;
	lc.inc();
	std::cout << lc << std::endl;
	lc.dec();
	std::cout << lc << std::endl;
	for(int i = 0; i < 10; ++i) lc.inc();
	std::cout << lc << std::endl;
	UseCounter(lc, -9);
	std::cout << lc << std::endl;

	return 0;
}
