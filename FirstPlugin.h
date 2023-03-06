#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"

#pragma comment( lib, "pluginsdk.lib")


class FirstPlugin : public BakkesMod::Plugin::BakkesModPlugin
{
public:
	// When plugin is loaded, this executes
	virtual void onLoad();

	// called when plugin is unloaded
	virtual void onUnload();

	// Binds GameEndedEvent() to the following HookEvents
	void         LoadHooks();

	// launches freeplay
	void         GameEndedEvent(std::string name);

private:
	// log msg to console in game
	void Log(std::string msg);
};

