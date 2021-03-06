//
// Created by 高昊 on 2019/11/27.
//

#ifndef GRAPH_REPRESENTATION_ADJ_LIST_H
#define GRAPH_REPRESENTATION_ADJ_LIST_H
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node* next;

    Node()
    {
        val=0;
        next=0;

    }
    Node(int _val)
    {
        val=_val;
        next=0;
    }
};

class AdjList
{
public:
    int nodeSize;
    int edgeSize;
    vector<Node*> ptrList;

public:
    AdjList(int _nodeSize)
    {
        nodeSize=_nodeSize;
        edgeSize=0;
        for(int i=0;i<nodeSize;i++)
        {
            Node* newptr=0;
            ptrList.push_back(newptr);
        }
    }

    void incertEdge(int val1, int val2)
    {
        Node* cur=ptrList[val1];
        Node* newNode=new Node(val2);
        if(cur==0)
        {
            //cout<<"here"<<endl;
            //cout<<"val1, val2 : "<<val1<<", "<<val2<<endl;
            ptrList[val1]=newNode;
        }
        else
        {
            while(cur->next!=0)
            {
                cur=cur->next;
            }
            cur->next=newNode;
        }
        edgeSize++;
    }

    void deleteEdge(int val1, int val2)
    {
        Node* cur=ptrList[val1];
        Node* last=cur;
        while(cur->next!=0&&cur->val!=val2)
        {
            last=cur;
            cur=cur->next;

        }
        if(cur->val==val2&&last!=cur)
        {
            last->next=cur->next;
            delete cur;
            edgeSize--;
        }
        else if(cur->val==val2&&last==cur)
        {
            ptrList[val1]=cur->next;
            delete cur;
            edgeSize--;
        }
        else if(cur->val!=val2)
        {

        }
        else{
            cout<<"error: not consider this case"<<endl;
            throw "error";
        }
    }
    bool isEmpty()
    {
        if(nodeSize==0)
            return true;
        else
            return false;
    }
    bool existEdge(int val1, int val2)
    {
        bool flag=false;
        Node*cur=ptrList[val1];
        if(cur==0)
            return false;
        while(cur->next!=0)
        {
            if(cur->val==val2)
                return true;
            cur=cur->next;
        }
        if(cur->val==val2)
            return true;
        else
            return false;
    }
    int retDegree(int val)
    {
        int res=0;
        Node*cur=ptrList[val];
        if(cur==0)
            return res;
        else
            res++;
        while(cur->next!=0)
        {
            res++;
            cur=cur->next;
        }
        return res;
    }

    void printList()
    {
        cout<<"printList:"<<endl;
        for(int i=0;i<ptrList.size();i++)
        {
            cout<<"list "<<i<<" :";
            Node* cur=ptrList[i];
            if(cur==0)
            {

            }
            else
            {
                cout<<cur->val<<", ";
                while(cur->next!=0)
                {
                    cur=cur->next;
                    cout<<cur->val<<", ";
                }
            }cout<<endl;
        }
    }
};
#endif //GRAPH_REPRESENTATION_ADJ_LIST_H
