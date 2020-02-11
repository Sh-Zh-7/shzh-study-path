import matplotlib.pyplot as plt

decision_node = dict(boxstyle="Round", fc="0.8")  # Decision block
leaf_node = dict(boxstyle="Round", fc="0.8")        # Terminate block
arrow_args = dict(arrowstyle="<-")                   # arrow style

# Generate tree in order to do testings
def RetrieveTree(i):
    list_of_trees = [{"no surfacing": {0: "no", 1: {"flippers":
                                                        {0: "no", 1: "yes"}}}},
                     {"no surfacing": {0: "no", 1: {"flippers":
                                                        {0: {"head": {0: "no", 1: "yes"}}, 1: "no"}}}}
                     ]
    return list_of_trees[i]

# Get height of the tree
def GetHeight(my_tree):
    max_height = 0
    # Get the subtree
    first_feat_str = list(my_tree.keys())[0]
    next_dict = my_tree[first_feat_str]
    # Calculate the height of tree recursively
    for key in next_dict.keys():
        if type(next_dict[key]).__name__ == "dict":
            height = 1 + GetHeight(next_dict[key])
        else:
            height = 1
        if height > max_height:
            max_height = height
    return max_height

# Get number of leaves of the tree
def GetWidth(my_tree):
    width = 0
    # Get the subtree
    first_feat_str = list(my_tree.keys())[0]
    next_dict = my_tree[first_feat_str]
    # Calculate the width of tree recursively
    for key in next_dict.keys():
        if type(next_dict[key]).__name__ == "dict":
            width += GetWidth(next_dict[key])
        else:
            width += 1
    return width

def PlotNode(node_text, center_pt, parent_pt, node_type):
    # The point and text is different from the plot in the figure
    # We need to determine its coordinate system
    CreatePlot.ax1.annotate(node_text,
                            xy=parent_pt, xycoords="axes fraction",
                            xytext=center_pt, textcoords="axes fraction",
                            bbox=node_type, arrowprops=arrow_args)

# Create text
def PlotMidText(center_pt, parent_pt, text_str):
    x_mid = (parent_pt[0] - center_pt[0]) / 2 + center_pt[0]
    y_mid = (parent_pt[1] - center_pt[1]) / 2 + center_pt[1]
    CreatePlot.ax1.text(x_mid, y_mid, text_str)

# plot tree in self-adaption mode
def PlotTree(my_tree, parent_pt, text):
    leaves_num = GetWidth(my_tree)
    # Calculate current position
    center_pt = (PlotTree.x_off + leaves_num / (2 * PlotTree.width),
                 PlotTree.y_off)
    # Draw node and text
    first_feat_str = list(my_tree.keys())[0]
    PlotMidText(center_pt, parent_pt, text)
    PlotNode(first_feat_str, center_pt, parent_pt, decision_node)
    # Draw subtree
    PlotTree.y_off -= 1 / PlotTree.height
    next_dict = my_tree[first_feat_str]
    for key in next_dict.keys():
        if type(next_dict[key]).__name__ == "dict":
            PlotTree(next_dict[key], center_pt, str(key))
        else:
            PlotTree.x_off += 1 / PlotTree.width
            PlotMidText((PlotTree.x_off, PlotTree.y_off), center_pt, str(key))
            PlotNode(next_dict[key], (PlotTree.x_off, PlotTree.y_off), center_pt, leaf_node)
    PlotTree.y_off += 1 / PlotTree.height    # Enter upper layer

def CreatePlot(my_tree):
    # Create fig and axes objects
    fig = plt.figure()
    xylabel = dict(xticks=[], yticks=[])
    CreatePlot.ax1 = plt.subplot(111, frameon=False, **xylabel)
    # Get the whole tree's attribute
    PlotTree.height = GetHeight(my_tree)
    PlotTree.width = GetWidth(my_tree)
    PlotTree.x_off = - 0.5 / PlotTree.width
    PlotTree.y_off = 1
    # Draw the tree
    PlotTree(my_tree, (0.5, 1), "")     # The first time the parent node is the root itself
    plt.show()

if __name__ == "__main__":
    tree = RetrieveTree(0)
    CreatePlot(tree)
