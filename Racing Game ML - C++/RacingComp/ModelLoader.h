#pragma once

#include <LightGBM/c_api.h>


/*
ModelLoader will handle the loading and interence from a LightGBM model
*/
class ModelLoader
{
public:
	void LoadModel();
	int GetPlayerClass(int _level, int _races, int _collisions);

private:

	//LightGBM model
	BoosterHandle boosterHandle = nullptr;

	// define the classes and features for now
	// tehse could be read from the JSON scehema for flexibility
	const int numClasses = 4;
	const int numFeatures = 3;


	int numIterations = 0;
};

