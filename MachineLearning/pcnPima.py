import os
import pylab as pl
import numpy as np
import perceptron as pcn

os.chdir('/home/adwait/developer/MyAlgo/MachineLearning/Datasets')
pima = np.loadtxt('pima-indians-diabetes.data', delimiter=',')

print 'Shape: '
print np.shape(pima)

indices0 = np.where(pima[:, 8] == 0)
indices1 = np.where(pima[:, 8] == 1)

pl.ion()
pl.plot(pima[indices0, 0], pima[indices0, 1], 'go')
pl.plot(pima[indices1, 0], pima[indices1, 1], 'rx')

#Data preparation

#If number of times pregnant is gt than 8, set as 8
pima[np.where(pima[:, 0] > 8), 0] = 8

#Give values to ranges for age
pima[np.where(pima[:, 7] <= 30), 7] = 1
pima[np.where((pima[:, 7] > 30) & (pima[:, 7] <= 40)), 7] = 2
pima[np.where((pima[:, 7] > 40) & (pima[:, 7] <= 50)), 7] = 3
pima[np.where((pima[:, 7] > 50) & (pima[:, 7] <= 60)), 7] = 4
pima[np.where(pima[:, 7] > 60), 7] = 5

print 'Initial Data'

print pima

pima[:,:8] = pima[:,:8]-pima[:,:8].mean(axis=0)
pima[:,:8] = pima[:,:8]/pima[:,:8].var(axis=0)

print '\n\n'

print 'After normalisation'

print pima

print '\n\n'

trainin = pima[::2, :8]
testin = pima[1::2, :8]

traintgt = pima[::2, 8:]
testtgt = pima[1::2, 8:]

p = pcn.PerceptronNetwork(trainin, traintgt)
p.train(0.25, 50000) #Accuracy goes till ~72 %
p.confusionMatrix(testin, testtgt, 2)


