#include "b_plus_tree.h"
#include "../structs.h"
#include <algorithm>

Node *BPTree::searchNode(float key)
{
    if (getRoot() == nullptr)
    {
        return nullptr;
    }

    Node *curNode = getRoot();
    int idx = 0;
    this->numOfNodesAcc++;

    while (!curNode->isLeaf)
    {
        //if current node is a non-leaf node
        idx = std::upper_bound(curNode->keys.begin(), curNode->keys.end(), key) - curNode->keys.begin();
        curNode = curNode->ptrs.at(idx+1);
        this->numOfNodesAcc++;
    }

    return curNode;
}

std::vector<Record *>* BPTree::searchRecord(float key)
{
    if (getRoot() == nullptr)
    {
        return nullptr;
    }

    Node *curNode = getRoot();
    int idx;
    this->numOfNodesAcc++;

    while (!curNode->isLeaf)
    {
        idx = std::upper_bound(curNode->keys.begin(), curNode->keys.end(), key) - curNode->keys.begin();
        curNode = curNode->ptrs.at(idx);
        this->numOfNodesAcc++;
    }

    idx = std::lower_bound(curNode->keys.begin(), curNode->keys.end(), key) - curNode->keys.begin();
    if (idx < curNode->keys.size() && curNode->keys.at(idx) == key)
    {
        return &(curNode->records.at(idx));
        /*std::vector<Record*>* result = new std::vector<Record*>;
        result->push_back(curNode->records.at(idx));
        return result;*/
    }

    return nullptr;
}
