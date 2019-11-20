import matplotlib.pyplot as plt
from descision_tree import *

# Global variable
# fc attribute determine the color of the node
decision_node = dict(boxstyle="sawtooth", fc="0.8")  # Decision block
leaf_node = dict(boxstyle="round4", fc="0.8")  # Terminate block
arrow_args = dict(arrowstyle="<-")


# Generate tree in order to do testings
def RetrieveTree(i):
    list_of_trees = [{"no surfacing": {0: "no", 1: {"flippers":
                        {0: "no", 1: "yes"}}}},
                     {"no surfacing": {0: "no", 1: {"flippers":
                        {0: {"head": {0: "no", 1: "yes"}}, 1: "no"}}}}
                    ]
    return list_of_trees[i]


# Count our tree's leaves represent by dict
def GetLeafNum(tree):
    leaf_num = 0
    next_dict = tree[list(tree.keys())[0]]  # Get next dict
    for key in next_dict.keys():
        if type(next_dict[key]).__name__ == "dict":
            leaf_num += GetLeafNum(next_dict[key])
        else:
            leaf_num += 1
    return leaf_num


# Get our tree's height represent by dict
def GetTreeHeight(tree):
    max_height = 0
    next_dict = tree[list(tree.keys())[0]]
    for key in next_dict.keys():
        if type(next_dict[key]).__name__ == "dict":
            height = 1 + GetTreeHeight(next_dict[key])
        else:
            height = 2      # Honestly speaking, here should be 2, because it counts node and its leaves
        if height > max_height:
            max_height = height
    return max_height


def PlotNode(node_text, center_pt, parent_pt, node_type):
    # The point and text is different from the plot in the figure
    # We need to determine its coordinate system
    CreatePlot.ax1.annotate(node_text,
                            xy=parent_pt, xycoords="axes fraction",
                            xytext=center_pt, textcoords="axes fraction",
                            bbox=node_type, arrowprops=arrow_args)
    # In Python, function is an object
    # And we can add attribute to any object at any time
    # In this case, we'll have use one variable which defined in another function
    # In order to access this variable, one possible way is bind the variable with its belonged function
    # Because we can access this function in global scope, we can surely access this variable

# Create text
def PlotMidText(center_pt, parent_pt, text_str):
    x_mid = (parent_pt[0] - center_pt[0]) / 2 + center_pt[0]
    y_mid = (parent_pt[1] - center_pt[1]) / 2 + center_pt[1]
    CreatePlot.ax1.text(x_mid, y_mid, text_str)

# Draw the tree recursively
def PlotTree(my_tree, parent_pt, node_text):
    leaves_num = GetLeafNum(my_tree)    # Current leaves number
    # Get current layer's position
    center_pt = ((PlotTree.x_off + (1 + leaves_num) / (2 * PlotTree.width)),
                PlotTree.y_off)
    # Connect current tree's root and its parent
    first_str = list(my_tree.keys())[0]
    PlotMidText(center_pt, parent_pt, node_text)
    PlotNode(first_str, center_pt, parent_pt, decision_node)
    PlotTree.y_off -= 1 / PlotTree.height
    # Draw leaves
    next_dict = my_tree[first_str]
    for key in next_dict.keys():
        if type(next_dict[key]).__name__ == "dict":
            PlotTree(next_dict[key], center_pt, str(key))
        else:
            PlotTree.x_off += 1 / PlotTree.width        # Update x position
            PlotNode(str(next_dict[key]), (PlotTree.x_off, PlotTree.y_off),
                     center_pt, leaf_node)
            PlotMidText((PlotTree.x_off, PlotTree.y_off),
                        center_pt, str(key))
    PlotTree.y_off += 1 / PlotTree.height

def CreatePlot(my_tree):
    fig = plt.figure(1)
    # Passing empty list to hide the xy axes
    axprobs = dict(xticks=[], yticks=[])
    CreatePlot.ax1 = plt.subplot(111, frameon=False, **axprobs)
    # Get my tree's entire information
    PlotTree.height = GetTreeHeight(my_tree)
    PlotTree.width = GetLeafNum(my_tree)
    PlotTree.x_off = -0.5 / PlotTree.width
    PlotTree.y_off = 1
    # Draw the Tree
    PlotTree(my_tree, (0.5, 1), "")
    plt.show()

if __name__ == "__main__":
    # my_tree = RetrieveTree(1)
    # my_tree["no surfacing"][3] = "maybe"
    # CreatePlot(my_tree)
    data_set, label = CreateDataSet()
    tree = CreateTree(data_set, label)
    CreatePlot(tree)
