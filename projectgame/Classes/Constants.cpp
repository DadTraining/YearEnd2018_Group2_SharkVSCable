#include "Constants.h"

cocos2d::Vector<cocos2d::ui::Button*> Constants::listButton;
std::vector<MapLevel*> Constants::listMap;

cocos2d::Size Constants::getVisibleSize()
{
	return cocos2d::Director::getInstance()->getVisibleSize();
}



float Constants::setScaleSprite(float whichSize, float expectSize, float realSize)
{
	return (whichSize / expectSize) / realSize;
}

void Constants::AddButtonIntoMapLevel(cocos2d::ui::Button * btn)
{
	listButton.pushBack(btn);
}

void Constants::SetEnableTouchEvent(int index, bool enable)
{
	listButton.at(index)->setTouchEnabled(enable);
	listButton.at(index)->setBright(enable);
	listButton.at(index)->setEnabled(enable);
}

void Constants::SetEnableAllTouchEventOnMapLevel(bool enable)
{
	for (int i = 0; i < listButton.size(); i++)
	{
		listButton.at(i)->setTouchEnabled(enable);
	}
}

std::vector<MapLevel*> Constants::GetListMap()
{
	return listMap;
}

void Constants::AddMapIntoList(MapLevel * map)
{
	listMap.push_back(map);
}



void Constants::SetPhase(int index)
{
	auto map = listMap.at(index);
	InfoMap::setSharPhases(
		map->GetPhase(1),
		map->GetPhase(2),
		map->GetPhase(3)
	);
	InfoMap::setMapLevel(index);
}

void Constants::ReleaseButton()
{
	listButton.clear();
}

bool Constants::ListButtonIsEmpty()
{
	return listButton.empty();
}

