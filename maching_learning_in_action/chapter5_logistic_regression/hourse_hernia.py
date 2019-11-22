from logistic_regression import *

# Load data from given filename
def LoadData(filename):
    data_set = []; labels = []
    with open(filename) as f:
        for line in f.readlines():
            temp_vec = []
            feat_vec = line.strip().split('\t')
            n = len(feat_vec)
            # Get features
            for i in range(n - 1):
                temp_vec.append(float(feat_vec[i]))
            labels.append(float(feat_vec[n - 1]))
            data_set.append(temp_vec)
    return data_set, labels

# Get label by sigmoid function
def ClassifyByProb(feature, weight):
    prob = Sigmoid(np.sum(feature * weight))
    return 1 if prob > 0.5 else 0

def Test():
    # Get training set
    train_file = "/home/szh/Downloads/machinelearninginaction/Ch05/horseColicTraining.txt"
    train_set, train_labels = LoadData(train_file)
    # Train
    best_weight = SGA(train_set, train_labels, 500)
    # Get testing set
    test_file = "/home/szh/Downloads/machinelearninginaction/Ch05/horseColicTest.txt"
    test_set, test_labels = LoadData(test_file)
    # Test
    error_count = 0
    total = len(test_labels)
    for i in range(total):
        result = ClassifyByProb(test_set[i], best_weight)
        if result != test_labels[i]:
            error_count += 1
    return error_count / total

# Because the train procedure select stochastic features
# We need to test multi times to reduce the testing error
def MultiTest():
    multi_test_time = 10
    error_rate_sum = 0
    for i in range(multi_test_time):
        cur_error_rate = Test()
        print("The current error rate is %f" % cur_error_rate)
        error_rate_sum += cur_error_rate
        print("")
    print("The average error rate is %f" % (error_rate_sum / multi_test_time))

if __name__ == "__main__":
    MultiTest()
