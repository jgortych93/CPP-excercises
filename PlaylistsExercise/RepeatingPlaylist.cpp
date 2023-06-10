#include "RepeatingPlaylist.hpp"

#include <iostream>

RepeatingPlaylist::~RepeatingPlaylist()
{
	this->DeletePlaylist();
}

void RepeatingPlaylist::PushBack(const Song& song)
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

void RepeatingPlaylist::PushFront(const Song& song)
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
	return *(const_cast<Song*>(this->root->val));
}

Song& RepeatingPlaylist::GetBack() const
{
	return *(const_cast<Song*>(this->back->val));
}

bool RepeatingPlaylist::DeleteNodeAtPosition(uint32_t idx)
{
	if (this->root == nullptr) return false;

	Node* currentNode = this->root;

	for (int i = 0; currentNode != nullptr && i <= idx; ++i)
	{
		currentNode = currentNode->nextSong;
	}

	if (currentNode != nullptr)
	{
		DeleteNode(currentNode);
		return true;
	}
	else
	{
		return false;
	}
}

void RepeatingPlaylist::DeleteNode(Node* node)
{
	Node* prevSong = node->prevSong;
	Node* nextSong = node->nextSong;

	delete node;

	if (prevSong != nullptr)
	{
		prevSong->nextSong = nextSong;
	}
	else
	{
		this->root = nextSong;
		return;
	}

	if (nextSong != nullptr)
	{
		nextSong->prevSong = prevSong;
	}
	else
	{
		this->back = prevSong;
	}
}