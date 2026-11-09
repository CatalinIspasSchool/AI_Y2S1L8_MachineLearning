#include "ModelLoader.h"

#include <fstream>
#include <iostream>

// will check any LightGBM errors reported and print
#define LGBM_CHECK(call)                                                   \
    do {                                                                   \
        if ((call) != 0) {                                                 \
            std::fprintf(stderr, "LightGBM error: %s\n", LGBM_GetLastError()); \
            std::exit(1);                                                  \
        }                                                                  \
    } while (0)


/*
LoadModel will load a LightGBM model ready for Inference
*/
void ModelLoader::LoadModel()
{

	// fixed path - edit as required
	const char* modelPath = "Assets/player_model.txt";


	// load the file into the booster item
	LGBM_CHECK(LGBM_BoosterCreateFromModelfile(modelPath, &numIterations, &boosterHandle));

	// report classes and features - for now these are manually set, but could be loaded from the JSON schema
	int _numFeatures = 0, _numClasses = 0;
	LGBM_CHECK(LGBM_BoosterGetNumFeature(boosterHandle, &_numFeatures));
	LGBM_CHECK(LGBM_BoosterGetNumClasses(boosterHandle, &_numClasses));
	std::printf("Loaded %s: %d iterations, %d features, %d classes\n",
		modelPath, numIterations, _numFeatures, _numClasses);

}


/*

GetPlayerClass will return the enum id of a PlayerSkill level based on the provided parameters

*/
int ModelLoader::GetPlayerClass(int _level, int _races, int _collisions)
{
	// config
	int numRows = 1; // only 1 player
	int64_t out_len = 0;

	// declare variables for model

	// the vector/array where the model will store the output of the prediction
	// this should be the number of rows x the number of classes
	// in this example, there is only a single player, so a single row
	std::vector<double> classProbability(static_cast<size_t>(numRows)* numClasses);


	//TODO - add the Level, Raced and Colliions model's input data
	// the vector/array where the input data should be added
	// Note: Order is important, as it must match the model features
	//    - add order should be Level, Races, Collisions
	std::vector<double> input;

	// add code to add the Level, Races and Collisions to the input adday






	// Use the LGBM API to make predictions
	// the model is stored in booster

	LGBM_CHECK(LGBM_BoosterPredictForMat(boosterHandle, input.data(), C_API_DTYPE_FLOAT64,numRows, numFeatures, 1,
		C_API_PREDICT_NORMAL, 0, -1,"", &out_len, classProbability.data()));


	// TODO - determine the class with the highest confifence/probability
	// the classProbability will contain class probability for each input row
	// in this example, there is only 1 player, so classProbability will be the same length as the number of classes, 4
	
	// add code below to determine class with the highest probablity
	// return this class index


	int maxIndex = 0;







	// return the index of the highest class. This will be the skill group predicted for the player data. 
	return maxIndex;
}