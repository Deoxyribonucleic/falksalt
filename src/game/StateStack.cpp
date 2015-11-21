#include "StateStack.hpp"


using namespace falksalt;

void StateStack::push(std::shared_ptr<State> state)
{
	m_stack.push(state);
}

void StateStack::pop()
{
	m_stack.pop();
}

void StateStack::update()
{
	m_stack.top()->update();
}

