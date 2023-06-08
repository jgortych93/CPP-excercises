#include "RepeatingPlaylist.hpp"

#include <iostream>

RepeatingPlaylist::~RepeatingPlaylist()
{
	this->DeletePlaylist();
}

void RepeatingPlaylist::PushBack(Song& song)
{
	if (this->root == nullptr)
	{
		PushFront(song);
	}
	else
	{
		Node* newNode = new Node();
		newNode->val = &song;
		newNode->nextSong = nullptr;
		newNode->prevSong = this->back;

		this->back->nextSong = newNode;
		this->back = newNode;
	}
}

void RepeatingPlaylist::PushFront(Song& song)
{
	Node* newNode = new Node();
	newNode->val = &song;
	newNode->nextSong = this->root;
	newNode->prevSong = nullptr;

	if (this->root != nullptr)
	{
		this->root->prevSong = newNode;
	}

	this->root = newNode;

	if (this->back == nullptr)
	{
		this->back = this->root;
	}
}

void RepeatingPlaylist::DeletePlaylist()
{
	if (this->root == nullptr) return;

	Node* currentNode = this->root;

	while (currentNode != nullptr)
	{
		Node* tmp = currentNode->nextSong;
		delete currentNode;
		currentNode = tmp;
	}
}

void RepeatingPlaylist::PrintPlaylist()
{
	if (this->root == nullptr) return;

	Node* current = this->root;
	do {
		std::cout << current->val->GetName() << "\n";
		current = current->nextSong;
	} while (current != nullptr);

	std::cout << "\n\n";
}

void RepeatingPlaylist::PopFront()
{
	if (this->root == nullptr) return;

	Node* secondSong = this->root->nextSong;

	if (secondSong == nullptr)
	{
		delete this->root;
		return;
	}

	secondSong->prevSong = nullptr;
	delete this->root;
	this->root = secondSong;
}

void RepeatingPlaylist::PopBack()
{
	if (this->root == nullptr) return;

	Node* prevSong = this->back->prevSong;

	prevSong->nextSong = nullptr;
	delete this->back;
	this->back = prevSong;
}

Song& RepeatingPlaylist::GetFront() const
{
	return *(this->root->val);
}

Song& RepeatingPlaylist::GetBack() const
{
	return *(this->back->val);
}