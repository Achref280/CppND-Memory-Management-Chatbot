#include "graphedge.h"
#include "graphnode.h"
#include "chatlogic.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
    std::cout << "GraphNode Constructor" << std::endl;

}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    std::cout << "GraphNode Destructor" << std::endl;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot &&chatbot)
{
    _chatBot = std::move(chatbot);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    newNode->_chatBot.GetChatLogicHandle()->SetChatbotHandle(&newNode->_chatBot);
    newNode->_chatBot.SetCurrentNode(newNode);
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}