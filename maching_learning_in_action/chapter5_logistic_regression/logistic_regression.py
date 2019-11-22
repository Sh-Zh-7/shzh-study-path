import random
import numpy as np
import matplotlib.pyplot as plt

# Get our data set and class by our file
def GetDataSet():
    data_mat = []; labels = []
    filename = "/home/szh/Downloads/machinelearninginaction/Ch05/testSet.txt"
    file = open(filename)
    for line in file.readlines():
        content = line.strip().split()
        data_mat.append([1, content[0], content[1]])
        labels.append(content[-1])
    return data_mat, labels

def Sigmoid(x):
    return 1 / (1 + np.exp(-x))

# Stochastic gradient ascent
# Set flexible variable as default parameter
def SGA(data_set, labels, iter_times=150):
    data_set = np.array(data_set, dtype="float64")
    labels = np.array(labels, dtype="float64")
    # Get our gradient ascent necessary attributes
    m, n = data_set.shape       # train_set num and feature num
    weight = np.ones(n, dtype="float64")    # Initial weight
    # Start to optimize
    for i in range(iter_times):
        index_set = list(range(m))
        for j in range(m):
            alpha = 4 / (1 + j + i) + 0.1       # Change learning rate
            rand_index = int(random.uniform(0, len(index_set)))
            h = Sigmoid(np.sum(data_set[rand_index] * weight))
            error = labels[rand_index] - h
            weight += alpha * error * data_set[rand_index]
            # Range object don't support item deletion
            # You need to convert the range object into list object
            del(index_set[rand_index])
    return weight

# Draw all points and decision boundary
def PlotDecisionBoundary():
    # Get necessary variables
    data_set, labels = GetDataSet()     # The elements' type in our labels is string
    weights = SGA(data_set, labels)
    # Convert our data set to array class
    # Remember to add dtype key-word parameter
    data_set = np.array(data_set, dtype="float64")
    m, n = data_set.shape
    # Store points
    x0_coords = []; y0_coords = []
    x1_coords = []; y1_coords = []
    for i in range(m):
        if int(labels[i]) == 1:
            x0_coords.append(data_set[i, 1])
            y0_coords.append(data_set[i, 2])
        else:
            x1_coords.append(data_set[i, 1])
            y1_coords.append(data_set[i, 2])
    # Plot all points
    figure = plt.figure()
    ax = plt.subplot(111, frameon=False)
    plt.scatter(x0_coords, y0_coords, s=30, c="red", marker="s")
    plt.scatter(x1_coords, y1_coords, s=30, c="blue")
    # Plot decision boundary
    X = np.linspace(-3.0, 3.0, 10)
    Y = (-weights[0] - weights[1] * X) / weights[2]
    plt.plot(X, Y)
    plt.xlabel("X1"); plt.ylabel("X2")
    plt.show()

if __name__ == "__main__":
    # If we coded wrongly elsewhere
    # The interpreter won't find it
    PlotDecisionBoundary()
