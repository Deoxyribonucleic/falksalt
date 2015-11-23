#include "StateStack.hpp"

#include "audio/SoundManager.hpp"


using namespace falksalt;

void StateStack::push(std::shared_ptr<State> state)
{
	m_stack.push(state);
}

void StateStack::pop()
{
	m_stack.pop();
}

void StateStack::update(float delta, SoundManager& soundMgr)
{
	auto stack = m_stack;
	stack.top()->update(delta, soundMgr, true);
	stack.pop();

	while(!stack.empty())
	{
		stack.top()->update(delta, soundMgr, false);
		stack.pop();
	}
}

void StateStack::render(Renderer& renderer)
{
	m_stack.top();
	auto tmp = m_stack;
	decltype(m_stack) stack;

	while(!tmp.empty())
	{
		stack.push(tmp.top());
		tmp.pop();
	}

	while(!stack.empty())
	{
		stack.top()->render(renderer);
		stack.pop();
	}
}

