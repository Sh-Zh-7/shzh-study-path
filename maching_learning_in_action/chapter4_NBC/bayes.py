import numpy as np

# Load data set by hard coding
def LoadDataSet():
    posting_list = [['my', 'dog', 'has', 'flea', 'problems', 'help', 'please'],
                 ['maybe', 'not', 'take', 'him', 'to', 'dog', 'park', 'stupid'],
                 ['my', 'dalmation', 'is', 'so', 'cute', 'I', 'love', 'him'],
                 ['stop', 'posting', 'stupid', 'worthless', 'garbage'],
                 ['mr', 'licks', 'ate', 'my', 'steak', 'how', 'to', 'stop', 'him'],
                 ['quit', 'buying', 'worthless', 'dog', 'food', 'stupid']]
    class_vec = [0, 1, 0, 1, 0, 1]
    return posting_list, class_vec

# Get all unique word
def GetVocabList(data_set):
    vocab_set = set([])
    for words in data_set:
        vocab_set = vocab_set | set(words)
    return list(vocab_set)

# Return a vector representing each word exist or not
def VocabList2Vec(vocab_set, words):
    word_exist = [0] * len(vocab_set)
    for word in words:
        if word in vocab_set:
            word_exist[vocab_set.index(word)] += 1
    return word_exist

# Treat all words as vector
def TrainNB(data_set, labels):
    m = len(data_set)
    n = len(data_set[0])
    # Calculate p(c1)
    p_c1 = sum(labels) / m  # p_c0 = 1 - p_c1
    # Prepare to calculate p(w|c1) and p(w|c0)
    p_num0 = np.ones(n); p_num1 = np.ones(n)
    p_total0 = 2; p_total1 = 2
    for i in range(m):
        if labels[i] == 1:
            p_num1 += data_set[i]
            p_total1 += sum(data_set[i])
        else:
            p_num0 += data_set[i]
            p_total0 += sum(data_set[i])
    return np.log(p_num0 / p_total0), np.log(p_num1 / p_total0), p_c1

def ClassifyNB(input_vector, p0v, p1v, pc1):
    p0 = sum(p0v * input_vector) + np.log(pc1)
    p1 = sum(p1v * input_vector) + np.log(1 - pc1)
    if p0 > p1:
        return 0
    else:
        return 1

def TestNB():
    words_set, labels = LoadDataSet()
    vocab_list = GetVocabList(words_set)
    data_set = []
    for word in words_set:
        data_set.append(VocabList2Vec(vocab_list, word))
    p0v, p1v, pc1 = TrainNB(data_set, labels)
    # Positive test
    test_entry = ["love", "my", "dalmation"]
    input1 = VocabList2Vec(vocab_list, test_entry)
    print(ClassifyNB(input1, p0v, p1v, pc1))
    # Negative test
    test_entry = ["stupid", "garbage"]
    input2 = VocabList2Vec(vocab_list, test_entry)
    print(ClassifyNB(input2, p0v, p1v, pc1))

if __name__ == "__main__":
    TestNB()
