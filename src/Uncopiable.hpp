#pragma once

class Uncopiable
{
public:
	Uncopiable() {};
	virtual ~Uncopiable() {};
private:
	Uncopiable(Uncopiable const&);
};

