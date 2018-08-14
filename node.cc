// Copyright 2018 <Author>
//http://10.241.14.34:11110/

#include "node.h"

Node::Node(char data) {
	this->pdata = data;
	this->prev = nullptr;
	this->next = nullptr;
  return;
}

char Node::GetData() {
	if (pdata)
		return pdata;
  return '\0';
}

Node* Node::GetPreviousNode() {
	if (prev)
		return prev;
  return nullptr;
}

Node* Node::GetNextNode() {
	if (next)
		return next;
  return nullptr;
}

Node* Node::InsertPreviousNode(char data) {
	Node* pInsertPreviousNode = new Node(data);
	Node* pGetPreviousNode = GetPreviousNode();

	if (pGetPreviousNode){
		if (pGetPreviousNode->next){
			pInsertPreviousNode->prev = prev;
			pGetPreviousNode->next = pInsertPreviousNode;
			pInsertPreviousNode->next = this;
			return pInsertPreviousNode;
		}
	} 
//제일 앞에 추가할 경우
	if (!pGetPreviousNode){
		pInsertPreviousNode->next = this;
		this->prev = pInsertPreviousNode;
		return pInsertPreviousNode;
	}
  return nullptr;
}

Node* Node::InsertNextNode(char data) {
	Node* pInsertNextNode = new Node(data);
	Node* pGetNextNode = GetNextNode();

	if (pGetNextNode){
		if (pGetNextNode->prev){
			pInsertNextNode->next = next;
			pGetNextNode->prev = pInsertNextNode;
			pInsertNextNode->prev = this;
			return pInsertNextNode;
		}
	}
	if (!pGetNextNode){
		pInsertNextNode->prev = this;
		this->next = pInsertNextNode;
		return pInsertNextNode;
	}
  return nullptr;
}

bool Node::ErasePreviousNode() {
	Node* pGetPreviousNode = GetPreviousNode();

	if (pGetPreviousNode){
		Node* tempPrevious = pGetPreviousNode->GetPreviousNode();
		if (tempPrevious) {
			tempPrevious->next = this;
			this->prev = tempPrevious;
			return true;
		}
		if (!tempPrevious){
			this->prev = nullptr;
			return true;
		}
	}
  return false;
}

bool Node::EraseNextNode() {
	Node* pGetNextNode = GetNextNode();

	if (pGetNextNode){
		Node* tempNext = pGetNextNode->GetNextNode();
		if (tempNext){
			this->next = tempNext;
			tempNext->prev = this;
			return true;
		}
		if (!tempNext){
			this->next = nullptr;
			return true;
		}
	}
  return false;
}
