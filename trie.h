/***********************************************************************
** Date: 		9/16/22
** Project :	trie.h
** Programers:	Jiahao Liang
** File:		trie.h
** Purpose:		The class trie.h, which implement the trie.h ADT
** Notes:		
***********************************************************************/

#pragma once
#ifndef _TRIE_H_
#define _TRIE_H_

#include <vector>
#include <string>

class Trie;

class TrieNode
{
public:
	friend class Trie;
	TrieNode()
	{
		isCompleteWord = false;
		dict.resize(26, nullptr);
	}
private:
	std::vector<TrieNode*> dict; // 二叉树只有左右两个孩子节点，而这个TrieNode有26个next孩子节点。
	bool isCompleteWord; // 多了一个bool变量isword，如果为true，表示该节点表示的字符串（准确地说，是从根节点一直next到此节点表示的字符串）在Trie树中存在，否则不存在。
};

class Trie
{
public:
	Trie();
	~Trie();
	void insert(const std::string&);
	bool search(const std::string&);
	bool startsWith(const std::string&);
	void clear();
private:
	TrieNode *root;
};

Trie::Trie():root(new TrieNode())
{
	
}

Trie::~Trie()
{
	delete root;
	root = nullptr;
}

void Trie::insert(const std::string& word)
{
	TrieNode *current = root;
	for(size_t i = 0; i < word.size(); ++i)
	{
		if(current->dict[word[i] - 'a'] == nullptr)
		{
			current->dict[word[i] - 'a'] = new TrieNode();
		}
		current = current->dict[word[i] - 'a'];
	}
	current->isCompleteWord = true;
}

bool Trie::search(const std::string& word)
{
	TrieNode *current = root;
	for(size_t i = 0; i < word.size(); ++i)
	{
		if(current->dict[word[i] - 'a'] == nullptr)
			return false;
		current = current->dict[word[i] - 'a'];
	}
	return current->isCompleteWord;
}

bool Trie::startsWith(const std::string &prefix)
{
	TrieNode *current = root;
	for(size_t i = 0; i < prefix.size(); ++i)
	{
		if(current->dict[prefix[i] - 'a'] == nullptr)
		{
			return false;
		}
		current = current->dict[prefix[i] - 'a'];
	}
	return true;
}

#endif