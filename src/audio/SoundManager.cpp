#include "SoundManager.hpp"

#include <cstdlib>

using namespace falksalt;

SoundManager::Sound loadSound(std::string const& file)
{
	SoundManager::Sound sound(new std::pair<sf::SoundBuffer, sf::Sound>());

	sound->first.loadFromFile("assets/sounds/" + file + ".ogg");
	sound->second.setBuffer(sound->first);

	return sound;
}

SoundManager::SoundManager()
{
	m_chimes.push_back(loadSound("chime1"));
	m_chimes.push_back(loadSound("chime2"));
	m_chimes.push_back(loadSound("chime3"));
	m_chimes.push_back(loadSound("chime4"));
	m_chimes.push_back(loadSound("chime5"));
	m_chimes.push_back(loadSound("chime6"));
	m_chimes.push_back(loadSound("chime7"));
	m_chimes.push_back(loadSound("chime8"));
	m_chimes.push_back(loadSound("chime9"));
	m_chimes.push_back(loadSound("chime10"));
	m_chimes.push_back(loadSound("chime11"));
	m_chimes.push_back(loadSound("chime12"));
	m_chimes.push_back(loadSound("chime13"));
	m_chimes.push_back(loadSound("chime14"));
	m_chimes.push_back(loadSound("chime15"));
	m_chimes.push_back(loadSound("chime16"));
	m_chimes.push_back(loadSound("chime17"));

	m_specialChimes.push_back(loadSound("special_chime1"));
	m_specialChimes.push_back(loadSound("special_chime2"));
	m_specialChimes.push_back(loadSound("special_chime3"));

	m_music.openFromFile("assets/sounds/music1.ogg");

	m_music.setLoop(true);
	m_music.play();
}

void SoundManager::playChime()
{
	m_chimes[rand() % m_chimes.size()]->second.play();
}

void SoundManager::playSpecialChime()
{
	m_specialChimes[rand() % m_specialChimes.size()]->second.play();
}

