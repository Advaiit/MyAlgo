#basic perceptron network for learning the OR logic

import numpy as np

class ORPerceptronNetwork:
    def __init__(self, inputSet, targetSet):
        
        #Neural Node Initialization code here

        self.mInputSet = inputSet
        self.mTargetSet = targetSet

        self.mDataSize = np.shape(self.mInputSet)[0]

        if np.ndim(self.mInputSet) > 1 :
            self.mInputCount = np.shape(self.mInputSet)[1]
        else :
            self.mInputCount = 1
        
        if np.ndim(self.mTargetSet) > 1 :
            self.mNodeCount = np.shape(self.mTargetSet)[1]
        else :
            self.mNodeCount = 1

        self.mWeights = np.random.rand(self.mInputCount + 1, self.mNodeCount) * 0.1 - 0.05
        
    def getActivations(self) :
        activations= np.dot(self.mInputSet, self.mWeights)
        return np.where(activations > 0, 1, 0)
    
    def train(self, learningRate, niterations) :
        self.mInputSet = np.concatenate((self.mInputSet, -np.ones((self.mDataSize, 1))), axis = 1)

        for i in range(niterations) :
            print 'Iterations: ', i
            print 'Weights: '
            print self.mWeights

            activations = self.getActivations()
            self.mWeights -= np.dot(np.transpose(self.mInputSet), (self.mTargetSet - activations)) * learningRate

            print 'Final Output: '
            print activations

'''
	def confmat(self,inputs,targets):
		"""Confusion matrix"""

		# Add the inputs that match the bias node
		inputs = np.concatenate((inputs,-np.ones((self.nData,1))),axis=1)
		
		outputs = np.dot(inputs,self.weights)
	
		nClasses = np.shape(targets)[1]

		if nClasses==1:
			nClasses = 2
			outputs = np.where(outputs>0,1,0)
		else:
			# 1-of-N encoding
			outputs = np.argmax(outputs,1)
			targets = np.argmax(targets,1)

		cm = np.zeros((nClasses,nClasses))
		for i in range(nClasses):
			for j in range(nClasses):
				cm[i,j] = np.sum(np.where(outputs==i,1,0)*np.where(targets==j,1,0))

		print cm
        print np.trace(cm)/np.sum(cm)


    def recall(self):
        self.confmat(self.mInputSet, self.mTargetSet)

'''