#pragma once
#include <functional>
#include <algorithm>
#include "Vectors.h"
#include "AffineMatrix.h"
#include "rand11.h"

class NeuralNetwork{
private:
	size_t inputSize;
	std::vector<size_t> sizes;
	double learningRate, annealingRate, weightmax;
	std::vector<AffineMatrix<double> > nlayers;
public:
	NeuralNetwork(const size_t is, const std::vector<size_t>& s, double ar);
	NeuralNetwork(const NeuralNetwork& nn){ inputSize = nn.inputSize; sizes = nn.sizes; learningRate = nn.learningRate; annealingRate = nn.annealingRate; weightmax = nn.weightmax; nlayers = nn.nlayers; }
	size_t depth() const{ return nlayers.size(); };
	AffineMatrix<double> operator[](size_t i){ return nlayers[i]; };
	
	void randInit();
	std::vector<double> frontprop(std::vector<double> input);

	//Genetic stuff
	NeuralNetwork mutate(double range) const;
	NeuralNetwork hybridize(const NeuralNetwork& n) const;

	//Backprop stuff
	std::vector<double> backprop(std::vector<double> testdata, std::vector<double> correct);
	std::vector<double> thresholding(std::vector<double> v);
	std::vector<double> thresholding_prime(std::vector<double> v);
};
