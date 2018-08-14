// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	this->head = NULL;
	this->cursor = NULL;
}

void TypingMachine::HomeKey() {
	cursor = head;
    return;
}

void TypingMachine::EndKey() {
	while (cursor->GetNextNode()) {
		cursor = cursor->GetNextNode();
	}
    return;
}

void TypingMachine::LeftKey() {
	Node* temp;
	temp = cursor->GetPreviousNode();
	if (temp)
		cursor = temp;
	return;
}

void TypingMachine::RightKey() {
	Node* temp;
	temp = cursor->GetNextNode();
	if (temp)
		cursor = temp;
	return;
}

bool TypingMachine::TypeKey(char key) {
	if (32 <= key && key <= 126){
		Node* node = new Node(key);
		node->pdata = key;
		node->next = NULL;

		if (head == NULL) {
			head = node;
			cursor = node;
		}
		else {
			node->prev = cursor;
			cursor->next = node;
			cursor = node;
		}
		return true;
	}
    return false;
}

bool TypingMachine::EraseKey() {
	cursor->ErasePreviousNode();
	return false;
}

std::string TypingMachine::Print(char separator) {
	Node* head = this->head;
//	while (head) {
	while (head && (head!=cursor)) {
		printf("%c", head->pdata);
		head = head->next;
	}
	if ((head) && separator!='0')
		printf("%c", separator);

	head = cursor;
//	head = head->next;
	while (head) {
		printf("%c", head->pdata);
		head = head->next;
	}

	return "";
}
