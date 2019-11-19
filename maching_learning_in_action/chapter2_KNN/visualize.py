# Pycharm 要把当前文件夹设为source root才能导入同一个目录下的文件
# 太NM神奇了
import KNN
import numpy as np      # 看来import模块，并不会导入相应模块里导入过的模块
import matplotlib.pyplot as plt

if __name__ == "__main__":
    group, labels = KNN.File2Matrix("./datingTestSet2.txt")
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.scatter(group[:, 1], group[:, 2], 15.0 * np.array(labels), 15.0 * np.array(labels))
    plt.show()

