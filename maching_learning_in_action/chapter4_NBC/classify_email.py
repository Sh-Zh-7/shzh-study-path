from bayes import *
import random
import re

# Select word that length is greater than 2
# And change them to lower case
def TextParse(big_string):
    words_list = re.split(r"\W*", big_string)
    return [word.lower() for word in words_list if len(word) > 2]

def SpamEmailClassification():
    # Store email's content in our list
    spam_email_path = "/home/szh/Downloads/machinelearninginaction/Ch04/email/spam"
    ham_email_path = "/home/szh/Downloads/machinelearninginaction/Ch04/email/ham"
    words_list = []; labels = []
    for i in range(1, 26):
        # Get content of emails
        spam_email = open(spam_email_path + "/%d.txt" % i, "r")
        spam_email_content = TextParse(spam_email.read())
        ham_email = open(ham_email_path + "/%d.txt" % i, "r")
        ham_email_content = TextParse(ham_email.read())
        # Store them in our words list
        words_list.append(spam_email_content)
        labels.append(1)
        words_list.append(ham_email_content)
        labels.append(0)
    # Select cross-validation set
    test_index = []
    training_set_num = list(range(50))
    for i in range(10):
        # random index must be integer
        random_index = int(random.uniform(0, len(training_set_num)))    # Using uniform random number
        test_index.append(random_index)
        del(training_set_num[random_index])           # Delete them in training set
    # Prepare to do testing
    train_set = []; train_class = []
    vocab_list = GetVocabList(words_list)
    for index in training_set_num:
        train_set.append(VocabList2Vec(vocab_list, words_list[index]))
        train_class.append(labels[index])
    # Train
    p0v, p1v, pc1 = TrainNB(train_set, train_class)
    print(pc1)
    # Test
    error_count = 0
    for index in test_index:
        test_input = VocabList2Vec(vocab_list, words_list[index])
        result = ClassifyNB(test_input, p0v, p1v, pc1)
        if result != labels[index]:
            error_count += 1
    print("Error rate: %f" % (error_count / 10))

if __name__ == "__main__":
    SpamEmailClassification()
