import random

# Load data set and labels from given filename
def LoadDataSet(filename):
    data_set = []; labels = []
    with open(filename, "r") as f:
        for line in f.readlines():
            line_content = line.strip().split("\t")
            # Convert str to float type
            data = map(float, line_content[:-2])
            data_set.append(data)
            labels.append(int(line_content[-1]))
    return data_set, labels

# Select index different from give index j
def SelectRandJ(i, m):
    j = i
    while j == i:
        j = int(random.uniform(0, m))
    return j

# Make alpha strained in range [low, high]
def ClipAlpha(a, low, high):
    if a < low:
        a = low
    elif a > high:
        a = high
    return a

if __name__ == "__main__":
    data_set, labels = LoadDataSet("./testSet.txt")
    print(labels)
