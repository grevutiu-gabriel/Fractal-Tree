// MainScene.cpp
// Tom Albrecht 18.11.16
// Copyright 2016

#include "MainScene.hpp"

#define ANGLE 29

using namespace FE;

Vec2 CalculatePoint(double angle, double distance) {
	return Vec2Make((distance * sin(angle)), (distance * cos(angle)));
}

void drawLine(Vec2 p1, Vec2 p2, const DrawTexturePtr &dest, const WindowPtr &w, double len) {
	auto off = Vec2Make(w->getSize().x/2.0, w->getSize().y);
	dest->drawLine(p2+off, p1+off, ColorWhiteColor());
}

/**
 * MainScene impl.
 */
void MainScene::branch(double len, double rot, Vec2 pos, DrawTexturePtr tex, double dir) {
	auto val = CalculatePoint(rot, len)+pos;

	drawLine(pos, val, tex, getWindow(), len);

	auto rr = double(rand()%300) / 30.0;
	auto rr2 = double(rand()%300) / 30.0;

	if (len >= 20)
		branch(len*0.8,rot+DegreesToRadians(dir), val, tex,  ANGLE+rr),
		branch(len*0.8,rot+DegreesToRadians(dir), val, tex,  (rr)),
		branch(len*0.8,rot+DegreesToRadians(dir), val, tex, -ANGLE-rr2);
}

void MainScene::generateTree() {
	auto texture = DrawTexture::create(getWindow()->getSize(), ColorClearColor());
	branch(90, DegreesToRadians(180), Vec2Null(), texture, 0);
	texture->apply();

	sprite->setTexture(texture);

	EngineHelper::getInstance()->removeUnusedTextures();
}

void MainScene::setWindow(WindowPtr window) {
	Scene::setWindow(window);

	sprite = Sprite::create();
	addChild(sprite);

	generateTree();
}

void MainScene::mouseClickBegan(SDL_MouseButtonEvent event, Vec2 coords) {
	generateTree();
}
