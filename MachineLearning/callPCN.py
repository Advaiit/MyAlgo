import numpy as np
import perceptron as pcn

a = np.array([[0, 0, 0], [0, 1, 1], [1, 0, 1], [1, 1, 1]])

p = pcn.PerceptronNetwork(a[:, :2], a[:, 2:])

p.train(0.25, 10)