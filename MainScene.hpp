// Created by Tom Albrecht
// 17.11.16 - 18:54
// Copyright 2016

#include "FayEngine/FayEngine.h"

class MainScene;
FE_create_Ptr(MainScene);

class MainScene: public FE::Scene {
    FE::SpritePtr sprite;

	void generateTree();
	void branch(double len, double rot, FE::Vec2 pos, FE::DrawTexturePtr tex, double dir);
public:
	FE_create_FUNC(MainScene);

	virtual void setWindow(FE::WindowPtr win);
	virtual void mouseClickBegan(SDL_MouseButtonEvent event, FE::Vec2 coords);
};

