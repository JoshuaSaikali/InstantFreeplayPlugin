#include "pch.h"
#include "FirstPlugin.h"
BAKKESMOD_PLUGIN(FirstPlugin, "First Plugin", "1.0", PLUGINTYPE_FREEPLAY)

void FirstPlugin::onLoad() 
{
	this->Log("Loaded first plugin...");
	this->LoadHooks();
}

void FirstPlugin::onUnload()
{
	this->Log("Unloaded first plugin...");
}

void FirstPlugin::LoadHooks()
{
	gameWrapper->HookEvent("Function TAGame.GameEvent_Soccar_TA.EventMatchEnded", std::bind(&FirstPlugin::GameEndedEvent, this, std::placeholders::_1));
	gameWrapper->HookEvent("Function TAGame.AchievementManager_TA.HandleMatchEnded", std::bind(&FirstPlugin::GameEndedEvent, this, std::placeholders::_1));
}

void FirstPlugin::GameEndedEvent(std::string name)
{
	cvarManager->executeCommand("load_freeplay");
}

void FirstPlugin::Log(std::string msg)
{
	cvarManager->log(msg);
}
