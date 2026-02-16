#include "graphedge.h"
#include "graphnode.h"
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
    _chatBot = std::make_unique<ChatBot>(std::move(chatbot));
    // Note: SetCurrentNode is NOT called here to avoid triggering GUI updates
    // before ChatLogic has a reference to the ChatBot
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->_chatBot = std::move(_chatBot);
    newNode->_chatBot->SetCurrentNode(newNode);
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