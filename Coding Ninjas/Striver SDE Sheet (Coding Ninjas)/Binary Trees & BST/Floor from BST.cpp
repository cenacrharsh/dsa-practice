// # Tutorial: https://www.youtube.com/watch?v=xm_W1ub-K-w&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=43

//* floor of n = greatest value <= n

/*
int Floor(BinaryTreeNode<int> *node, int input)
{
    int floor = 0;
    while (node != NULL)
    {
        if (node->data == input)
        {
            return node->data;
        }

        if (node->data > input)
        {
            node = node->left;
        }
        else
        {
            floor = node->data;
            node = node->right; //* as we want greatest value as our answer we try to find bigger values
        }
    }
    return floor;
}
*/