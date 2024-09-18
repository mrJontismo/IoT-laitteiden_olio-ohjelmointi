#include <iostream>
#include <string>
#include <vector>

class Observer;
class Subject
{
public:
	virtual void Attach(Observer *o) = 0;
	virtual void Notify() = 0;
};

class Observer
{
public:
	virtual void Update() = 0;
};

class Person
{
public:
	Person(const std::string& name = "nobody");
	virtual ~Person() = default;
	virtual void identity() const;
	virtual void interrogate();
private:
	std::string name;
};

Person::Person(const std::string& name) : name(name) {}

void Person::identity() const
{
	std::cout << "My name is: " << name << std::endl;
}

void Person::interrogate()
{

}

class Spy : public Person, public Subject
{
public:
    Spy(const std::string& name = "nobody", const std::string& alias = "none", int resistance = 0);
    void set_identity(const std::string& alias);
    void identity() const override;
	void interrogate() override;
	void Attach(Observer * o) override;
	void Notify() override;
private:
    std::string alias;
	int resistance;
	Observer *observer;
};

Spy::Spy(const std::string& name, const std::string& alias, int resistance) : Person(name), alias(alias), resistance(resistance) {}

void Spy::set_identity(const std::string& alias)
{
	this->alias = alias;
}

void Spy::identity() const
{
	if (resistance > 0)
	{
		std::cout << "My name is: " << alias << std::endl;
	} else
	{
		Person::identity();
		std::cout << "My alias is: " << alias << std::endl;
	}
}

void Spy::interrogate()
{
	if (resistance > 0 )
	{
		--resistance;
		if (resistance == 0)
		{
			Notify();
		}
	}
}

void Spy::Attach(Observer *o)
{
	observer = o;
}

void Spy::Notify()
{
	if (observer)
	{
		observer->Update();
	}
}

class Judge : public Person, public Observer
{
public:
	Judge(const std::string& name) : Person(name) {};
	void Update() override;
};

void Judge::Update()
{
	std::cout << "My name is: ";
	identity();
	std::cout << "I'm sending a spy to prison!" << std::endl;
}

int main(int argc, char** argv)
{

	Person agent("James Bond");
	Spy spy("Emilio Largo", "William Johnson", 3);
	Spy spy2("Ernst Blofield", "John Keats", 5);
	Judge judge("Judge Barnhill");
	spy.Attach(&judge);
	spy2.Attach(&judge);

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy.interrogate();
		spy.identity();
	}
	spy.set_identity("Bill Munny");
	spy.identity();

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy2.interrogate();
		spy2.identity();
	}

	return 0;
}