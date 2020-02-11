import numpy as np
import operator

# Read file content and convert it to matrix
def File2Matrix(filename):
    # Read file's content
    file = open(filename)
    array_of_lines = file.readlines()
    data_set_num = len(array_of_lines)
    index = 0
    # Prepare return values
    ret_mat = np.zeros((data_set_num, 3))
    ret_label = []
    for line in array_of_lines:
        line = line.strip()  # Delete /r
        list_from_line = line.split('\t')
        ret_mat[index, :] = list_from_line[0: 3]  # Ignore last
        ret_label.append(int(list_from_line[-1]))
        index += 1
    return ret_mat, ret_label


# Normalize our data set
def AutoNorm(data_set):
    # Get min and max array
    min_val = data_set.min(0)
    max_val = data_set.max(0)
    val_range = max_val - min_val
    # Calculate
    m = data_set.shape[0]
    normal_data = data_set - np.tile(min_val, (m, 1))
    normal_data = normal_data / np.tile(val_range, (m, 1))
    return normal_data, val_range, min_val


# Classify input by using KNN
def Classify(in_x, data_set, labels, k):
    # Calculate distance
    data_set_num = data_set.shape[0]
    diff_mat = np.tile(in_x, (data_set_num, 1)) - data_set
    square_diff_mat = diff_mat ** 2
    dis = np.sum(square_diff_mat, axis=0)
    # Get sorted indexes and count class
    sorted_indexes = np.argsort(dis)
    class_count = {}
    for i in range(k):
        # if the key doesn't exist, we'll have a KeyError
        label = labels[sorted_indexes[i]]
        class_count[label] = class_count.get(label, 0) + 1
    # Sort and get most similar label
    sorted_class_count = sorted(class_count.items(), key=operator.itemgetter(1), reverse=True)
    return sorted_class_count[0][0]


# Get accuracy
def ClassTest():
    # Get data set and normalize them
    data_set, labels = File2Matrix("datingTestSet2.txt")
    data_set, val_range, mins = AutoNorm(data_set)
    # Set test rate and start testing
    test_rate = 0.1
    m = data_set.shape[0]
    test_num = int(test_rate * m)
    error_count = 0
    for i in range(test_num):
        classify_res = Classify(data_set[i, :], data_set[test_num:m], labels[test_num:m], 3)
        print("The classifier came back with %d, the real answer is %d"\
              % (classify_res, labels[i]))
        if classify_res != labels[i]:
            error_count += 1
    print("Error rate is %f" % (error_count / test_num))

# API
def ClassifyPerson():
    result_list = ["not at all", "in small does", "in large does"]
    p = float(input())
    i = float(input())
    d = float(input())
    train_set, labels = File2Matrix("datingTestSet2.txt")
    train_set, val_range, min_val = AutoNorm(train_set)
    inarray = np.array([p, i, d])
    result = Classify((inarray - min_val) / val_range, train_set, labels, 3)
    print(result_list[result])

if __name__ == "__main__":
    ClassifyPerson()
