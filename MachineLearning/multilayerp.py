import numpy as np

class MLPNetwork:
    def __init__(self, inputs, targets, hiddenNodeCount, beta = 1, momentum = 0.9, outType = 'logistic'):
        #Initializa a neural network with 1 hidden layer and 1 output layer
        self.mInputs = inputs
        self.mTargets = targets

        if np.shape(self.mInputs)[0] <= 1:
            print 'Input too small'
            return -1
        
        if np.shape(self.mInputs)[1] < 1:
            print "Invalid input"

        self.nData = np.shape(self.mInputs)[0]
        self.nIn = np.shape(self.mInputs)[1]
        self.nOut = np.shape(self.mTargets)[1]
        self.nHidden = hiddenNodeCount
        self.mBeta = beta
        self.mMomentum = momentum
        self.mOutputType = outType
        
        #Initialize weight matrix for i to j
        self.mWeights1 = (np.random.rand(self.nIn + 1, self.nHidden) - 0.5) * 2 / np.sqrt(self.nIn) 
        self.mWeights2 = (np.random.rand(self.nHidden + 1, self.nOut) - 0.5) * 2 / np.sqrt(self.nHidden) 

    def getActivations(self):
        #Move the network forward

        #Get the dot product of weights and inputs
        self.hiddenOut = np.dot(self.mInputs, self.mWeights1)
        self.hiddenOut = 1.0 / (1.0 + np.exp(-self.mBeta * self.hiddenOut))
        np.concatenate((self.hiddenOut, -np.ones((self.nData, 1))), axis=1)

        outputs = self.dot(self.hiddenOut, self.mWeights2)

        if self.mOutputType == 'linear':
            return outputs
        elif self.mOutputType == 'logistic':
            return 1.0 / (1.0 + np.exp(self.mBeta * outputs))
        else:
            print 'Invalid output type'

    def train(self, learningRate, iterations):
        inputs = np.concatenate((self.mInputs, -np.ones((self.nData, 1))), axis=1)

        updateW1 = np.zeros((np.shape(self.mWeights1)))
        updateW2 = np.zeros((np.shape(self.mWeights2)))

        for n in range(iterations):
            self.outputs = getActivations()

            error = 0.5 * np.sum((self.outputs - self.mTargets)**2)

            if np.mod(n, 100) == 0:
                print 'Iteration: ', n, 'Error: ', error
            
            if self.mOutputType == 'linear':
                deltaO = (self.outputs - self.mTargets)/self.nData
            elif self.mOutputType == 'logistic':
                deltaO = self.mBeta * (self.outputs - self.mTargets) * self.outputs * (1.0 - self.outputs)
            else:
                print "Invalid output type"
                return -1
            
            deltaH = self.mBeta * self.hiddenOut * (1.0 - self.hiddenOut) * (np.dot(deltaO, np.transpose(self.mWeights2)))

            updateW1 = self.learningRate * (np.dot(np.transpose(self.mInputs, deltaH[:, :-1]))) * self.mMomentum * updateW1
            updateW2 = self.learningRate * (np.dot(np.transpose(self.hiddenOut), deltaO)) + self.mMomentum * updateW2

            self.mWeights1 -= updateW1
            self.mWeights2 -= updateW2
            
    #@TODO: Add confusion matrix


