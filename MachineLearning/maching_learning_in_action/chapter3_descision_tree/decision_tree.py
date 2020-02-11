from math import log
import operator

# Helper
def CreateDataSet():
    data_set = [
        [1, 1, "yes"],
        [1, 0, "no"],
        [1, 1, "yes"],
        [0, 1, "no"],
        [0, 1, "no"],
    ]
    # Label represent each feature's meaning
    labels = ["no surfacing", "flippers"]
    return data_set, labels

# Split
def SplitDataSet(data_set, axis, value):
    split_data_set = []
    for feature_vector in data_set:
        if feature_vector[axis] == value:
            reduced_feature_vector = feature_vector[:axis]
            reduced_feature_vector.extend(feature_vector[axis + 1:])
            split_data_set.append(reduced_feature_vector)
    return split_data_set

# Calculate Shannon entropy
# The data set here are different from kNN
# it includes the labels
def CalShannonEnt(data_set):
    # Calculate data set's label's frequency
    label_count = {}
    for feature_vec in data_set:
        label = feature_vec[-1]
        label_count[label] = label_count.get(label, 0) + 1
    # Calculate data set's shannon entropy
    shannon_ent = 0
    entry_num = len(data_set)
    for key in label_count.keys():
        prob = label_count[key] / entry_num
        shannon_ent -= prob * log(prob, 2)
    return shannon_ent

# Choose best feature by using shannon entropy again
def ChooseBestFeatureToSplit(data_set):
    # Prepare
    num_feature = len(data_set[0]) - 1
    init_entropy = CalShannonEnt(data_set)
    best_info_gain = 0; best_feature_index = -1
    for i in range(num_feature):
        features = [line[i] for line in data_set]    # List comprehension
        unique_features = set(features)
        now_entropy = 0
        # Iter all value of the feature
        for feature in unique_features:
            split_data_set = SplitDataSet(data_set, i, feature)
            prob = len(split_data_set) / len(data_set)
            now_entropy += prob * CalShannonEnt(split_data_set)
        new_info_gain = init_entropy - now_entropy
        if new_info_gain > best_info_gain:
            best_info_gain = new_info_gain
            best_feature_index = i
    return best_feature_index

# Get the most count label
def MajorityCnt(class_list):
    class_count = {}
    for label in class_list:
        class_count[label] = class_count.get(label, 0) + 1
    result = sorted(class_count.items(), key=operator.itemgetter(1),
                    reverse=True)
    return result[0][0]

# Create decision tree
def CreateTree(data_set, labels):
    # Get all our class
    class_list = [line[-1] for line in data_set]    # The correct way to get our labels
    # All data in the same class
    if class_list.count(class_list[0]) == len(class_list):
        return class_list[0]
    # Iter all features
    if len(data_set[0]) == 1:                       # We only have one feature
        return MajorityCnt(class_list)              # Return the largest frequency as result
    # Select best feature
    best_feature_index = ChooseBestFeatureToSplit(data_set)
    best_feature = labels[best_feature_index]
    del(labels[best_feature_index])                 # Never consider the same feature
    # Build our tree
    my_tree = {best_feature: {}}
    unique_feature = set(line[best_feature_index] for line in data_set)
    for value in unique_feature:
        sub_labels = labels[:]
        my_tree[best_feature][value] = \
            CreateTree(SplitDataSet(data_set, best_feature_index, value),
                       sub_labels)
    return my_tree

# Classify our input due to the decision tree
def Classify(my_tree, label, test_vec):
    first_feat = list(my_tree.keys())[0]
    next_dict = my_tree[first_feat]
    feat_index = label.index(first_feat)
    for key in next_dict.keys():
        # In this case, the key of dict is the value of feature
        if key == test_vec[feat_index]:
            if type(next_dict[key]).__name__ == "dict":
                class_label = Classify(next_dict[key], label, test_vec)
            else:
                class_label = next_dict[key]
    return class_label

# Dump our decision tree
def StoreTree(my_tree, filename):
    import pickle
    file = open(filename)
    pickle.dump(my_tree, file)
    file.close()

# Load our decision tree
def LoadTree(filename):
    import pickle
    file = open(filename)
    return pickle.load(file)

if __name__ == "__main__":
    data_set, labels = CreateDataSet()
    labels_copy = labels[:]
    tree = CreateTree(data_set, labels)
    print(Classify(tree, labels_copy, [1, 1]))
