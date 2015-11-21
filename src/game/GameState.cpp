#include "GameState.hpp"

using namespace falksalt;

GameState::GameState()
	: m_logger(om::Logger::get("GameState"))
{
}

void GameState::update()
{
	m_logger.info() << "Update" << std::endl;
}

