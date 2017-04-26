#include"GameManager.h"

GameManager* GameManager::m_pInstance = 0;

GameManager::GameManager()
{

}

GameManager* GameManager::Instance()
{
	if (!m_pInstance)
		m_pInstance = new GameManager();
	return m_pInstance;

}





