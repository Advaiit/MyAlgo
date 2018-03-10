import numpy as np
import pylab as pl
import multilayerp as mlp

x = np.ones((1, 40)) * np.linspace(0, 1, 40)
t = np.sin(2 * np.pi * x) + np.cos(4 * np.pi * x)

x = x.T
t = t.T

inputTrainingSet = x[0::2, :]
targetTrainingSet = t[0::2, :]

inputTestSet = x[1::4, :]
targetTestSet = t[1::4, :]

inputValidationSet = x[3::4, :]
targetValidationSet = x[3::4, :]

network = mlp.MLPNetwork(inputTrainingSet, targetTrainingSet, hiddenNodeCount=3, outType='linear')
network.train(0.25, 1000)


